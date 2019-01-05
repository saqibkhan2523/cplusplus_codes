#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
   db.setDatabaseName("C:/sqlite/lms2.sqlite");
   if(!db.open())
   {
       ui->log_2->setText("Failure! Database Unavailable");
   }
   else
   {
      ui->log_2->setText("Database connected. You may log in");
   }
}

login::~login()
{
    delete ui;
}

void login::delay(int s)
{
    QTime dieTime= QTime::currentTime().addSecs(s);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void login::on_quit_clicked()
{
    QCoreApplication::exit();
}

void login::on_log_clicked()
{
    QString usr,pass;
           usr = ui->lineEdit->text();
           pass = ui->lineEdit_2->text();
           QString u_c;


           QSqlQuery sq;

           sq.exec("select * from user where usr  = '"+usr+"' and pass = '"+pass+"'");
           if(sq.next())
           {
               ui->con->setText("Login Status .");
               delay(1);
               ui->con->setText("Login Status . .");
               delay(1);
               ui->con->setText("Login Status . . .");
               delay(1);
               ui->con->setText("Logged in successfully");
               u_c = sq.value(5).toString();
               u_c.toStdString();
               if(u_c == "a")
               {

                   qDebug()<<"a";
                   uc = new usecase(this);
                   uc->findChild<QLabel*>("utype")->setText("Admin Interface");
                   uc->setch(false);
                   uc->show();
               }
               if(u_c == "c")
               {
                   qDebug()<<"c";
                   uc = new usecase(this);
                   uc->findChild<QLabel*>("utype")->setText("Clrek Interface");
                   uc->findChild<QLabel*>("label_6")->hide();
                   uc->findChild<QPushButton*>("add_i")->hide();
                   uc->findChild<QLabel*>("label_7")->hide();
                   uc->findChild<QPushButton*>("del_i")->hide();
                   uc->findChild<QLabel*>("label_8")->hide();
                   uc->findChild<QPushButton*>("c_i")->hide();
                   uc->setch(false);
                   uc->show();
               }
               if(u_c == "s")
               {
                   qDebug()<<"s";
                   uc = new usecase(this);
                   uc->findChild<QLabel*>("utype")->setText("Student Interface");
                   uc->findChild<QLabel*>("label_4")->hide();
                   uc->findChild<QPushButton*>("pushButton_2")->hide();
                   uc->findChild<QLabel*>("label_5")->hide();
                   uc->findChild<QPushButton*>("updateinfo")->hide();
                   uc->findChild<QLabel*>("label_6")->hide();
                   uc->findChild<QPushButton*>("add_i")->hide();
                   uc->findChild<QLabel*>("label_7")->hide();
                   uc->findChild<QPushButton*>("del_i")->hide();
                   uc->findChild<QLabel*>("label_8")->hide();
                   uc->findChild<QPushButton*>("c_i")->hide();
                   uc->setch(true);
                   uc->setobj(usr);
                   uc->show();
               }
           }
           else
           {
               ui->con->setText("Login Failure");
           }
}
