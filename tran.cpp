#include "widget.h"
#include "tran.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QDebug>
#include <QLabel>
#include <QScrollBar>
#include "maintool.h"
tran::tran(QWidget *parent)
    : QWidget(parent),
      httpsManager(new QNetworkAccessManager(this)),
      postUrl("https://aip.baidubce.com/rpc/2.0/ai_custom/v1/wenxinworkshop/chat/ernie-3.5-128k"),
      token("24.d73f8badebe37e3e75ccd69500cf8ce4.2592000.1719122493.282335-74022858"),
      userName("user")
{
    setWindowTitle("AI Chat");
    setMinimumSize(600, 400);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *inputLayout = new QHBoxLayout;

    inputLineEdit = new QLineEdit(this);
    sendButton = new QPushButton("Send", this);
    exitButton = new QPushButton("Exit", this);  // 创建退出按钮
    responseTextEdit = new QTextEdit(this);
    responseTextEdit->setReadOnly(true);
    responseTextEdit->setStyleSheet("QTextEdit { background-color: #f0f0f0; }");

    inputLayout->addWidget(inputLineEdit);
    inputLayout->addWidget(sendButton);
    inputLayout->addWidget(exitButton);  // 将退出按钮添加到布局

    QLabel *titleLabel = new QLabel("AI Chat Interface", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("QLabel { font-size: 20px; font-weight: bold; }");

    mainLayout->addWidget(titleLabel);
    mainLayout->addWidget(responseTextEdit);
    mainLayout->addLayout(inputLayout);

    connect(sendButton, &QPushButton::clicked, this, &tran::onSendButtonClicked);
    connect(httpsManager, &QNetworkAccessManager::finished, this, &tran::onReplyFinished);
    connect(exitButton, &QPushButton::clicked, this, &tran::onExitButtonClicked);

    // 调整间距
    mainLayout->setSpacing(10);
    inputLayout->setSpacing(10);
}

tran::tran(const QString &username,QWidget *parent)
    : QWidget(parent),
      httpsManager(new QNetworkAccessManager(this)),
      postUrl("https://aip.baidubce.com/rpc/2.0/ai_custom/v1/wenxinworkshop/chat/ernie-3.5-128k"),
      token("24.d73f8badebe37e3e75ccd69500cf8ce4.2592000.1719122493.282335-74022858"),
      userName("user")
{
    setWindowTitle("AI Chat");
    setMinimumSize(600, 400);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *inputLayout = new QHBoxLayout;

    inputLineEdit = new QLineEdit(this);
    sendButton = new QPushButton("Send", this);
    exitButton = new QPushButton("Exit", this);  // 创建退出按钮
    responseTextEdit = new QTextEdit(this);
    responseTextEdit->setReadOnly(true);
    responseTextEdit->setStyleSheet("QTextEdit { background-color: #f0f0f0; }");

    inputLayout->addWidget(inputLineEdit);
    inputLayout->addWidget(sendButton);
    inputLayout->addWidget(exitButton);  // 将退出按钮添加到布局

    QLabel *titleLabel = new QLabel("AI Chat Interface", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("QLabel { font-size: 20px; font-weight: bold; }");

    mainLayout->addWidget(titleLabel);
    mainLayout->addWidget(responseTextEdit);
    mainLayout->addLayout(inputLayout);

    connect(sendButton, &QPushButton::clicked, this, &tran::onSendButtonClicked);
    connect(httpsManager, &QNetworkAccessManager::finished, this, &tran::onReplyFinished);
    connect(exitButton, &QPushButton::clicked, this, &tran::onExitButtonClicked);

    // 调整间距
    mainLayout->setSpacing(10);
    inputLayout->setSpacing(10);
    currentUser=username;
}
void tran::onExitButtonClicked()
{
    this->close();
    maintool* w=new maintool(currentUser);
    w->show();
}
tran::~tran()
{
}

void tran::onSendButtonClicked()
{
    QString userInput = inputLineEdit->text();
    if (userInput.isEmpty()) {
        responseTextEdit->append("<p style='color:red;'>Input cannot be empty.</p>");
        return;
    }

    QByteArray dataArray = QStringToQByteArray(userInput);

    QNetworkRequest request(QUrl(postUrl + "?access_token=" + token));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    httpsManager->post(request, dataArray);
    responseTextEdit->append("<p style='color:blue;'><b>User:</b> " + userInput + "</p><br>");
    inputLineEdit->clear();
}

void tran::onReplyFinished(QNetworkReply* reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseByte = reply->readAll();
        QString replyStr = QByteArrayToQString(responseByte);
        responseTextEdit->append("<p style='color:green;'><b>AI:</b> " + replyStr + "</p><br>");
    } else {
        responseTextEdit->append("<p style='color:red;'>Network error: " + reply->errorString() + "</p>");
    }
    reply->deleteLater();
    // 自动滚动到最新内容
    QScrollBar *scrollBar = responseTextEdit->verticalScrollBar();
    scrollBar->setValue(scrollBar->maximum());
}

QByteArray tran::QStringToQByteArray(const QString& str)
{
    QJsonObject jsonData1;
    QJsonArray arrayData;
    QJsonObject jsonData2;

    jsonData1.insert("content", str);
    jsonData1.insert("role", userName);

    arrayData.append(jsonData1);

    jsonData2.insert("messages", arrayData);

    QJsonDocument doc;
    doc.setObject(jsonData2);

    return doc.toJson();
}

QString tran::QByteArrayToQString(const QByteArray& ba)
{
    QJsonDocument doc = QJsonDocument::fromJson(ba);
    QJsonObject retMess = doc.object();
    QString strReq = retMess.value("result").toString();
    return strReq;
}
