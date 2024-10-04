/********************************************************************************
** Form generated from reading UI file 'maintool.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINTOOL_H
#define UI_MAINTOOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_maintool
{
public:
    QPushButton *reviewFailWordsButton;
    QPushButton *pushButton;
    QPushButton *translationButton;
    QPushButton *readingcompreButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_news;
    QPushButton *pushButton_gram;

    void setupUi(QWidget *maintool)
    {
        if (maintool->objectName().isEmpty())
            maintool->setObjectName(QString::fromUtf8("maintool"));
        maintool->resize(587, 373);
        reviewFailWordsButton = new QPushButton(maintool);
        reviewFailWordsButton->setObjectName(QString::fromUtf8("reviewFailWordsButton"));
        reviewFailWordsButton->setGeometry(QRect(290, 10, 120, 120));
        reviewFailWordsButton->setStyleSheet(QString::fromUtf8("border-image: url(:/image/PNG99.png);\n"
"\n"
"border: none;"));
        pushButton = new QPushButton(maintool);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 10, 120, 120));
        pushButton->setStyleSheet(QString::fromUtf8("image: url(:/image/PNG101.png);\n"
"border: none;"));
        translationButton = new QPushButton(maintool);
        translationButton->setObjectName(QString::fromUtf8("translationButton"));
        translationButton->setGeometry(QRect(420, 10, 120, 120));
        translationButton->setStyleSheet(QString::fromUtf8("image: url(:/image/PNG100.png);\n"
"border: none;"));
        readingcompreButton = new QPushButton(maintool);
        readingcompreButton->setObjectName(QString::fromUtf8("readingcompreButton"));
        readingcompreButton->setGeometry(QRect(160, 10, 120, 120));
        readingcompreButton->setStyleSheet(QString::fromUtf8("image: url(:/image/PNG110.png);\n"
"border: none;"));
        pushButton_2 = new QPushButton(maintool);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(290, 150, 120, 120));
        pushButton_2->setStyleSheet(QString::fromUtf8("image: url(:/image/PNG112.png);\n"
"border: none;"));
        pushButton_news = new QPushButton(maintool);
        pushButton_news->setObjectName(QString::fromUtf8("pushButton_news"));
        pushButton_news->setGeometry(QRect(30, 150, 120, 120));
        pushButton_news->setStyleSheet(QString::fromUtf8("image: url(:/image/PNG108.png);border: none;"));
        pushButton_gram = new QPushButton(maintool);
        pushButton_gram->setObjectName(QString::fromUtf8("pushButton_gram"));
        pushButton_gram->setGeometry(QRect(160, 150, 120, 120));
        pushButton_gram->setStyleSheet(QString::fromUtf8("image: url(:/image/PNG103.png);\n"
"border: none;"));

        retranslateUi(maintool);

        QMetaObject::connectSlotsByName(maintool);
    } // setupUi

    void retranslateUi(QWidget *maintool)
    {
        maintool->setWindowTitle(QCoreApplication::translate("maintool", "Form", nullptr));
        reviewFailWordsButton->setText(QCoreApplication::translate("maintool", "\345\233\236\351\241\276\345\215\225\350\257\215", nullptr));
        pushButton->setText(QCoreApplication::translate("maintool", "\350\203\214\350\257\265\345\215\225\350\257\215", nullptr));
        translationButton->setText(QCoreApplication::translate("maintool", "\344\272\272\345\267\245\346\231\272\350\203\275", nullptr));
        readingcompreButton->setText(QCoreApplication::translate("maintool", "\351\230\205\350\257\273\347\220\206\350\247\243", nullptr));
        pushButton_2->setText(QCoreApplication::translate("maintool", "\351\200\200\345\207\272\345\255\246\344\271\240", nullptr));
        pushButton_news->setText(QCoreApplication::translate("maintool", "\351\230\205\350\257\273\350\265\204\346\226\231", nullptr));
        pushButton_gram->setText(QCoreApplication::translate("maintool", "\350\257\255\346\263\225\345\241\253\347\251\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class maintool: public Ui_maintool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINTOOL_H
