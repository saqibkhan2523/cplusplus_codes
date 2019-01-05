#ifndef C_INFO_H
#define C_INFO_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileinfo>

namespace Ui {
class c_info;
}

class c_info : public QDialog
{
    Q_OBJECT

public:
    explicit c_info(QWidget *parent = 0);
    ~c_info();

private slots:
    void on_update_clicked();

    void on_clear_clicked();

private:
    Ui::c_info *ui;
};

#endif // C_INFO_H
