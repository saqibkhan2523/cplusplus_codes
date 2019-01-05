#ifndef HOLD_B_S_H
#define HOLD_B_S_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileinfo>

namespace Ui {
class hold_b_s;
}

class hold_b_s : public QDialog
{
    Q_OBJECT

public:
    explicit hold_b_s(QWidget *parent = 0);
    ~hold_b_s();
     void setu(QString u);

private slots:
     void on_pushButton_clicked();

     void on_pushButton_2_clicked();

private:
    Ui::hold_b_s *ui;

        QString us;
};

#endif // HOLD_B_S_H
