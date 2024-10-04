/********************************************************************************
** Form generated from reading UI file 'reading.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_READING_H
#define UI_READING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_reading
{
public:
    QTextBrowser *Text;
    QComboBox *xuanze;
    QLabel *label_2;
    QLabel *label;
    QPushButton *syt;
    QPushButton *xyt;
    QLabel *dn;
    QTextBrowser *text1;
    QPushButton *ButtonC;
    QTextBrowser *text2;
    QLabel *timu;
    QPushButton *ButtonD;
    QPushButton *ButtonB;
    QTextBrowser *text4;
    QTextBrowser *text3;
    QPushButton *ButtonA;
    QLabel *tishi;
    QPushButton *pushButton;

    void setupUi(QWidget *reading)
    {
        if (reading->objectName().isEmpty())
            reading->setObjectName(QString::fromUtf8("reading"));
        reading->resize(955, 583);
        Text = new QTextBrowser(reading);
        Text->setObjectName(QString::fromUtf8("Text"));
        Text->setGeometry(QRect(20, 10, 571, 461));
        xuanze = new QComboBox(reading);
        xuanze->addItem(QString());
        xuanze->addItem(QString());
        xuanze->addItem(QString());
        xuanze->addItem(QString());
        xuanze->setObjectName(QString::fromUtf8("xuanze"));
        xuanze->setGeometry(QRect(250, 500, 81, 41));
        label_2 = new QLabel(reading);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(200, 500, 51, 31));
        label = new QLabel(reading);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(600, 90, 351, 61));
        syt = new QPushButton(reading);
        syt->setObjectName(QString::fromUtf8("syt"));
        syt->setEnabled(true);
        syt->setGeometry(QRect(620, 10, 91, 71));
        xyt = new QPushButton(reading);
        xyt->setObjectName(QString::fromUtf8("xyt"));
        xyt->setEnabled(true);
        xyt->setGeometry(QRect(850, 10, 91, 71));
        dn = new QLabel(reading);
        dn->setObjectName(QString::fromUtf8("dn"));
        dn->setGeometry(QRect(350, 480, 111, 61));
        text1 = new QTextBrowser(reading);
        text1->setObjectName(QString::fromUtf8("text1"));
        text1->setGeometry(QRect(680, 160, 231, 61));
        ButtonC = new QPushButton(reading);
        ButtonC->setObjectName(QString::fromUtf8("ButtonC"));
        ButtonC->setGeometry(QRect(620, 330, 51, 31));
        text2 = new QTextBrowser(reading);
        text2->setObjectName(QString::fromUtf8("text2"));
        text2->setGeometry(QRect(680, 240, 231, 61));
        timu = new QLabel(reading);
        timu->setObjectName(QString::fromUtf8("timu"));
        timu->setGeometry(QRect(510, 490, 411, 61));
        ButtonD = new QPushButton(reading);
        ButtonD->setObjectName(QString::fromUtf8("ButtonD"));
        ButtonD->setGeometry(QRect(620, 410, 51, 31));
        ButtonB = new QPushButton(reading);
        ButtonB->setObjectName(QString::fromUtf8("ButtonB"));
        ButtonB->setGeometry(QRect(620, 250, 51, 31));
        text4 = new QTextBrowser(reading);
        text4->setObjectName(QString::fromUtf8("text4"));
        text4->setGeometry(QRect(680, 400, 231, 61));
        text3 = new QTextBrowser(reading);
        text3->setObjectName(QString::fromUtf8("text3"));
        text3->setGeometry(QRect(680, 320, 231, 61));
        ButtonA = new QPushButton(reading);
        ButtonA->setObjectName(QString::fromUtf8("ButtonA"));
        ButtonA->setGeometry(QRect(620, 180, 51, 31));
        tishi = new QLabel(reading);
        tishi->setObjectName(QString::fromUtf8("tishi"));
        tishi->setGeometry(QRect(710, 10, 141, 61));
        pushButton = new QPushButton(reading);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 500, 113, 32));

        retranslateUi(reading);

        QMetaObject::connectSlotsByName(reading);
    } // setupUi

    void retranslateUi(QWidget *reading)
    {
        reading->setWindowTitle(QCoreApplication::translate("reading", "Form", nullptr));
        xuanze->setItemText(0, QCoreApplication::translate("reading", "A\347\257\207", nullptr));
        xuanze->setItemText(1, QCoreApplication::translate("reading", "B\347\257\207", nullptr));
        xuanze->setItemText(2, QCoreApplication::translate("reading", "C\347\257\207", nullptr));
        xuanze->setItemText(3, QCoreApplication::translate("reading", "D\347\257\207", nullptr));

        xuanze->setCurrentText(QCoreApplication::translate("reading", "A\347\257\207", nullptr));
        label_2->setText(QCoreApplication::translate("reading", "\345\275\223\345\211\215\346\230\257", nullptr));
        label->setText(QString());
        syt->setText(QCoreApplication::translate("reading", "\344\270\212\344\270\200\351\242\230", nullptr));
        xyt->setText(QCoreApplication::translate("reading", "\344\270\213\344\270\200\351\242\230", nullptr));
        dn->setText(QString());
        ButtonC->setText(QCoreApplication::translate("reading", "C", nullptr));
        timu->setText(QString());
        ButtonD->setText(QCoreApplication::translate("reading", "D", nullptr));
        ButtonB->setText(QCoreApplication::translate("reading", "B", nullptr));
        ButtonA->setText(QCoreApplication::translate("reading", "A", nullptr));
        tishi->setText(QString());
        pushButton->setText(QCoreApplication::translate("reading", "\351\200\200\345\207\272\347\273\203\344\271\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class reading: public Ui_reading {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_READING_H
