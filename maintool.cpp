#include "maintool.h"
#include "ui_maintool.h"
#include <QDebug>
#include "memorizewords.h"
#include "ui_memorizewords.h"
#include "repeatword.h"
#include "ui_repeatword.h"
#include "reading.h"
#include "ui_reading.h"
#include "widget.h"
#include "ui_widget.h"
#include "tran.h"
#include "ui_tran.h"
#include "news.h"
#include "ui_news.h"
#include "gram.h"
#include "ui_gram.h"
maintool::maintool(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::maintool)
{

    ui->setupUi(this);
this->setWindowFlags(Qt::FramelessWindowHint );
    showcurrentuser();

}


maintool::maintool(const QString &username, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::maintool)
{
    ui->setupUi(this);
this->setWindowFlags(Qt::FramelessWindowHint );
    currentUser=username;
    showcurrentuser();
}
void maintool::showcurrentuser(){
    qDebug()<<"user in maintool:"<<currentUser;
}


maintool::~maintool()
{
    delete ui;
}

void maintool::on_pushButton_clicked()
{
    this->close();
    memorizewords *w=new memorizewords(currentUser);
    w->show();
}

void maintool::on_reviewFailWordsButton_clicked()
{
    this->close();
    repeatword * w=new repeatword(currentUser);
    w->show();
}

void maintool::on_readingcompreButton_clicked()
{
    this->close();
    reading *w=new reading(currentUser);
    w->show();
}

void maintool::on_translationButton_clicked()
{
this->close();
    tran* w=new tran(currentUser);
    w->show();
}

void maintool::on_pushButton_2_clicked()
{
    this->close();
    Widget *w=new Widget();
    w->show();
}


void maintool::on_pushButton_news_clicked()
{
    this->close();
    news *w=new news(currentUser);
    w->show();
}

void maintool::on_pushButton_gram_clicked()
{
    this->close();
    gram *w=new gram(currentUser);
    w->show();
}
