#include "hold_b_s.h"
#include "ui_hold_b_s.h"
#include <QMessageBox>

hold_b_s::hold_b_s(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hold_b_s)
{
    ui->setupUi(this);
}

hold_b_s::~hold_b_s()
{
    delete ui;
}

void hold_b_s::setu(QString u)
{
    us = u;
}

void hold_b_s::on_pushButton_clicked()
{
    QString sr,sn,bn,ch;
        QSqlQuery sq;
       if(sq.exec("select * from user where usr='"+us+"'"))
       {
        if(sq.next())
        {
            sn=sq.value(2).toString();
            sr=sq.value(3).toString();
        }
       }

       ui->lineEdit->setText(sr);
       ui->lineEdit_2->setText(sn);
        bn = ui->lineEdit_3->text();


        if(sq.exec("select * from libitem where name='"+bn+"'"))
        {
            if(sq.next())
                ch = sq.value(4).toString();

            if(ch == "a")
            {
                QMessageBox::information(this,tr("Note"),tr("Book is Available"));
                return;
            }
            else
            {
               sq.prepare("insert into onhold (srnum,sname,bname) values(?,?,?)");

               sq.bindValue(0,sr);
               sq.bindValue(1,sn);
               sq.bindValue(2,bn);

               sq.exec();
               QMessageBox::information(this,tr("Note"),tr("Placed on Hold"));
            }
        }
        else
        {
            QMessageBox::warning(this,tr("Note"),tr("Book not Exist"));
        }
}

void hold_b_s::on_pushButton_2_clicked()
{
    this->close();
}
