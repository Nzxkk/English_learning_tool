#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QDebug>
#include "maintool.h"
#include "ui_maintool.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    InitStyle();
    ui->passwordLineEdit->setEchoMode(QLineEdit::Password);
    connectMainDatabase();
}
bool Widget::connectMainDatabase() {
    mainDatabase = QSqlDatabase::addDatabase("QMYSQL");
    mainDatabase.setDatabaseName("mn_database");
    mainDatabase.setHostName("47.117.162.236");
    mainDatabase.setPort(3307);
    mainDatabase.setUserName("root");
    mainDatabase.setPassword("a_yMn4_4");
    if (!mainDatabase.open()) {
        QMessageBox::critical(this, tr("Error"), tr("Failed to connect to main database: %1").arg(mainDatabase.lastError().text()));
        return false;
    }
    QString currentUserName = mainDatabase.userName();
      qDebug() << "Connected as user:" << currentUserName;
    return true;
}


void Widget::on_loginButton_clicked() {
    QString username = ui->usernameLineEdit->text().trimmed();
    QString password = ui->passwordLineEdit->text().trimmed();
    // 先连接到主数据库
    QString databaseName = "mn_database";
    if (!connectMainDatabase()) {
        QMessageBox::critical(this, tr("Login"), tr("Failed to connect to main database"));
        return;
    }
    // 查询用户表验证用户名和密码
    QSqlQuery query;
    query.prepare("SELECT username FROM users WHERE username = :username AND password = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    if (query.exec() && query.next()) {
        QMessageBox::information(this, tr("Login"), tr("Login successful"));
        currentUser = username;
        qDebug()<<"current username:"<<currentUser;
        maintool *w = new maintool(currentUser);
        w->show();
        this->close();
    } else {
        QMessageBox::critical(this, tr("Login"), tr("Invalid username or password"));
    }
}
Widget::~Widget()
{
    delete ui;
}


void Widget::on_registerButton_clicked() {
    QString username = ui->usernameLineEdit->text().trimmed();
    QString password = ui->passwordLineEdit->text().trimmed();
    QString databaseName = "mn_database";
    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password) VALUES (:username, :password)");
    query.bindValue(":username", username);
    query.bindValue(":password", password);


    if (!query.exec()) {
        qDebug() << "Failed to insert user into users table:" << query.lastError().text();
        QMessageBox::critical(this, tr("Register"), tr("Registration failed"));
        return;
    }

    QMessageBox::information(this, tr("Register"), tr("Registration successful"));
}

void Widget::on_pushButton_clicked()
{
    this->close();
}
void Widget::InitStyle()
{
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint);
}
