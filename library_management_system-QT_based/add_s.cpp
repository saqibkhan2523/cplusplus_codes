#include "add_s.h"
#include "ui_add_s.h"
#include <QMessageBox>

add_s::add_s(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_s)
{
    ui->setupUi(this);
}

add_s::~add_s()
{
    delete ui;
}

void add_s::on_pushButton_2_clicked()
{
    this->close();
}

void add_s::on_pushButton_clicked()
{
    QSqlQuery sq;

        QString user,pass,name,rnum;

        user = ui->lineEdit->text();
        pass = ui->lineEdit_2->text();
        name = ui->lineEdit_3->text();
        rnum = ui->lineEdit_4->text();

        sq.prepare("insert into user(usr,pass,name,rnum,cid,type) values(?,?,?,?,?,?)");

        sq.bindValue(0,user);
        sq.bindValue(1,pass);
        sq.bindValue(2,name);
        sq.bindValue(3,rnum);
        sq.bindValue(5,"s");


        if(sq.exec())
        {
            QMessageBox::information(this,tr("Note"),tr("Student Added"));
        }
        else
        {
            QMessageBox::warning(this,tr("Note"),tr("Already Exist or error"));
        }
}
