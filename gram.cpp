#include "gram.h"
#include "ui_gram.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <maintool.h>
#include <ui_gram.h>
gram::gram(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::gram)
{
    ui->setupUi(this);

    connectDatabase();
    currentArticleId=1;
    displayArticleContent();

}

gram::gram(const QString &username,QWidget *parent): QWidget(parent)
    , ui(new Ui::gram)
{
    ui->setupUi(this);

    currentUser=username;
    connectDatabase();
    currentArticleId=1;
    displayArticleContent();
}
gram::~gram()
{
    delete ui;
}

void gram::connectDatabase() {
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
        qDebug() << "Connected to database.";
    }
}

void gram::displayArticleContent() {
    ui->t1->setText("T1");
    ui->t2->setText("T2");
    ui->t3->setText("T3");
    ui->t4->setText("T4");
    ui->t5->setText("T5");
    ui->t6->setText("T6");
    ui->t7->setText("T7");
    ui->t8->setText("T8");
    ui->t9->setText("T9");
    ui->t10->setText("T10");
    // 查询与 currentArticleId 对应的文章内容
    QSqlQuery query(db);
    query.prepare("SELECT content FROM yftk WHERE id = :currentArticleId");
    query.bindValue(":currentArticleId", currentArticleId);
    if (query.exec() && query.next()) {
        QString articleContent = query.value(0).toString();
        ui->content->setText(articleContent); // 将文章内容显示在文本框中
    } else {
        // 处理查询失败或没有结果的情况
        ui->content->setText("No content available for current article.");
    }
}


void gram::on_jd_clicked() {
    // 获取TextEdit控件中的文本内容
    QString text1 = ui->textEdit->toPlainText();
    QString text2 = ui->textEdit_2->toPlainText();
    QString text3 = ui->textEdit_3->toPlainText();
    QString text4 = ui->textEdit_4->toPlainText();
    QString text5 = ui->textEdit_5->toPlainText();
    QString text6 = ui->textEdit_6->toPlainText();
    QString text7 = ui->textEdit_7->toPlainText();
    QString text8 = ui->textEdit_8->toPlainText();
    QString text9 = ui->textEdit_9->toPlainText();
    QString text10 = ui->textEdit_10->toPlainText();
    // 查询数据库并比较内容
    QSqlQuery query1(db);
    query1.prepare("SELECT T1 ,T2 ,T3 ,T4 ,T5 ,T6 ,T7 ,T8 ,T9 ,T10 FROM yftk WHERE id = :currentArticleId");
    query1.bindValue(":currentArticleId", currentArticleId);
    if (query1.exec() && query1.next()) {
        QString dbText1 = query1.value(0).toString();
        QString dbText2 = query1.value(1).toString();
        QString dbText3 = query1.value(2).toString();
        QString dbText4 = query1.value(3).toString();
        QString dbText5 = query1.value(4).toString();
        QString dbText6 = query1.value(5).toString();
        QString dbText7 = query1.value(6).toString();
        QString dbText8 = query1.value(7).toString();
        QString dbText9 = query1.value(8).toString();
        QString dbText10 = query1.value(9).toString();
        if (text1.isEmpty() || text2.isEmpty() || text3.isEmpty() || text4.isEmpty()|| text5.isEmpty()|| text6.isEmpty()|| text7.isEmpty()|| text8.isEmpty()|| text9.isEmpty()|| text10.isEmpty()/* 检查其他textEdit 是否为空*/) {
            if (text1.isEmpty()) {
                ui->label1->setText("此题未作答");
            }
            else{
                if (text1 == dbText1) {
                    ui->label1->setText("正确");
                } else {
                    ui->label1->setText("错误");
                }
            }

            if (text2.isEmpty()) {
                ui->label2->setText("此题未作答");
            }
            else {
                if (text2 == dbText2) {
                ui->label2->setText("正确");
                }
                else {
                    ui->label2->setText("错误");
                }
            }

            if (text3.isEmpty()) {
                ui->label3->setText("此题未作答");
            }
            else {
                if (text3 == dbText3) {
                ui->label3->setText("正确");
            } else {
                ui->label3->setText("错误");
            }
            }

            if (text4.isEmpty()) {
                ui->label4->setText("此题未作答");
            }
            else{
                if (text4 == dbText4) {
                ui->label4->setText("正确");
            } else {
                ui->label4->setText("错误");
            }
            }

            if (text5.isEmpty()) {
                ui->label5->setText("此题未作答");
            }
            else{
                if (text5 == dbText5) {
                ui->label5->setText("正确");
            } else {
                ui->label5->setText("错误");
            }
            }

            if (text6.isEmpty()) {
                ui->label6->setText("此题未作答");
            }
            else{
                if (text6 == dbText6) {
                    ui->label6->setText("正确");
                } else {
                    ui->label6->setText("错误");
                }
            }

            if (text7.isEmpty()) {
                ui->label7->setText("此题未作答");
            }
            else{
                if (text7 == dbText7) {
                    ui->label7->setText("正确");
                } else {
                    ui->label7->setText("错误");
                }
            }

            if (text8.isEmpty()) {
                ui->label8->setText("此题未作答");
            }
            else{
                if (text8 == dbText8) {
                    ui->label8->setText("正确");
                } else {
                    ui->label8->setText("错误");
                }
            }

            if (text9.isEmpty()) {
                ui->label9->setText("此题未作答");
            }
            else{
                if (text9 == dbText9) {
                    ui->label9->setText("正确");
                } else {
                    ui->label9->setText("错误");
                }
            }

            if (text10.isEmpty()) {
                ui->label10->setText("此题未作答");
            }
            else{
                if (text10 == dbText10) {
                    ui->label10->setText("正确");
                } else {
                    ui->label10->setText("错误");
                }
            }
            // 对其他label 控件设置相应的文本
            // 如果还有其他textEdit 和 label 控件需要处理，可以继续添加相应的逻辑
            return; // 结束函数执行，避免执行查询逻辑
        }
        else{
            ui->textEdit->setReadOnly(true);
            ui->textEdit_2->setReadOnly(true);
            ui->textEdit_3->setReadOnly(true);
            ui->textEdit_4->setReadOnly(true);
            ui->textEdit_5->setReadOnly(true);
            ui->textEdit_6->setReadOnly(true);
            ui->textEdit_7->setReadOnly(true);
            ui->textEdit_8->setReadOnly(true);
            ui->textEdit_9->setReadOnly(true);
            ui->textEdit_10->setReadOnly(true);
                if (text1 == dbText1) {
                    ui->label1->setText("正确");
                } else {
                    ui->label1->setText("错误");
                }


                if (text2 == dbText2) {
                    ui->label2->setText("正确");
                }
                else {
                    ui->label2->setText("错误");
                }



                if (text3 == dbText3) {
                    ui->label3->setText("正确");
                } else {
                    ui->label3->setText("错误");
                }



                if (text4 == dbText4) {
                    ui->label4->setText("正确");
                } else {
                    ui->label4->setText("错误");
                }




                if (text5 == dbText5) {
                    ui->label5->setText("正确");
                } else {
                    ui->label5->setText("错误");
                }



                if (text6 == dbText6) {
                    ui->label6->setText("正确");
                } else {
                    ui->label6->setText("错误");
                }



                if (text7 == dbText7) {
                    ui->label7->setText("正确");
                } else {
                    ui->label7->setText("错误");
                }



                if (text8 == dbText8) {
                    ui->label8->setText("正确");
                } else {
                    ui->label8->setText("错误");
                }

                if (text9 == dbText9) {
                    ui->label9->setText("正确");
                } else {
                    ui->label9->setText("错误");
                }


                if (text10 == dbText10) {
                    ui->label10->setText("正确");
                } else {
                    ui->label10->setText("错误");
                }
                saveUserAnswer();
}
}
}



