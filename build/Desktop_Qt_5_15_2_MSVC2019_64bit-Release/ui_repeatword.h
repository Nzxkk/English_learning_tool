/********************************************************************************
** Form generated from reading UI file 'repeatword.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPEATWORD_H
#define UI_REPEATWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_repeatword
{
public:
    QTextBrowser *textBrowser;
    QPushButton *exportButton;
    QPushButton *pushButton;

    void setupUi(QWidget *repeatword)
    {
        if (repeatword->objectName().isEmpty())
            repeatword->setObjectName(QString::fromUtf8("repeatword"));
        repeatword->resize(400, 300);
        textBrowser = new QTextBrowser(repeatword);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(70, 20, 256, 192));
        exportButton = new QPushButton(repeatword);
        exportButton->setObjectName(QString::fromUtf8("exportButton"));
        exportButton->setGeometry(QRect(40, 230, 113, 32));
        pushButton = new QPushButton(repeatword);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(240, 230, 113, 32));

        retranslateUi(repeatword);

        QMetaObject::connectSlotsByName(repeatword);
    } // setupUi

    void retranslateUi(QWidget *repeatword)
    {
        repeatword->setWindowTitle(QCoreApplication::translate("repeatword", "Form", nullptr));
        exportButton->setText(QCoreApplication::translate("repeatword", "\345\257\274\345\207\272", nullptr));
        pushButton->setText(QCoreApplication::translate("repeatword", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class repeatword: public Ui_repeatword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPEATWORD_H
