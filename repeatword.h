#ifndef REPEATWORD_H
#define REPEATWORD_H

#include <QWidget>
#include <QSqlDatabase>
namespace Ui {
class repeatword;
}

class repeatword : public QWidget
{
    Q_OBJECT

public:
    explicit repeatword(QWidget *parent = nullptr);
    explicit repeatword(const QString &username, QWidget *parent = nullptr);
    ~repeatword();
    QString currentUser;

private slots:
    void on_exportButton_clicked();
    void on_pushButton_clicked();

private:
    void showcurrentuser();
    Ui::repeatword *ui;
     QSqlDatabase database;
    bool connectToDatabase();
    void showErrorWords();

};

#endif // REPEATWORD_H
