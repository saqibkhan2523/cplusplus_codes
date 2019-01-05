#ifndef USECASE_H
#define USECASE_H

#include <QDialog>
#include <QDebug>
#include "view_info.h"
#include "book_s.h"
#include "hold_b.h"
#include "add_s.h"
#include "u_info.h"
#include "add_i.h"
#include "del_i.h"
#include "c_info.h"
#include "view_info_s.h"
#include "hold_b_s.h"

namespace Ui {
class usecase;
}

class usecase : public QDialog
{
    Q_OBJECT

public:
    explicit usecase(QWidget *parent = 0);
    ~usecase();

    void setobj(QString u);
    void setch(bool c);

private slots:
    void on_vi_clicked();

    void on_search_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_updateinfo_clicked();

    void on_add_i_clicked();

    void on_del_i_clicked();

    void on_c_i_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::usecase *ui;

    view_info *vi;
    view_info_s *vis;
    book_s *bs;
    hold_b *hb;
    add_s *as;
    u_info *upi;
    add_i *ai;
    del_i *di;
    c_info *ci;
    hold_b_s *hbs;

    QString usr;
    bool ch;
};

#endif // USECASE_H
