#include "c_info.h"
#include "ui_c_info.h"
#include <QMessageBox>

c_info::c_info(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::c_info)
{
    ui->setupUi(this);
}

c_info::~c_info()
{
    delete ui;
}

void c_info::on_update_clicked()
{
    QSqlQuery sq;

      sq.prepare("update libitem set name='"+ui->lineEdit->text()+"', author='"+ui->lineEdit_2->text()+"', pub_yr='"+ui->lineEdit_3->text()+"', duration='"+ui->lineEdit_4->text()+"', availability='"+ui->lineEdit_5->text()+"' where name='"+ui->lineEdit->text()+"'");
      if(sq.exec())
      {
          QMessageBox::information(this,tr("Note"),tr("Saved"));
      }
      else
      {
          QMessageBox::critical(this,tr("Error"),sq.lastError().text());
      }
}

void c_info::on_clear_clicked()
{
    this->close();
}
