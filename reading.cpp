#include "reading.h"
#include "ui_reading.h"
#include "maintool.h"
#include "ui_maintool.h"
reading::reading(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::reading)
{
    ui->setupUi(this);
    connectDatabase(); // 连接数据库
    // 在Widget类的构造函数中连接信号和槽
    currentArticleId = 1;
    currentQuestionId = 1;
    newArticleId =0;
    ui->tishi->clear();
    ui->syt->setEnabled(false);
    showTextOnAllWidgets();
    displayArticleContent();
    connect(ui->ButtonA, SIGNAL(clicked()), this, SLOT(checkAnswer()));
    connect(ui->ButtonB, SIGNAL(clicked()), this, SLOT(checkAnswer()));
    connect(ui->ButtonC, SIGNAL(clicked()), this, SLOT(checkAnswer()));
    connect(ui->ButtonD, SIGNAL(clicked()), this, SLOT(checkAnswer()));
    connect(ui->xyt, SIGNAL(clicked()), this, SLOT(on_xyt_clicked()));
    connect(ui->xuanze, QOverload<int>::of(&QComboBox::activated), this, &reading::on_xuanze_activated);
}
reading::reading(const QString &username, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::reading)
{
    ui->setupUi(this);
    currentUser=username;
    connectDatabase(); // 连接数据库
    // 在Widget类的构造函数中连接信号和槽
    currentArticleId = 1;
    currentQuestionId = 1;
    newArticleId =0;
    ui->tishi->clear();
    ui->syt->setEnabled(false);
    showTextOnAllWidgets();
    displayArticleContent();
    connect(ui->ButtonA, SIGNAL(clicked()), this, SLOT(checkAnswer()));
    connect(ui->ButtonB, SIGNAL(clicked()), this, SLOT(checkAnswer()));
    connect(ui->ButtonC, SIGNAL(clicked()), this, SLOT(checkAnswer()));
    connect(ui->ButtonD, SIGNAL(clicked()), this, SLOT(checkAnswer()));
    connect(ui->xyt, SIGNAL(clicked()), this, SLOT(on_xyt_clicked()));
}
void reading::connectDatabase() {
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("mn_database"); // ODBC 数据源名称
    db.setHostName("47.117.162.236");
    db.setPort(3307);
    db.setUserName("root");
    db.setPassword("a_yMn4_4");
    // 尝试连接数据库
    if (!db.open()) {
        qDebug() << "Error: Failed to connect to database." << db.lastError();
        // 处理连接失败的情况
    } else {
        qDebug() << "Connected to reading";
    }
}
void reading::updateText()
{
    displayArticleContent(); // 显示文章内容
    displayQuestion(); // 显示问题及选项内容
}

void reading::showTextOnAllWidgets()
{
    // 显示所有控件
    ui->label->show();
    ui->text1->show();
    ui->text2->show();
    ui->text3->show();
    ui->text4->show();
    ui->Text->show();
    ui->dn->show();
    // 更新界面内容
    updateText();
}


void reading::displayArticleContent() {
    // 查询与 currentArticleId 对应的文章内容和题目总数
    QSqlQuery query(db);
    query.prepare(R"(
        SELECT
            (SELECT article_content FROM articles WHERE article_id = :currentArticleId),
            (SELECT COUNT(*) FROM questions WHERE article_id = :currentArticleId)
    )");
    query.bindValue(":currentArticleId", currentArticleId);

    if (query.exec()) {
        if (query.next()) {
            // 获取文章内容
            QString articleContent = query.value(0).toString();
            ui->Text->setText(articleContent.isEmpty() ? "ooNo content available for current article." : articleContent);
            // 获取题目总数
            totalQuestionCount = query.value(1).toInt();
        } else {
            // 处理没有结果的情况
            ui->Text->setText("No content available for current article.");
            totalQuestionCount = 0;
        }
    } else {
        // 处理查询失败的情况
        qWarning() << "Failed to execute query:" << query.lastError().text();
        ui->Text->setText("Error loading article content.");
        totalQuestionCount = 0;
    }
}