void gram::on_ckda_clicked() {

    // 查询数据库并获取对应字段的内容
    QSqlQuery query(db);
    query.prepare("SELECT T1, T2, T3, T4, T5, T6, T7, T8, T9, T10 FROM yftk WHERE id = :currentArticleId");
    query.bindValue(":currentArticleId", currentArticleId);

    if (query.exec() && query.next()) {
        QString text1 = ui->textEdit->toPlainText();
        QString text2 = ui->textEdit_2->toPlainText();
        QString text3 = ui->textEdit_3->toPlainText();
        QString text4 = ui->textEdit_4->toPlainText();
        QString text5 = ui->textEdit_5->toPlainText();
        QString text6 = ui->textEdit_6->toPlainText();
        QString text7 = ui->textEdit_7->toPlainText();
        QString text8 = ui->textEdit_8->toPlainText();
        QString text9 = ui->textEdit_9->toPlainText();
        QString text10 = ui->textEdit_10->toPlainText();
        // 查询数据库并比较内容
        QSqlQuery query1(db);
        query1.prepare("SELECT T1 ,T2 ,T3 ,T4 ,T5 ,T6 ,T7 ,T8 ,T9 ,T10 FROM yftk WHERE id = :currentArticleId");
        query1.bindValue(":currentArticleId", currentArticleId);
        if (query1.exec() && query1.next()) {
        QString dbText1 = query.value(0).toString();
        QString dbText2 = query.value(1).toString();
        QString dbText3 = query.value(2).toString();
        QString dbText4 = query.value(3).toString();
        QString dbText5 = query.value(4).toString();
        QString dbText6 = query.value(5).toString();
        QString dbText7 = query.value(6).toString();
        QString dbText8 = query.value(7).toString();
        QString dbText9 = query.value(8).toString();
        QString dbText10 = query.value(9).toString();

        // 将获取的内容设置到对应的textEdit控件上
        if (text1.isEmpty() || text2.isEmpty() || text3.isEmpty() || text4.isEmpty()|| text5.isEmpty()|| text6.isEmpty()|| text7.isEmpty()|| text8.isEmpty()|| text9.isEmpty()|| text10.isEmpty()/* 检查其他textEdit 是否为空*/) {
            if (text1.isEmpty()) {
                ui->label1->setText("此题未作答");
            }
            else{
                if (text1 == dbText1) {
                    ui->label1->setText("正确");
                } else {
                    ui->label1->setText("错误");
                }
            }

            if (text2.isEmpty()) {
                ui->label2->setText("此题未作答");
            }
            else {
                if (text2 == dbText2) {
                    ui->label2->setText("正确");
                }
                else {
                    ui->label2->setText("错误");
                }
            }

            if (text3.isEmpty()) {
                ui->label3->setText("此题未作答");
            }
            else {
                if (text3 == dbText3) {
                    ui->label3->setText("正确");
                } else {
                    ui->label3->setText("错误");
                }
            }

            if (text4.isEmpty()) {
                ui->label4->setText("此题未作答");
            }
            else{
                if (text4 == dbText4) {
                    ui->label4->setText("正确");
                } else {
                    ui->label4->setText("错误");
                }
            }

            if (text5.isEmpty()) {
                ui->label5->setText("此题未作答");
            }
            else{
                if (text5 == dbText5) {
                    ui->label5->setText("正确");
                } else {
                    ui->label5->setText("错误");
                }
            }

            if (text6.isEmpty()) {
                ui->label6->setText("此题未作答");
            }
            else{
                if (text6 == dbText6) {
                    ui->label6->setText("正确");
                } else {
                    ui->label6->setText("错误");
                }
            }

            if (text7.isEmpty()) {
                ui->label7->setText("此题未作答");
            }
            else{
                if (text7 == dbText7) {
                    ui->label7->setText("正确");
                } else {
                    ui->label7->setText("错误");
                }
            }

            if (text8.isEmpty()) {
                ui->label8->setText("此题未作答");
            }
            else{
                if (text8 == dbText8) {
                    ui->label8->setText("正确");
                } else {
                    ui->label8->setText("错误");
                }
            }

            if (text9.isEmpty()) {
                ui->label9->setText("此题未作答");
            }
            else{
                if (text9 == dbText9) {
                    ui->label9->setText("正确");
                } else {
                    ui->label9->setText("错误");
                }
            }

            if (text10.isEmpty()) {
                ui->label10->setText("此题未作答");
            }
            else{
                if (text10 == dbText10) {
                    ui->label10->setText("正确");
                } else {
                    ui->label10->setText("错误");
                }
            }
            // 对其他label 控件设置相应的文本
            // 如果还有其他textEdit 和 label 控件需要处理，可以继续添加相应的逻辑
            return; // 结束函数执行，避免执行查询逻辑
        }
        else{
        ui->jd->setEnabled(false);
        ui->textEdit->setText(dbText1);
        ui->textEdit_2->setText(dbText2);
        ui->textEdit_3->setText(dbText3);
        ui->textEdit_4->setText(dbText4);
        ui->textEdit_5->setText(dbText5);
        ui->textEdit_6->setText(dbText6);
        ui->textEdit_7->setText(dbText7);
        ui->textEdit_8->setText(dbText8);
        ui->textEdit_9->setText(dbText9);
        ui->textEdit_10->setText(dbText10);
        ui->textEdit->setReadOnly(true);
        ui->textEdit_2->setReadOnly(true);
        ui->textEdit_3->setReadOnly(true);
        ui->textEdit_4->setReadOnly(true);
        ui->textEdit_5->setReadOnly(true);
        ui->textEdit_6->setReadOnly(true);
        ui->textEdit_7->setReadOnly(true);
        ui->textEdit_8->setReadOnly(true);
        ui->textEdit_9->setReadOnly(true);
        ui->textEdit_10->setReadOnly(true);
        }
    } else {
        qDebug() << "Failed to retrieve data from database.";
    }
}
}


