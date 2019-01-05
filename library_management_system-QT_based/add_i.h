#ifndef ADD_I_H
#define ADD_I_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileinfo>

namespace Ui {
class add_i;
}

class add_i : public QDialog
{
    Q_OBJECT

public:
    explicit add_i(QWidget *parent = 0);
    ~add_i();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::add_i *ui;
};

#endif // ADD_I_H