void reading::displayQuestion() {
    QSqlQuery query(db);
    query.prepare("SELECT question_text, option_a, option_b, option_c, option_d, correct_answer FROM questions WHERE article_id = :currentArticleId");
    query.bindValue(":currentArticleId", currentArticleId); // 绑定当前文章ID
    if (query.exec()) { // 执行查询
        if (query.next()) {
            QString questionText = query.value(0).toString(); // 去除首尾空格
            QString optionA = query.value(1).toString();
            QString optionB = query.value(2).toString();
            QString optionC = query.value(3).toString();
            QString optionD = query.value(4).toString();
            // 显示问题文本内容和选项内容在标签中
            ui->label->setText(questionText);
            ui->text1->setText(optionA);
            ui->text2->setText(optionB);
            ui->text3->setText(optionC);
            ui->text4->setText(optionD);

            // 存储正确答案
            correctAnswer = query.value(5).toString();
        }
    } else {
        // 查询失败，处理失败情况
        qDebug() << "Error in displaying question:" << query.lastError().text();
    }
}
void reading::checkAnswer() {
    QPushButton *button = qobject_cast<QPushButton*>(sender()); // 获取发送信号的按钮

    if (button) {
        QString userAnswer;
        QString hint;

        if (button == ui->ButtonA) {
            userAnswer = "A";
            hint = (userAnswer == correctAnswer) ? "正确\n答案：" + correctAnswer : "错误\n答案：" + correctAnswer;
        } else if (button == ui->ButtonB) {
            userAnswer = "B";
            hint = (userAnswer == correctAnswer) ? "正确\n答案："+ correctAnswer : "错误\n答案：" + correctAnswer;
        } else if (button == ui->ButtonC) {
            userAnswer = "C";
            hint = (userAnswer == correctAnswer) ? "正确\n答案：" + correctAnswer: "错误\n答案：" + correctAnswer;
        } else if (button == ui->ButtonD) {
            userAnswer = "D";
            hint = (userAnswer == correctAnswer) ? "正确\n答案：" + correctAnswer: "错误\n答案：" + correctAnswer;
        }

        // 记录作答状态和提示文本内容
        questionStatus[currentQuestionId] = qMakePair(userAnswer, hint);

        // 在提示栏显示文本内容
        ui->dn->setText(hint);

        // 禁用当前题目的选项按钮
        ui->ButtonA->setEnabled(false);
        ui->ButtonB->setEnabled(false);
        ui->ButtonC->setEnabled(false);
        ui->ButtonD->setEnabled(false);
    }
}
void reading::on_xyt_clicked() {
    qDebug() << "xyt button clicked.";
    // 断开之前的连接
    disconnect(ui->xyt, SIGNAL(clicked()), this, SLOT(on_xyt_clicked()));
    // 执行你的逻辑
    ui->syt->setEnabled(true);
    ui->tishi->clear();
    currentQuestionId++;
    fetchNextQuestion();
    // 重新连接信号与槽函数
    connect(ui->xyt, SIGNAL(clicked()), this, SLOT(on_xyt_clicked()));
}

void reading::fetchNextQuestion() {
    QSqlQuery query;
    query.prepare("SELECT question_text, option_a, option_b, option_c, option_d, question_id, correct_answer , article_id FROM questions WHERE question_id = :currentQuestionId");
    query.bindValue(":currentQuestionId", currentQuestionId);
    ui->dn->clear();
    ui->timu->clear();

    if (query.exec()) {
        qDebug() << "Query executed successfully.";

        if (query.next()) {
            qDebug() << "Processing next record...";
            QString questionText = query.value(0).toString().trimmed();
            QString optionA = query.value(1).toString();
            QString optionB = query.value(2).toString();
            QString optionC = query.value(3).toString();
            QString optionD = query.value(4).toString();
            currentQuestionId = query.value(5).toInt();
            qDebug() << currentQuestionId;
            correctAnswer = query.value(6).toString();
            newArticleId = query.value(7).toInt();

            if (newArticleId != currentArticleId) {
                currentArticleId = newArticleId;
                displayArticleContent();
            }

            ui->label->setText(questionText);
            ui->text1->setText(optionA);
            ui->text2->setText(optionB);
            ui->text3->setText(optionC);
            ui->text4->setText(optionD);

            // 恢复作答状态和提示文本内容
            ui->ButtonA->setEnabled(true);
            ui->ButtonB->setEnabled(true);
            ui->ButtonC->setEnabled(true);
            ui->ButtonD->setEnabled(true);

            if (questionStatus.contains(currentQuestionId)) {
                QPair<QString, QString> status = questionStatus.value(currentQuestionId);
                if (!status.first.isEmpty()) { // 如果已经作答过
                    ui->ButtonA->setEnabled(false);
                    ui->ButtonB->setEnabled(false);
                    ui->ButtonC->setEnabled(false);
                    ui->ButtonD->setEnabled(false);
                }
                if (!status.second.isEmpty()) { // 如果有提示文本内容
                    ui->dn->setText(status.second);
                }
            }

            // 检查是否已经到达第一篇题目的最后一题
            QSqlQuery countQuery;
            countQuery.prepare("SELECT COUNT(*) FROM questions WHERE article_id = :currentArticleId");
            countQuery.bindValue(":currentArticleId", currentArticleId);
            if (countQuery.exec() && countQuery.next()) {
                if (currentQuestionId == 3*currentArticleId) {
                    ui->xyt->setEnabled(false); // 禁用 "下一题" 按钮
                    ui->tishi->setText("已经是此篇的最后一题了");
                } else {
                    ui->xyt->setEnabled(true); // 启用 "下一题" 按钮
                }
            }
        }
        else {
            qDebug() << "No more records found.";
            ui->timu->setText("已经是最后一题了");
            currentQuestionId--;
            // 进行适当的处理，例如提示用户或重置状态
        }
    }
    else {
        qDebug() << "Query execution failed.";
    }
}

