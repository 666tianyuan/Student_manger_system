#ifndef REGCOUNT_H
#define REGCOUNT_H

#include <QWidget>

namespace Ui {
class regcount;
}

class regcount : public QWidget
{
    Q_OBJECT

public:
    explicit regcount(QWidget *parent = nullptr);
    ~regcount();

private slots:
    void on_pushButton_clicked();

private:
    Ui::regcount *ui;
};

#endif // REGCOUNT_H
