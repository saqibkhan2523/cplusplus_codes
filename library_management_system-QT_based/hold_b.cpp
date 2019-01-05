#include "hold_b.h"
#include "ui_hold_b.h"
#include <QMessageBox>

hold_b::hold_b(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hold_b)
{
    ui->setupUi(this);
}

hold_b::~hold_b()
{
    delete ui;
}

void hold_b::on_pushButton_clicked()
{
    QString sr,sn,bn,ch;
        QSqlQuery sq;

        sr = ui->lineEdit->text();
        sn = ui->lineEdit_2->text();
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

void hold_b::on_pushButton_2_clicked()
{
    this->close();
}
