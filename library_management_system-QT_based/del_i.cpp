#include "del_i.h"
#include "ui_del_i.h"
#include <QMessageBox>

del_i::del_i(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::del_i)
{
    ui->setupUi(this);
}

del_i::~del_i()
{
    delete ui;
}

void del_i::on_pushButton_2_clicked()
{
    this->close();
}

void del_i::on_pushButton_clicked()
{
    QSqlQuery sq;

    sq.prepare("delete from libitem where name='"+ui->lineEdit->text()+"' and author='"+ui->lineEdit_2->text()+"' ");

    if(sq.exec())
    {
        QMessageBox::information(this,tr("Note"),tr("Item Deleted"));
    }
    else
    {
        QMessageBox::warning(this,tr("Note"),tr("Wrong input or error"));
    }
}
