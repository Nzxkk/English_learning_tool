/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label_2;
    QPushButton *loginButton;
    QLabel *label;
    QLineEdit *usernameLineEdit;
    QPushButton *registerButton;
    QLineEdit *passwordLineEdit;
    QCheckBox *checkBox;
    QPushButton *pushButton;
    QLabel *label_3;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(738, 363);
        Widget->setStyleSheet(QString::fromUtf8(""));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(210, 240, 60, 16));
        loginButton = new QPushButton(Widget);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setGeometry(QRect(200, 280, 113, 32));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 200, 60, 16));
        usernameLineEdit = new QLineEdit(Widget);
        usernameLineEdit->setObjectName(QString::fromUtf8("usernameLineEdit"));
        usernameLineEdit->setGeometry(QRect(310, 200, 113, 21));
        registerButton = new QPushButton(Widget);
        registerButton->setObjectName(QString::fromUtf8("registerButton"));
        registerButton->setGeometry(QRect(310, 280, 113, 32));
        passwordLineEdit = new QLineEdit(Widget);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));
        passwordLineEdit->setGeometry(QRect(310, 240, 113, 21));
        checkBox = new QCheckBox(Widget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(450, 240, 86, 20));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(420, 280, 113, 32));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(270, 70, 251, 71));
        QFont font;
        font.setPointSize(18);
        label_3->setFont(font);
        label_3->setMouseTracking(false);
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_3->setMargin(6);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\345\257\206\347\240\201", nullptr));
        loginButton->setText(QCoreApplication::translate("Widget", "\347\231\273\351\231\206", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215", nullptr));
        usernameLineEdit->setText(QString());
        registerButton->setText(QCoreApplication::translate("Widget", "\346\263\250\345\206\214", nullptr));
        checkBox->setText(QCoreApplication::translate("Widget", "\346\230\276\347\244\272", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\351\200\200\345\207\272", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "word master\350\213\261\350\257\255\345\255\246\344\271\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
