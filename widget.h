#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtSql>
#include <QPainter>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QString currentUser;
private slots:
    void on_loginButton_clicked();
    void on_registerButton_clicked();
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    QSqlDatabase mainDatabase;
    bool connectMainDatabase();
    bool createUsersTable();
    void InitStyle();




};
#endif // WIDGET_H