void reading::fetchPreviousQuestion() {
    QSqlQuery query;
    query.prepare("SELECT question_text, option_a, option_b, option_c, option_d, question_id, correct_answer, article_id FROM questions WHERE question_id = :currentQuestionId");
    query.bindValue(":currentQuestionId", currentQuestionId);
    ui->dn->clear();

    if (query.exec()) {
        qDebug() << "Query executed successfully.";

        if (query.next()) {
            qDebug() << "Processing previous record...";
            QString questionText = query.value(0).toString().trimmed();
            QString optionA = query.value(1).toString();
            QString optionB = query.value(2).toString();
            QString optionC = query.value(3).toString();
            QString optionD = query.value(4).toString();
            currentQuestionId = query.value(5).toInt();
            qDebug() << currentQuestionId;
            correctAnswer = query.value(6).toString();
            newArticleId = query.value(7).toInt();
            if (newArticleId != currentArticleId) {
                currentArticleId = newArticleId;
                displayArticleContent();
            }
            ui->label->setText(questionText);
            ui->text1->setText(optionA);
            ui->text2->setText(optionB);
            ui->text3->setText(optionC);
            ui->text4->setText(optionD);

            // 恢复作答状态和提示文本内容
            ui->ButtonA->setEnabled(true);
            ui->ButtonB->setEnabled(true);
            ui->ButtonC->setEnabled(true);
            ui->ButtonD->setEnabled(true);
            if (questionStatus.contains(currentQuestionId)) {
                QPair<QString, QString> status = questionStatus.value(currentQuestionId);
                if (!status.first.isEmpty()) { // 如果已经作答过
                    ui->ButtonA->setEnabled(false);
                    ui->ButtonB->setEnabled(false);
                    ui->ButtonC->setEnabled(false);
                    ui->ButtonD->setEnabled(false);
                }
                if (!status.second.isEmpty()) { // 如果有提示文本内容
                    ui->dn->setText(status.second);
                }
            }
            QSqlQuery countQuery;
            countQuery.prepare("SELECT COUNT(*) FROM questions WHERE article_id = :currentArticleId");
            countQuery.bindValue(":currentArticleId", currentArticleId);
            if (countQuery.exec() && countQuery.next()) {
                if (currentQuestionId == 3*currentArticleId-2) {
                    ui->syt->setEnabled(false); // 禁用 "上一题" 按钮
                } else {
                    ui->syt->setEnabled(true); // 启用 "上一题" 按钮
                }
            }
        }
        else {
            qDebug() << "No more records found.";
            // 进行适当的处理，例如提示用户或重置状态
        }
    }
    else {
        qDebug() << "Query execution failed.";
    }
}

void reading::on_syt_clicked() {
    qDebug() << "syt button clicked.";
    ui->xyt->setEnabled(true);
    ui->tishi->clear();
    // 检查是否已经到达第一道题目
    if (currentQuestionId > 1) {
        currentQuestionId--; // 返回上一题
        ui -> timu->clear();
        fetchPreviousQuestion(); // 调用获取上一题的函数
    } else {
        qDebug() << "已经是第一道题目了，无法返回上一题";
        ui -> timu ->setText("已经是第一道题目了，无法返回上一题");
        // 进行适当的处理，例如提示用户或重置状态
    }
}

void reading::on_xuanze_activated(int index) {
    // 获取下拉框当前选中的文本
    QString selectedArticle = ui->xuanze->itemText(index);

    // 根据选中的文章设置对应的文章ID
    int articleId = 0;
    if (selectedArticle == "A篇") {
        articleId = 1;
    } else if (selectedArticle == "B篇") {
        articleId = 2;
    } else if (selectedArticle == "C篇") {
        articleId = 3;
    } else if (selectedArticle == "D篇") {
        articleId = 4;
    }
    ui->xyt->setEnabled(true);
    ui->syt->setEnabled(false);
    ui->tishi->clear();
    // 恢复作答状态和提示文本内容
    ui->ButtonA->setEnabled(true);
    ui->ButtonB->setEnabled(true);
    ui->ButtonC->setEnabled(true);
    ui->ButtonD->setEnabled(true);
    ui->dn->clear();
    // 跳转到选中文章的第一道题目
    jumpToFirstQuestionOfArticle(articleId);
    currentArticleId=articleId;
    displayArticleContent();
}

void reading::jumpToFirstQuestionOfArticle(int articleId) {
    // 查询选中文章的第一道题目
    QSqlQuery query;
    query.prepare("SELECT question_id FROM questions WHERE article_id = :articleId ORDER BY question_id ASC LIMIT 1");
    query.bindValue(":articleId", articleId);
    if (query.exec() && query.next()) {
        int firstQuestionId = query.value(0).toInt();
        // 更新当前题目ID并显示题目内容
        currentQuestionId = firstQuestionId;
        displayQuestion();
    } else {
        qDebug() << "Failed to jump to the first question of article" << articleId;
    }
}



reading::~reading()
{
    delete ui;
}

void reading::on_pushButton_clicked()
{
    this->close();
    maintool *w =new maintool(currentUser);
    w->show();

}
