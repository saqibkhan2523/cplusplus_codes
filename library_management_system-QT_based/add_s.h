#ifndef ADD_S_H
#define ADD_S_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileinfo>

namespace Ui {
class add_s;
}

class add_s : public QDialog
{
    Q_OBJECT

public:
    explicit add_s(QWidget *parent = 0);
    ~add_s();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::add_s *ui;
};

#endif // ADD_S_H
