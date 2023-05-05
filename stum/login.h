#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include"regcount.h"
namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_logBtn_clicked();


    void on_regBtn_clicked();

signals:
    void sendLoginSuccess();
protected:
    void closeEvent(QCloseEvent*event);
private:
    Ui::Login *ui;

};

#endif // LOGIN_H
