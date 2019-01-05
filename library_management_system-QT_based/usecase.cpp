#include "usecase.h"
#include "ui_usecase.h"

usecase::usecase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::usecase)
{
    ui->setupUi(this);
}

usecase::~usecase()
{
    delete ui;
}

void usecase::setobj(QString u)
{
    usr = u;
}

void usecase::setch(bool c)
{
    ch = c;
}

void usecase::on_vi_clicked()
{
    if(ch == true)
    {
        vis = new view_info_s(this);
        vis->setu(usr);
        vis->setc(true);
        vis->show();
    }
    else
    {
        vi = new view_info(this);
        vi->show();
    }
}

void usecase::on_search_clicked()
{
    bs = new book_s(this);
    bs->show();

}

void usecase::on_pushButton_clicked()
{
    if(ch == true)
    {
        hbs = new hold_b_s(this);
        hbs->setu(usr);
        hbs->show();
    }
    else
    {
        hb = new hold_b(this);
        hb->show();
    }
}

void usecase::on_pushButton_2_clicked()
{
    as = new add_s(this);
    as->show();
}

void usecase::on_updateinfo_clicked()
{
    upi = new u_info(this);
    upi->show();
}

void usecase::on_add_i_clicked()
{
    ai = new add_i(this);
    ai->show();
}

void usecase::on_del_i_clicked()
{
    di = new del_i(this);
    di->show();
}

void usecase::on_c_i_clicked()
{
    ci = new c_info(this);
    ci->show();
}

void usecase::on_pushButton_3_clicked()
{
    this->close();
}
