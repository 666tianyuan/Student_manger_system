#include "mainwindow.h"
#include"stusql.h"
#include <QApplication>
#include"login.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
//    w.show();
    stuSql sql;
    return a.exec();
}
