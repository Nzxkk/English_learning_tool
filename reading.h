#ifndef READING_H
#define READING_H

#include <QWidget>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
namespace Ui {
class reading;
}

class reading : public QWidget
{
    Q_OBJECT

public:
    explicit reading(QWidget *parent = nullptr);
    explicit reading(const QString &username, QWidget *parent = nullptr);
    ~reading();
    QString currentUser;

private slots:
    void checkAnswer();
    void on_xyt_clicked();
    void fetchPreviousQuestion();
    void fetchNextQuestion();
    void on_syt_clicked();

    void on_pushButton_clicked();
    void on_xuanze_activated(int index);
    void jumpToFirstQuestionOfArticle(int articleId);

private:
    Ui::reading *ui;

    QSqlDatabase db;
    QString correctAnswer;
    void connectDatabase();
    int currentArticleId;
    int currentQuestionId;
    int newArticleId;
    void displayArticleContent();
    int totalQuestionCount;
    void showTextOnAllWidgets();
    void updateText();
    void displayQuestion();
    QMap<int, QPair<QString, QString>> questionStatus;




};

#endif // READING_H
