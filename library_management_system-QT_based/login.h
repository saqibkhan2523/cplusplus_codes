#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileinfo>
#include "usecase.h"

namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();

    void delay(int s);

private slots:
    void on_quit_clicked();

    void on_log_clicked();

private:
    Ui::login *ui;
    QSqlDatabase db;

    usecase *uc;
};

#endif // LOGIN_H
