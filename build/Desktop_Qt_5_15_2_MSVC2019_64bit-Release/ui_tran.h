/********************************************************************************
** Form generated from reading UI file 'tran.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAN_H
#define UI_TRAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tran
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QTextEdit *xianshi;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QTextEdit *textEdit;
    QPushButton *TO;
    QTextEdit *textEdit_2;
    QPushButton *pushButtonfy;

    void setupUi(QWidget *tran)
    {
        if (tran->objectName().isEmpty())
            tran->setObjectName(QString::fromUtf8("tran"));
        tran->resize(400, 300);
        pushButton = new QPushButton(tran);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 100, 51, 23));
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(0 0, 0);\n"
"color: rgb(0, 0, 0);"));
        label = new QLabel(tran);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 30, 71, 16));
        label->setStyleSheet(QString::fromUtf8("color: rgb(0 0, 0);\n"
"color: rgb(0, 0, 0);"));
        xianshi = new QTextEdit(tran);
        xianshi->setObjectName(QString::fromUtf8("xianshi"));
        xianshi->setGeometry(QRect(50, 180, 301, 81));
        xianshi->setStyleSheet(QString::fromUtf8("color: rgb(0 0, 0);\n"
"color: rgb(0, 0, 0);"));
        lineEdit = new QLineEdit(tran);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(260, 100, 31, 21));
        lineEdit->setStyleSheet(QString::fromUtf8("color: rgb(0 0, 0);\n"
"color: rgb(0, 0, 0);"));
        lineEdit_2 = new QLineEdit(tran);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(320, 100, 31, 21));
        lineEdit_2->setStyleSheet(QString::fromUtf8("color: rgb(0 0, 0);\n"
"color: rgb(0, 0, 0);"));
        textEdit = new QTextEdit(tran);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(50, 50, 301, 41));
        textEdit->setStyleSheet(QString::fromUtf8("color: rgb(0 0, 0);\n"
"color: rgb(0, 0, 0);"));
        TO = new QPushButton(tran);
        TO->setObjectName(QString::fromUtf8("TO"));
        TO->setGeometry(QRect(290, 100, 31, 21));
        TO->setStyleSheet(QString::fromUtf8("color: rgb(0 0, 0);\n"
"color: rgb(0, 0, 0);"));
        textEdit_2 = new QTextEdit(tran);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(50, 130, 301, 51));
        pushButtonfy = new QPushButton(tran);
        pushButtonfy->setObjectName(QString::fromUtf8("pushButtonfy"));
        pushButtonfy->setGeometry(QRect(100, 100, 161, 23));
        pushButtonfy->setStyleSheet(QString::fromUtf8("color: rgb(0 0, 0);\n"
"color: rgb(0, 0, 0);"));

        retranslateUi(tran);

        QMetaObject::connectSlotsByName(tran);
    } // setupUi

    void retranslateUi(QWidget *tran)
    {
        tran->setWindowTitle(QCoreApplication::translate("tran", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("tran", "\345\217\221\351\237\263", nullptr));
        label->setText(QCoreApplication::translate("tran", "\350\257\267\350\276\223\345\205\245\350\213\261\346\226\207:", nullptr));
        lineEdit->setText(QCoreApplication::translate("tran", "\350\213\261\346\226\207", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("tran", "\344\270\255\346\226\207", nullptr));
        TO->setText(QCoreApplication::translate("tran", "<=>", nullptr));
        textEdit_2->setStyleSheet(QCoreApplication::translate("tran", "color: rgb(0 0, 0);\n"
"color: rgb(0, 0, 0);", nullptr));
        pushButtonfy->setText(QCoreApplication::translate("tran", "\347\277\273\350\257\221", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tran: public Ui_tran {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAN_H
