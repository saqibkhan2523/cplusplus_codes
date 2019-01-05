#include "book_s.h"
#include "ui_book_s.h"

book_s::book_s(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::book_s)
{
    ui->setupUi(this);
}

book_s::~book_s()
{
    delete ui;
}

void book_s::on_pushButton_clicked()
{
    QSqlQuery sq;

        if(ui->radioButton->isChecked())
        {
               sq.exec("select * from libitem where name = '"+ui->lineEdit->text()+"'");
               if(sq.next())
               {
                   ui->lineEdit_2->setText(sq.value(0).toString());
                   ui->lineEdit_3->setText(sq.value(1).toString());
                   ui->lineEdit_4->setText(sq.value(2).toString());
                   ui->lineEdit_5->setText("");
                   ui->lineEdit_6->setText(sq.value(4).toString());
               }
        }
        if(ui->radioButton_2->isChecked())
        {
               sq.exec("select * from libitem where author = '"+ui->lineEdit->text()+"'");
               if(sq.next())
               {
                   ui->lineEdit_2->setText(sq.value(0).toString());
                   ui->lineEdit_3->setText(sq.value(1).toString());
                   ui->lineEdit_4->setText(sq.value(2).toString());
                   ui->lineEdit_5->setText("");
                   ui->lineEdit_6->setText(sq.value(4).toString());
               }
        }
        if(ui->radioButton_3->isChecked())
        {
               sq.exec("select * from libitem where name = '"+ui->lineEdit->text()+"'");
               if(sq.next())
               {
                   ui->lineEdit_2->setText(sq.value(0).toString());
                   ui->lineEdit_3->setText(sq.value(1).toString());
                   ui->lineEdit_4->setText(sq.value(2).toString());
                   ui->lineEdit_5->setText(sq.value(3).toString());
                   ui->lineEdit_6->setText(sq.value(4).toString());
               }
        }
        if(ui->radioButton_4->isChecked() )
        {
               sq.exec("select * from libitem where author = '"+ui->lineEdit->text()+"'");
               if(sq.next())
               {
                   ui->lineEdit_2->setText(sq.value(0).toString());
                   ui->lineEdit_3->setText(sq.value(1).toString());
                   ui->lineEdit_4->setText(sq.value(2).toString());
                   ui->lineEdit_5->setText(sq.value(3).toString());
                   ui->lineEdit_6->setText(sq.value(4).toString());
               }
        }
}

void book_s::on_pushButton_2_clicked()
{
    this->close();
}
