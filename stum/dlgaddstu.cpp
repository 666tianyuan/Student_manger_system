#include "dlgaddstu.h"
#include "ui_dlgaddstu.h"
#include"stusql.h"
#include<QMessageBox>
#include"mainwindow.h"
DlgAddStu::DlgAddStu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgAddStu)
{
    ui->setupUi(this);
}

DlgAddStu::~DlgAddStu()
{
    delete ui;
}
//复用函数，判断添加还是修改
void DlgAddStu::setType(bool isAdd,StuInfo info)
{
    m_isAdd = isAdd;
    m_info=info;
    ui->leName->setText(info.name);
    ui->leAge->setValue(info.age);
    ui->leUiclass->setText(QString::number(info.uiclass));
    ui->leGrade->setText(QString::number(info.grade));
    ui->leStuid->setText(QString::number(info.studentid));
    ui->lePhone->setText(info.phone);
    ui->leWechat->setText(info.wechat);
}

void DlgAddStu::on_saveBtn_clicked()
{
    StuInfo info;
    auto ptr = stuSql::getinstance();
    info.name=ui->leName->text();
    info.age=ui->leAge->text().toUInt();
    info.uiclass=ui->leUiclass->text().toUInt();
    info.grade=ui->leGrade->text().toUInt();
    info.studentid=ui->leStuid->text().toUInt();
    info.phone=ui->lePhone->text();
    info.wechat=ui->leWechat->text();
    if(m_isAdd){
        ptr->addStu(info);
         QMessageBox::information(nullptr,"信息","存储成功");
    }
    else
    {
       info.id=m_info.id;
        ptr->UpdateStuInfo(info);
        QMessageBox::information(nullptr,"信息","修改成功");
    }



    this->hide();
}

void DlgAddStu::on_cancelBtn_clicked()
{
    this->hide();
}
