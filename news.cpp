#include "news.h"
#include "ui_news.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "maintool.h"

news::~news()
{
    delete ui;
}

news::news(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::news)
{
    ui->setupUi(this);
    connectDatabase(); // 连接数据库

    currentArticleId = 1;
    newArticleId =0;
    time = 0;
    display();

}

news::news(const QString &username,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::news)
{
    ui->setupUi(this);
    connectDatabase(); // 连接数据库
    currentUser=username;
    currentArticleId = 1;
    newArticleId =0;
    time = 0;
    display();
}
void news::connectDatabase() {
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



void news::display() {
    QSqlQuery query(db);
    query.prepare("SELECT id, content, ch, title FROM xinwen WHERE id = :currentArticleId");
    query.bindValue(":currentArticleId", currentArticleId); // 绑定当前文章ID
    if (query.exec()) { // 执行查询
        if (query.next()) {
            QString id = query.value(0).toString(); // 获取ID
            QString content = query.value(1).toString(); // 获取中英内容
            QString ch = query.value(2).toString(); // 获取单词内容
            QString title = query.value(3).toString(); // 获取标题
            // 显示内容在标签中
            ui->yw->setText(content);
            ui->zw->setText(ch);
            ui->title->setText(title);
        }
    } else {
        // 查询失败，处理失败情况
        qDebug() << "Error in displaying question:" << query.lastError().text();
    }
    QSqlQuery nextQuery(db);
    nextQuery.prepare("SELECT id FROM xinwen WHERE id > :currentArticleId LIMIT 1");
    nextQuery.bindValue(":currentArticleId", currentArticleId);
    if (nextQuery.exec() && nextQuery.next()) {
        // 下一条记录存在，启用按钮
        ui->xyp->setEnabled(true);
    } else {
        // 下一条记录不存在，禁用按钮
        ui->xyp->setEnabled(false);
        ui->ts->setText("已经是最后一篇了");
    }
    QSqlQuery prevQuery(db);
    prevQuery.prepare("SELECT id FROM xinwen WHERE id < :currentArticleId ORDER BY id DESC LIMIT 1");
    prevQuery.bindValue(":currentArticleId", currentArticleId);
    if (prevQuery.exec() && prevQuery.next()) {
        // 上一条记录存在，启用按钮
        ui->syp->setEnabled(true);
    } else if( time != 0) {
        // 上一条记录不存在，禁用按钮
        ui->syp->setEnabled(false);
        ui->ts->setText("已经是第一篇了");
    }
    else{
        time = 1;
        ui->syp->setEnabled(false);
    }
}


void news::on_xyp_clicked() {
    ui->ts->clear();
    currentArticleId += 1;
    display();
}

void news::on_syp_clicked() {
    ui->ts->clear();
    currentArticleId -= 1;
    display();
}
void news::on_pushButton_clicked()
{
    this->close();
    maintool *w =new maintool(currentUser);
    w->show();
}
