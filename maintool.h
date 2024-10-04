#ifndef MAINTOOL_H
#define MAINTOOL_H

#include <QWidget>

namespace Ui {
class maintool;
}

class maintool : public QWidget
{
    Q_OBJECT

public:
    explicit maintool(QWidget *parent = nullptr);
    explicit maintool(const QString &username, QWidget *parent = nullptr);
    ~maintool();
    QString currentUser;
private slots:
    void on_pushButton_clicked();

    void on_reviewFailWordsButton_clicked();


    void on_readingcompreButton_clicked();

    void on_translationButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_news_clicked();

    void on_pushButton_gram_clicked();

private:

    Ui::maintool *ui;
    void showcurrentuser();
};

#endif // MAINTOOL_H
