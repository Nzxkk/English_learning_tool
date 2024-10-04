#ifndef NEWS_H
#define NEWS_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QtSql>
namespace Ui {
class news;
}

class news : public QWidget
{
    Q_OBJECT

public:
    explicit news(QWidget *parent = nullptr);
    explicit news(const QString &username,QWidget *parent= nullptr);
    ~news();
private slots:
    void display();
    void connectDatabase();
    void on_xyp_clicked();

    void on_syp_clicked();

    void on_pushButton_clicked();

private:
    QString currentUser;
    QSqlDatabase db;
    int currentArticleId;
    int currentId;
    int newArticleId;
    int time = 0;
private:
    Ui::news *ui;
};

#endif // NEWS_H




