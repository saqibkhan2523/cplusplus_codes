#ifndef DEL_I_H
#define DEL_I_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileinfo>

namespace Ui {
class del_i;
}

class del_i : public QDialog
{
    Q_OBJECT

public:
    explicit del_i(QWidget *parent = 0);
    ~del_i();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::del_i *ui;
};

#endif // DEL_I_H
