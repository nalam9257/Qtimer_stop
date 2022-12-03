#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QDebug>
//#include<mainwindow.h>
#include<QDebug>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
signals :
    void counterReq() ;
private slots:
    void on_buttonBox_accepted();

private:
    Ui::Dialog *ui;
//    MainWindow *mw ;
};

#endif // DIALOG_H
