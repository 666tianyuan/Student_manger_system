#ifndef STUSQL_H
#define STUSQL_H
#include <QObject>
#include <QSqlDatabase>

struct StuInfo{
    int id;
    QString name;
    quint8 age;
    quint16 grade;
    quint16 uiclass;
    quint32 studentid;
    QString phone;
    QString wechat;
};
struct UserInfo{
    QString username;
    QString password;
    QString aut;
};

class stuSql : public QObject
{
    Q_OBJECT
public:
    //写个单例，全局唯一的对象
    static stuSql*ptrstuSql;
    static stuSql*getinstance(){
        if(nullptr == ptrstuSql){
            ptrstuSql = new stuSql;
        }
        return ptrstuSql;

    }
    explicit stuSql(QObject *parent = nullptr);
//    初始化
    void init();
//    查询所有学生数量
    quint32 getStuCnt();
//   查询第几页学生数据(从第零页开始）
    QList<StuInfo>getPageStu(quint32 page,quint32 uiCnt);
//    增加学生
    bool addStu(StuInfo);
    bool addStu(QList<StuInfo>l);
//    删除学生
    bool delStu(int id);
//    清空学生表
    bool clearStuTable();
//    修改学生信息
    bool UpdateStuInfo(StuInfo);
//    查询所有用户
    QList<UserInfo> getAlluser();
//    查询用户名是否存在
    bool isExit(QString strUser);
//    更新用户信息
    bool upDateUser(UserInfo info);
//    添加单个用户
    bool addUser(UserInfo info);
//    删除单个用户
    bool delUser(QString strUserName);

private:
    QSqlDatabase m_db;



signals:

};

#endif // STUSQL_H
