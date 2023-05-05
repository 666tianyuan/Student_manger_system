#include "regcount.h"
#include "ui_regcount.h"
#include <QButtonGroup>
#include <QSqlQuery>
#include <QMessageBox>

regcount::regcount(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::regcount)
{
    ui->setupUi(this);
}

regcount::~regcount()
{
    delete ui;
}

void regcount::on_pushButton_clicked()
{
    QString username = ui->leuser->text();
    QString password = ui->lepwd->text();
    QString rpassword = ui->lerpwd->text();
//    int age = ui->ledit_age->text().toInt();
    QSqlQuery sql;//执行查询语句
    sql.exec(QString("select *from username where username='%1'").arg(username));
    if(sql.next())
        {
            QMessageBox::information(this,"警告","用户名已存在！",QMessageBox::Ok);
        }
    else
        {
            sql.exec(QString("insert into username values ('%1','%2','%3')").arg(username).arg(password).arg(password));
            QMessageBox::information(this,"","注册成功！",QMessageBox::Ok);
            this->hide();
        }

}
