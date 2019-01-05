#ifndef BOOK_S_H
#define BOOK_S_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileinfo>

namespace Ui {
class book_s;
}

class book_s : public QDialog
{
    Q_OBJECT

public:
    explicit book_s(QWidget *parent = 0);
    ~book_s();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::book_s *ui;
};

#endif // BOOK_S_H
