/********************************************************************************
** Form generated from reading UI file 'news.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWS_H
#define UI_NEWS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_news
{
public:
    QTextBrowser *yw;
    QTextBrowser *zw;
    QPushButton *xyp;
    QLabel *ts;
    QPushButton *syp;
    QLabel *title;
    QPushButton *pushButton;

    void setupUi(QWidget *news)
    {
        if (news->objectName().isEmpty())
            news->setObjectName(QString::fromUtf8("news"));
        news->resize(803, 559);
        yw = new QTextBrowser(news);
        yw->setObjectName(QString::fromUtf8("yw"));
        yw->setGeometry(QRect(40, 90, 271, 411));
        zw = new QTextBrowser(news);
        zw->setObjectName(QString::fromUtf8("zw"));
        zw->setGeometry(QRect(500, 90, 271, 411));
        xyp = new QPushButton(news);
        xyp->setObjectName(QString::fromUtf8("xyp"));
        xyp->setGeometry(QRect(350, 360, 111, 71));
        ts = new QLabel(news);
        ts->setObjectName(QString::fromUtf8("ts"));
        ts->setGeometry(QRect(320, 500, 171, 31));
        syp = new QPushButton(news);
        syp->setObjectName(QString::fromUtf8("syp"));
        syp->setGeometry(QRect(350, 150, 111, 71));
        title = new QLabel(news);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(90, 10, 601, 71));
        pushButton = new QPushButton(news);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(350, 440, 113, 32));

        retranslateUi(news);

        QMetaObject::connectSlotsByName(news);
    } // setupUi

    void retranslateUi(QWidget *news)
    {
        news->setWindowTitle(QCoreApplication::translate("news", "Form", nullptr));
        xyp->setText(QCoreApplication::translate("news", "\344\270\213\344\270\200\347\257\207", nullptr));
        ts->setText(QString());
        syp->setText(QCoreApplication::translate("news", "\344\270\212\344\270\200\347\257\207", nullptr));
        title->setText(QString());
        pushButton->setText(QCoreApplication::translate("news", "\345\233\236\345\210\260\344\270\273\351\241\265\351\235\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class news: public Ui_news {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWS_H
