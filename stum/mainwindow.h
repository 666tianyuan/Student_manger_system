#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"stusql.h"
#include <QMainWindow>
#include"login.h"
#include"dlgaddstu.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    virtual void keyPressEvent(QKeyEvent*event);
private slots:
    void on_exitBtn_clicked();

    void on_simBtn_clicked();

    void on_addBtn_clicked();

    void on_modBtn_clicked();

    void on_delBtn_clicked();

    void on_clcBtn_clicked();

    void on_serBtn_clicked();

private:
    Ui::MainWindow *ui;
    Login m_ll;
    stuSql *m_ptrStuSql;
    QStringList m_lNames;
    DlgAddStu m_dlgAddStu;
    void updateTable();

};
#endif // MAINWINDOW_H
