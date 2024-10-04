#ifndef TRAN_H
#define TRAN_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>

class tran : public QWidget
{
    Q_OBJECT

public:
    explicit tran(QWidget *parent = nullptr);
    explicit tran(const QString &username,QWidget *parent=nullptr);
    ~tran();
    QString currentUser;

private slots:
    void onSendButtonClicked();
    void onReplyFinished(QNetworkReply* reply);
    void onExitButtonClicked();  // 声明退出按钮的槽函数

private:
    void initNetworkManager();
    QByteArray QStringToQByteArray(const QString& str);
    QString QByteArrayToQString(const QByteArray& ba);

    // 网络访问管理器
    QNetworkAccessManager *httpsManager;
    // 访问URL
    QString postUrl;
    // 访问令牌
    QString token;
    // 用户名
    QString userName;

    // UI元素
    QLineEdit *inputLineEdit;
    QPushButton *sendButton;
    QPushButton *exitButton;  // 退出按钮
    QTextEdit *responseTextEdit;
};

#endif // WIDGET_H
