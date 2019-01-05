#ifndef U_INFO_H
#define U_INFO_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileinfo>

namespace Ui {
class u_info;
}

class u_info : public QDialog
{
    Q_OBJECT

public:
    explicit u_info(QWidget *parent = 0);
    ~u_info();

private slots:
    void on_clear_clicked();

    void on_update_clicked();

private:
    Ui::u_info *ui;
};

#endif // U_INFO_H