void gram::displayNextArticleContent() {
    if (userAnswers.contains(currentArticleId)) {
        ui->textEdit->setReadOnly(true);
        ui->textEdit_2->setReadOnly(true);
        ui->textEdit_3->setReadOnly(true);
        ui->textEdit_4->setReadOnly(true);
        ui->textEdit_5->setReadOnly(true);
        ui->textEdit_6->setReadOnly(true);
        ui->textEdit_7->setReadOnly(true);
        ui->textEdit_8->setReadOnly(true);
        ui->textEdit_9->setReadOnly(true);
        ui->textEdit_10->setReadOnly(true);
        UserAnswer answer = userAnswers[currentArticleId];
        ui->textEdit->setText(answer.text1);
        ui->textEdit_2->setText(answer.text2);
        ui->textEdit_3->setText(answer.text3);
        ui->textEdit_4->setText(answer.text4);
        ui->textEdit_5->setText(answer.text5);
        ui->textEdit_6->setText(answer.text6);
        ui->textEdit_7->setText(answer.text7);
        ui->textEdit_8->setText(answer.text8);
        ui->textEdit_9->setText(answer.text9);
        ui->textEdit_10->setText(answer.text10);
        ui->label1->setText(answer.labelStatus1);
        ui->label2->setText(answer.labelStatus2);
        ui->label3->setText(answer.labelStatus3);
        ui->label4->setText(answer.labelStatus4);
        ui->label5->setText(answer.labelStatus5);
        ui->label6->setText(answer.labelStatus6);
        ui->label7->setText(answer.labelStatus7);
        ui->label8->setText(answer.labelStatus8);
        ui->label9->setText(answer.labelStatus9);
        ui->label10->setText(answer.labelStatus10);
        ui->jd->setEnabled(false);
// 假设只恢复 label1 的状态，其他的类似
    } else {
        ui->jd->setEnabled(true);
        ui->textEdit->setReadOnly(false);
        ui->textEdit_2->setReadOnly(false);
        ui->textEdit_3->setReadOnly(false);
        ui->textEdit_4->setReadOnly(false);
        ui->textEdit_5->setReadOnly(false);
        ui->textEdit_6->setReadOnly(false);
        ui->textEdit_7->setReadOnly(false);
        ui->textEdit_8->setReadOnly(false);
        ui->textEdit_9->setReadOnly(false);
        ui->textEdit_10->setReadOnly(false);
        // 如果没有保存的答案，则清空 textEdit 和 label
        // 清空其他的 textEdit 和 label 的内容
        ui->textEdit->clear();
        ui->textEdit_2->clear();
        ui->textEdit_3->clear();
        ui->textEdit_4->clear();
        ui->textEdit_5->clear();
        ui->textEdit_6->clear();
        ui->textEdit_7->clear();
        ui->textEdit_8->clear();
        ui->textEdit_9->clear();
        ui->textEdit_10->clear();
        ui->label1->clear();
        ui->label2->clear();
        ui->label3->clear();
        ui->label4->clear();
        ui->label5->clear();
        ui->label6->clear();
        ui->label7->clear();
        ui->label8->clear();
        ui->label9->clear();
        ui->label10->clear();
         // 假设只清空 label1 的状态，其他的类似
    }
    // 显示下一个文章的内容
    displayArticleContent();
}


