/********************************************************************************
** Form generated from reading UI file 'memorizewords.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEMORIZEWORDS_H
#define UI_MEMORIZEWORDS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_memorizewords
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QLineEdit *lineEdit;
    QPushButton *pushButton_next;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *pushButton_2;

    void setupUi(QWidget *memorizewords)
    {
        if (memorizewords->objectName().isEmpty())
            memorizewords->setObjectName(QString::fromUtf8("memorizewords"));
        memorizewords->resize(443, 401);
        verticalLayoutWidget = new QWidget(memorizewords);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(90, 20, 231, 331));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textBrowser = new QTextBrowser(verticalLayoutWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        pushButton_next = new QPushButton(verticalLayoutWidget);
        pushButton_next->setObjectName(QString::fromUtf8("pushButton_next"));

        verticalLayout->addWidget(pushButton_next);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);


        retranslateUi(memorizewords);

        QMetaObject::connectSlotsByName(memorizewords);
    } // setupUi

    void retranslateUi(QWidget *memorizewords)
    {
        memorizewords->setWindowTitle(QCoreApplication::translate("memorizewords", "Form", nullptr));
        pushButton_next->setText(QCoreApplication::translate("memorizewords", "\344\270\213\344\270\200\344\270\252", nullptr));
        pushButton->setText(QCoreApplication::translate("memorizewords", "\345\210\244\346\226\255", nullptr));
        label->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("memorizewords", "\344\277\235\345\255\230\345\271\266\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class memorizewords: public Ui_memorizewords {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEMORIZEWORDS_H
