#ifndef VIEW_INFO_S_H
#define VIEW_INFO_S_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileinfo>

namespace Ui {
class view_info_s;
}

class view_info_s : public QDialog
{
    Q_OBJECT

public:
    explicit view_info_s(QWidget *parent = 0);
    ~view_info_s();
    void setu(QString u);
    void setc(bool ch);


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::view_info_s *ui;
    QString us;
    bool c;
};

#endif // VIEW_INFO_S_H
