#include "add_i.h"
#include "ui_add_i.h"
#include <QMessageBox>

add_i::add_i(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_i)
{
    ui->setupUi(this);
}

add_i::~add_i()
{
    delete ui;
}

void add_i::on_pushButton_2_clicked()
{
    this->close();
}

void add_i::on_pushButton_clicked()
{
    QSqlQuery sq;

    sq.prepare("insert into libitem (name,author,pub_yr,duration,availability) values(?,?,?,?,?)");

    sq.bindValue(0, ui->lineEdit->text());
    sq.bindValue(1, ui->lineEdit_2->text());
    sq.bindValue(2, ui->lineEdit_3->text());
    sq.bindValue(3, ui->lineEdit_4->text());
    sq.bindValue(4, "a");

    if(sq.exec())
    {
        QMessageBox::information(this,tr("Note"),tr("Item Added"));
    }
    else
    {
        QMessageBox::warning(this,tr("Note"),tr("Already Exist or error"));
    }
}
