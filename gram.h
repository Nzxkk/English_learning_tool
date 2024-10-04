#ifndef GRAM_H
#define GRAM_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QtSql>

namespace Ui {
class gram;
}
struct UserAnswer {
    QString text1;
    QString text2;
    QString text3;
    QString text4;
    QString text5;
    QString text6;
    QString text7;
    QString text8;
    QString text9;
    QString text10;
    QString labelStatus1;
    QString labelStatus2;
    QString labelStatus3;
    QString labelStatus4;
    QString labelStatus5;
    QString labelStatus6;
    QString labelStatus7;
    QString labelStatus8;
    QString labelStatus9;
    QString labelStatus10;
};

class gram : public QWidget
{
    Q_OBJECT

public:
    explicit gram(QWidget *parent = nullptr);
    explicit gram(const QString &username,QWidget *parent = nullptr);
    ~gram();
private slots:
    void connectDatabase();
    void displayArticleContent();
    void on_jd_clicked();
    void on_ckda_clicked();
    void displayNextArticleContent();
    void on_xyp_clicked();
    void saveUserAnswer();
    void on_syp_clicked();
    void on_exit_clicked();
private:
    QString currentUser;
    QSqlDatabase db;
    int currentArticleId;
    QMap<int, UserAnswer> userAnswers;
private:
    Ui::gram *ui;
};

#endif // GRAM_H
