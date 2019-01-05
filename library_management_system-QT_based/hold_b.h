#ifndef HOLD_B_H
#define HOLD_B_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileinfo>

namespace Ui {
class hold_b;
}

class hold_b : public QDialog
{
    Q_OBJECT

public:
    explicit hold_b(QWidget *parent = 0);
    ~hold_b();



private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::hold_b *ui;

};

#endif // HOLD_B_H