void gram::saveUserAnswer() {
    UserAnswer answer;
    answer.text1 = ui->textEdit->toPlainText();
    answer.text2 = ui->textEdit_2->toPlainText();
    answer.text3 = ui->textEdit_3->toPlainText();
    answer.text4 = ui->textEdit_4->toPlainText();
    answer.text5 = ui->textEdit_5->toPlainText();
    answer.text6 = ui->textEdit_6->toPlainText();
    answer.text7 = ui->textEdit_7->toPlainText();
    answer.text8 = ui->textEdit_8->toPlainText();
    answer.text9 = ui->textEdit_9->toPlainText();
    answer.text10 = ui->textEdit_10->toPlainText();
    answer.labelStatus1 = ui->label1->text(); // 假设只保存 label1 的状态，其他的类似
    answer.labelStatus2 = ui->label2->text();
    answer.labelStatus3 = ui->label3->text();
    answer.labelStatus4 = ui->label4->text();
    answer.labelStatus5 = ui->label5->text();
    answer.labelStatus6 = ui->label6->text();
    answer.labelStatus7 = ui->label7->text();
    answer.labelStatus8 = ui->label8->text();
    answer.labelStatus9 = ui->label9->text();
    answer.labelStatus10 = ui->label10->text();
    userAnswers[currentArticleId] = answer;
}


void gram::on_xyp_clicked()
{
    // 增加 currentArticleId，如果超过最大文章ID，则重新从第一个文章开始
    currentArticleId++;
    displayNextArticleContent();
}


void gram::on_syp_clicked()
{
    currentArticleId--;
    displayNextArticleContent();
}

void gram::on_exit_clicked()
{
    this->close();
    maintool *w=new maintool(currentUser);
    w->show();
}
