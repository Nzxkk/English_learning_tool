#include "repeatword.h"
#include "ui_repeatword.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QFileDialog>
#include "memorizewords.h"
#include "ui_memorizewords.h"
#include "maintool.h"
#include "ui_maintool.h"
repeatword::repeatword(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::repeatword)
{
    ui->setupUi(this);
}
repeatword::repeatword(const QString &username, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::repeatword)
{
    ui->setupUi(this);
    currentUser=username;
    showcurrentuser();
    connectToDatabase();
    showErrorWords();
}
void repeatword::showcurrentuser(){
    qDebug()<<"User in repeatword:"<<currentUser;
}


bool repeatword::connectToDatabase() {
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setDatabaseName("mn_database"); // 设置数据库名称
    database.setHostName("47.117.162.236");
    database.setPort(3307);
    database.setUserName("root");
    database.setPassword("a_yMn4_4");

    if (!database.open()) {
        qDebug() << "Failed to connect to database:" << database.lastError().text();
        return false;
    }
    qDebug() << "Database connected successfully";
    return true;
}

void repeatword::showErrorWords() {
    // 假设你已经有一个成员变量存储了当前用户的 user_id
    // 在这个示例中，我将用户的 user_id 存储在了变量 userId 中
    // 先通过用户名查询 user_id
    int userId = -1;
    QSqlQuery userQuery;
    userQuery.prepare("SELECT user_id FROM users WHERE username = :username");
    userQuery.bindValue(":username", currentUser); // 假设用户名已存储在成员变量 username 中
    if (userQuery.exec() && userQuery.next()) {
        userId = userQuery.value(0).toInt();
    } else {
        qDebug() << "No user found with username:" << currentUser;
        return;
    }

    QSqlQuery query(database);
    query.prepare("SELECT Englishword, Chinesemeaning FROM failed_words WHERE user_id = :userId");
    query.bindValue(":userId", userId);

    if (query.exec()) {
        ui->textBrowser->clear();
        int rowCount = 0;
        while (query.next()) {
            QString englishWord = query.value("Englishword").toString();
            QString chineseMeaning = query.value("Chinesemeaning").toString();
            ui->textBrowser->append(englishWord + ": " + chineseMeaning);
            rowCount++;
        }
        qDebug() << "Query executed successfully, number of rows fetched:" << rowCount;
    } else {
        qDebug() << "Failed to fetch fail words:" << query.lastError().text();
    }
}

void repeatword::on_exportButton_clicked()
{
    // 弹出文件保存对话框，让用户选择保存文件的路径和名称
    QString filePath = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Text Files (*.txt)"));

    // 检查用户是否取消了对话框
    if (filePath.isEmpty()) {
        qDebug() << "User canceled the file dialog";
        return;
    }

    // 打开文件以进行写入
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for writing";
        return;
    }

    // 将错误单词写入文件
    QTextStream out(&file);
    QSqlQuery query("SELECT Englishword, Chinesemeaning FROM failed_words", database);
    if (query.exec()) {
        while (query.next()) {
            QString englishWord = query.value("Englishword").toString();
            QString chineseMeaning = query.value("Chinesemeaning").toString();
            out << englishWord << ": " << chineseMeaning << "\n";
        }
        qDebug() << "Error words exported to" << filePath;
    } else {
        qDebug() << "Failed to fetch fail words:" << query.lastError().text();
    }

    // 关闭文件
    file.close();
}

repeatword::~repeatword()
{
    delete ui;
}

void repeatword::on_pushButton_clicked()
{
    this->close();
    maintool *w = new maintool(currentUser);
    w->show();
}
