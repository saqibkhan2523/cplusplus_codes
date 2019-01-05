#include "view_info_s.h"
#include "ui_view_info_s.h"

view_info_s::view_info_s(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::view_info_s)
{
    ui->setupUi(this);
}

view_info_s::~view_info_s()
{
    delete ui;
}

void view_info_s::setu(QString u)
{
    us = u;
}

void view_info_s::setc(bool ch)
{
    c = ch;
}

void view_info_s::on_pushButton_clicked()
{
    QSqlQuery sq;

    sq.exec("select * from user where usr  = '"+us+"'");
    if(sq.next())
    {
        ui->lineEdit_2->setText(sq.value(0).toString());
        ui->lineEdit_3->setText(sq.value(1).toString());
        ui->lineEdit_4->setText(sq.value(2).toString());
        ui->lineEdit_5->setText(sq.value(3).toString());
    }
}

void view_info_s::on_pushButton_2_clicked()
{
    this->close();
}
