#include "stusql.h"

#include <QCoreApplication>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include<QtDebug>

stuSql*stuSql::ptrstuSql=nullptr;//静态成员类外初始化
stuSql::stuSql(QObject *parent) : QObject(parent)
{
//    init();
//    StuInfo s;
//    s.id=1;
//    s.name="1111";

//     s.age=11;
//    for(int i=0;i<10;i++){
//        addStu(s);
//    }
//    getStuCnt();
//    getPageStu(1,2);
//    delStu(21);
//    UpdateStuInfo(s);
//    UserInfo info;
//    info.username="1212";
//    info.password="1111";
//    info.aut="admin";

//    addUser(info);
//    addUser(info);
//    auto l=getAlluser();
//    auto ll=isExit("1212");
//    qDebug()<<l<<ll;
//    info.password="666";
//    upDateUser(info);

//  delUser("1212");



}

void stuSql::init()
{
    if (QSqlDatabase::drivers().isEmpty())
    {
    qDebug()<<"No database drivers found";
    }
    m_db = QSqlDatabase::addDatabase("QSQLITE");
#if 0
    auto str = QCoreApplication::applicationDirPath();
    qDebug()<<str;
#endif
    m_db.setDatabaseName("D:\\666\\data.db");
    if (!m_db.open()) {
        qDebug()<<"db not open!";
}
}

quint32 stuSql::getStuCnt()
{
    QSqlQuery sql(m_db);
    sql.exec("select count(id) from student;");
    quint32 uiCnt = 0;
    while(sql.next()){
        uiCnt=sql.value(0).toUInt();
    }
    return uiCnt;
}

QList<StuInfo> stuSql::getPageStu(quint32 page, quint32 uiCut)
{
    QList<StuInfo>l;
    QSqlQuery sql(m_db);
    QString strSql =QString("select * from student order by id limit %1 offset %2;")
            .arg(uiCut).arg(page*uiCut);
    sql.exec(strSql);
    StuInfo info;
    while(sql.next()){
        info.id=sql.value(0).toUInt();
        info.name=sql.value(1).toString();
        info.age=sql.value(2).toUInt();
        info.grade=sql.value(3).toUInt();
        info.uiclass=sql.value(4).toUInt();
        info.studentid=sql.value(5).toUInt();
        info.phone=sql.value(6).toString();
        info.wechat=sql.value(7).toString();
        l.push_back(info);
    }
    return l;
}

bool stuSql::addStu(StuInfo info)
{
    QSqlQuery sql(m_db);
    QString strSql =QString("insert into student values(null,'%1',%2,%3,%4,%5,'%6','%7')").
            arg(info.name).arg(info.age).arg(info.grade).arg(info.uiclass).arg(info.studentid).arg(info.phone).arg(info.wechat);
   return sql.exec(strSql);
}
bool stuSql::addStu(QList<StuInfo> l)
{
    QSqlQuery sql(m_db);
    m_db.transaction();
    for(auto info:l){
        QString strSql =QString("insert into student values(null,'%1',%2,%3,%4,%5,'%6','%7')").
                arg(info.name).arg(info.age).arg(info.grade).arg(info.uiclass).arg(info.studentid).arg(info.phone).arg(info.wechat);
       sql.exec(strSql);
    }
    m_db.commit();
    return true;
}

bool stuSql::delStu(int id)
{
    QSqlQuery sql(m_db);
    return sql.exec(QString("delete from student where id = %1").arg(id));


}

bool stuSql::clearStuTable()
{
    QSqlQuery sql(m_db);
    sql.exec("delete from student");
    return sql.exec("delete from sqlite_sequence where name = 'student'");



}
//更新学生信息
bool stuSql::UpdateStuInfo(StuInfo info)
{
    QSqlQuery sql(m_db);
    QString strSql=QString("update student set name='%1',age=%2,grade=%3,class=%4,studentid=%5,"
                              "phone='%6',wechat='%7' where id=%8;").
            arg(info.name).arg(info.age).arg(info.grade).arg(info.uiclass).arg(info.studentid).arg(info.phone).arg(info.wechat).arg(info.id);
   return sql.exec(strSql);

//   bool ret=sql.exec(strSql);
//   QSqlError e = sql.lastError();
//     if(e.isValid()){
//       qDebug()<<e.text();
//   }
//     return ret;
}

QList<UserInfo> stuSql::getAlluser()
{
    QList<UserInfo>l;
    QSqlQuery sql(m_db);
    sql.exec("select * from username");
    UserInfo info;
    while(sql.next()){
        info.username=sql.value(0).toString();
        info.password=sql.value(1).toString();
        info.aut=sql.value(2).toString();
        l.push_back(info);
    }
    return l;
}

bool stuSql::isExit(QString strUser)
{
    QSqlQuery sql(m_db);
    sql.exec(QString("select *from username where username='%1'").arg(strUser));
    return sql.next();

}

bool stuSql::upDateUser(UserInfo info)
{
    QSqlQuery sql(m_db);
    QString strSql =QString("update username set password='%1',auth='%2' where username='%3'").arg(info.password).arg(info.aut).arg(info.username);
   return sql.exec(strSql);

}



bool stuSql::addUser(UserInfo info)
{
    QSqlQuery sql(m_db);
    QString strSql =QString("insert into username values ('%1', %2, '%3')").
            arg(info.username).arg(info.password).arg(info.aut);
   return sql.exec(strSql);
}

bool stuSql::delUser(QString strUserName)
{
    QSqlQuery sql(m_db);
    return sql.exec(QString("delete from username where username='%1'").arg(strUserName));

}
