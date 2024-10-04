#include "memorizewords.h"
#include "ui_memorizewords.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "maintool.h"
#include "ui_maintool.h"

memorizewords::memorizewords(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::memorizewords)
{
    ui->setupUi(this);

}
memorizewords::memorizewords(const QString &username, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::memorizewords)
{
    ui->setupUi(this);
    currentUser=username;
    showcurrentuser();
    connectDatabase();
    loadProgress(); // 加载背诵进度
    loadWord();
}
void memorizewords::showcurrentuser(){
    qDebug()<<"User in memorizewords:"<<currentUser;
}
void memorizewords::connectDatabase() {
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setDatabaseName("mn_database");
    database.setHostName("47.117.162.236");
    database.setPort(3307);
    database.setUserName("root");
    database.setPassword("a_yMn4_4");
    if (!database.open()) {
        qDebug() << "Failed to connect to database: " << database.lastError().text();
    } else {
        qDebug() << "Successfully connect to "<<currentUser<<"_database";
    }
}
void memorizewords::loadWord() {
    QString queryString = "SELECT id, Englishword, Chinesemeaning FROM word WHERE id > " + QString::number(lastLoadedId) + " LIMIT 1";
    QSqlQuery query(queryString, database);
    if (query.exec()) {
        if (query.next()) {
            int id = query.value(0).toInt();
            QString englishWord = query.value(1).toString();
            QString chineseTranslation = query.value(2).toString();
            ui->textBrowser->setPlainText(chineseTranslation); // 使用 setPlainText 设置纯文本
            currentWordTranslation = englishWord;
            lastLoadedId = id;
        } else {
            qDebug() << "No more words found";
        }
    } else {
        qDebug() << "Query failed:" << query.lastError().text();
    }
}
void memorizewords::loadProgress() {
    QSqlQuery query;
    query.prepare("SELECT user_id FROM users WHERE username = :username");
    query.bindValue(":username", currentUser);
    if (query.exec() && query.next()) {
        int userId = query.value(0).toInt();

        QSqlQuery progressQuery;
        progressQuery.prepare("SELECT last_loaded_id FROM progress WHERE user_id = :user_id");
        progressQuery.bindValue(":user_id", userId);
        if (progressQuery.exec() && progressQuery.next()) {
            lastLoadedId = progressQuery.value(0).toInt();
            qDebug() << "Loaded progress for username:" << currentUser << ", lastLoadedId:" << lastLoadedId;
        } else {
            lastLoadedId = 0;
            qDebug() << "No progress found for username:" << currentUser;
        }
    } else {
        qDebug() << "No user found with username:" << currentUser;
    }
}
void memorizewords::checkWord() {
    QString userWord = ui->lineEdit->text();
    QString currentWordTranslationTrimmed = currentWordTranslation.trimmed();
    int userId = -1;

    // 先通过用户名查询 user_id
    QSqlQuery userQuery;
    userQuery.prepare("SELECT user_id FROM users WHERE username = :username");
    userQuery.bindValue(":username", currentUser); // 假设用户名已存储在成员变量 username 中
    if (userQuery.exec() && userQuery.next()) {
        userId = userQuery.value(0).toInt();
    } else {
        qDebug() << "No user found with username:" << currentUser;
        return;
    }

    if (userWord.trimmed().compare(currentWordTranslationTrimmed, Qt::CaseInsensitive) != 0) {
        // 查询是否已经存在该单词的记录
        QSqlQuery query;
        query.prepare("SELECT error_count FROM failed_words WHERE user_id = :userId AND Englishword = :englishWord");
        query.bindValue(":userId", userId);
        query.bindValue(":englishWord", currentWordTranslationTrimmed);

        if (query.exec() && query.next()) {
            // 如果存在记录，则更新错误次数
            int errorCount = query.value(0).toInt();
            errorCount++;
            QSqlQuery updateQuery;
            updateQuery.prepare("UPDATE failed_words SET error_count = :errorCount WHERE user_id = :userId AND Englishword = :englishWord");
            updateQuery.bindValue(":errorCount", errorCount);
            updateQuery.bindValue(":userId", userId);
            updateQuery.bindValue(":englishWord", currentWordTranslationTrimmed);

            if (!updateQuery.exec()) {
                qDebug() << "Failed to update error count for word:" << currentWordTranslationTrimmed << updateQuery.lastError().text();
            }
        } else {
            // 如果不存在记录，则插入新记录
            QSqlQuery insertQuery;
            insertQuery.prepare("INSERT INTO failed_words (user_id, Englishword, Chinesemeaning, error_count) VALUES (:userId, :englishWord, :chineseTranslation, 1)");
            insertQuery.bindValue(":userId", userId);
            insertQuery.bindValue(":englishWord", currentWordTranslationTrimmed);
            insertQuery.bindValue(":chineseTranslation", ui->textBrowser->toPlainText());

            if (!insertQuery.exec()) {
                qDebug() << "Failed to insert failed word into database:" << insertQuery.lastError().text();
            }
        }
    }

    // 检查单词是否正确，并根据结果更新标签
    if (userWord.compare(currentWordTranslationTrimmed, Qt::CaseInsensitive) == 0) {
        ui->label->setText("正确！");
    } else {
        ui->label->setText("错误！");
    }
}
void memorizewords::saveProgress() {
    // 假设你有一个成员变量存储当前用户名
    // 在这个示例中，我将用户名存储在了变量 username 中

    QSqlQuery getUserIdQuery;
    getUserIdQuery.prepare("SELECT user_id FROM users WHERE username = :username");
    getUserIdQuery.bindValue(":username", currentUser);
    if (getUserIdQuery.exec() && getUserIdQuery.next()) {
        int userId = getUserIdQuery.value(0).toInt();

        QSqlQuery query;
        query.prepare("INSERT INTO progress (user_id, last_loaded_id) VALUES (:userId, :lastLoadedId) "
                      "ON DUPLICATE KEY UPDATE last_loaded_id = :lastLoadedId");
        query.bindValue(":userId", userId);
        query.bindValue(":lastLoadedId", lastLoadedId);

        if (!query.exec()) {
            qDebug() << "Failed to save progress:" << query.lastError().text();
        }
    } else {
        qDebug() << "Failed to get user_id for username:" << currentUser;
    }
}


void memorizewords::on_pushButton_clicked()
{
    checkWord();
    ui->pushButton_next->setEnabled(true); // 激活下一个按钮
    saveProgress(); // 保存背诵进度
}

void memorizewords::on_pushButton_next_clicked()
{
    loadWord();
    ui->lineEdit->clear(); // 清空文本框内容
    ui->pushButton_next->setEnabled(false); // 禁用下一个按钮
    saveProgress(); // 保存背诵进度
    ui->pushButton_next->setEnabled(false);
}

void memorizewords::on_pushButton_2_clicked() {
    maintool *maintool_page = new maintool(currentUser);
    this->hide();
    maintool_page->show();
}
memorizewords::~memorizewords()
{
    delete ui;
}
