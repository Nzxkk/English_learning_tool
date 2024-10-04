#ifndef MEMORIZEWORDS_H
#define MEMORIZEWORDS_H

#include <QWidget>
#include <QSqlDatabase>
namespace Ui {
class memorizewords;
}

class memorizewords : public QWidget
{
    Q_OBJECT

public:
    explicit memorizewords(QWidget *parent = nullptr);
    explicit memorizewords(const QString &username, QWidget *parent = nullptr);
    ~memorizewords();
    QString currentUser;
private slots:
    void on_pushButton_clicked();
    void on_pushButton_next_clicked();
    void on_pushButton_2_clicked();
private:
    Ui::memorizewords *ui;
    void showcurrentuser();
    void connectDatabase();
    QSqlDatabase database;
    void loadWord();
    void loadProgress();
    QString currentWordTranslation;
    int lastLoadedId;
    void checkWord();
    void saveProgress();

};

#endif // MEMORIZEWORDS_H
