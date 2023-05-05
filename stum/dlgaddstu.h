#ifndef DLGADDSTU_H
#define DLGADDSTU_H

#include <QDialog>
#include"stusql.h"
namespace Ui {
class DlgAddStu;
}

class DlgAddStu : public QDialog
{
    Q_OBJECT

public:
    explicit DlgAddStu(QWidget *parent = nullptr);
    ~DlgAddStu();
    void setType(bool isAdd,StuInfo info={});

private slots:
    void on_saveBtn_clicked();

    void on_cancelBtn_clicked();

private:
    Ui::DlgAddStu *ui;
    bool m_isAdd;
    StuInfo m_info;
};

#endif // DLGADDSTU_H
