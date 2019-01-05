#include "u_info.h"
#include "ui_u_info.h"
#include <QMessageBox>

u_info::u_info(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::u_info)
{
    ui->setupUi(this);
}

u_info::~u_info()
{
    delete ui;
}

void u_info::on_clear_clicked()
{
    this->close();
}

void u_info::on_update_clicked()
{
    QSqlQuery sq;

      sq.prepare("update user set usr='"+ui->lineEdit->text()+"',pass='"+ui->lineEdit_2->text()+"',name='"+ui->lineEdit_3->text()+"',rnum='"+ui->lineEdit_4->text()+"',cid='""',type='"+ui->lineEdit_5->text()+"' where usr='"+ui->lineEdit->text()+"'");
      if(sq.exec())
      {
          QMessageBox::information(this,tr("Note"),tr("Saved"));
      }
      else
      {
          QMessageBox::critical(this,tr("Error"),sq.lastError().text());
      }
}
