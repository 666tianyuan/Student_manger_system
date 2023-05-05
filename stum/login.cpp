#include "login.h"
#include "ui_login.h"
#include<QMessageBox>
#include<QCloseEvent>
#include <QSqlQuery>
#include"stusql.h"
Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

}

Login::~Login()
{
    delete ui;
}

void Login::on_logBtn_clicked()
{
   //数据库查找用户名密码
    QString user;
    QString pwd;
    user = ui->userle->text();//获取用户名
    pwd = ui->pwdle->text();//获取密码
    //判断用户名密码是否为空，为空则提示不能为空
    if(user=="" || pwd=="")
    {
        QMessageBox::warning(this,"警告","用户名或密码不能为空",QMessageBox::Ok);
    }
    else
    {
        QSqlQuery sql;//执行查询语句
         sql.exec(QString("select *from username where username='%1'").arg(user));
         sql.exec(QString("select *from username where password='%2'").arg(pwd));

    //成功提示
    if(!sql.next())
            {
                //结果集为空,执行某操作
                QMessageBox::information(this,"警告","用户名或密码错误！",QMessageBox::Ok);
                // 清空内容并定位光标
                    ui->userle->clear();
                    ui->pwdle->clear();
                    ui->userle->setFocus();//将光标定位到用户名输入框
            }
            else
            {
                QMessageBox::information(this,"提醒","登录成功！",QMessageBox::Ok);
                emit sendLoginSuccess();//发送登录成功信号
                this->hide();
            }
     }

}

void Login::closeEvent(QCloseEvent *event)
{
    int ret = QMessageBox::question(this,"退出","确定退出?");
    if(ret == QMessageBox::Yes){
        event->accept();
    }
    else{
        event->ignore();
    }
}


void Login::on_regBtn_clicked()
{
    regcount *r = new regcount;
       r->show();
}
