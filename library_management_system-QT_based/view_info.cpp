#include "view_info.h"
#include "ui_view_info.h"

view_info::view_info(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::view_info)
{
    ui->setupUi(this);
}

view_info::~view_info()
{
    delete ui;
}

void view_info::on_pushButton_2_clicked()
{
    this->close();
}

void view_info::on_pushButton_clicked()
{
    QString rn = ui->lineEdit->text();

    QSqlQuery sq;

    sq.exec("select * from user where rnum  = '"+rn+"'");
    if(sq.next())
    {
        ui->lineEdit_2->setText(sq.value(0).toString());
        ui->lineEdit_3->setText(sq.value(1).toString());
        ui->lineEdit_4->setText(sq.value(2).toString());
        ui->lineEdit_5->setText(sq.value(3).toString());
    }
}
