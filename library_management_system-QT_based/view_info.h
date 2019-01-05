#ifndef VIEW_INFO_H
#define VIEW_INFO_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileinfo>

namespace Ui {
class view_info;
}

class view_info : public QDialog
{
    Q_OBJECT

public:
    explicit view_info(QWidget *parent = 0);
    ~view_info();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::view_info *ui;
};

#endif // VIEW_INFO_H
