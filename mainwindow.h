#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<dialog.h>
#include<QTimer>
#include<QJsonDocument>
#include<QJsonArray>
#include<QJsonObject>
#include<QJsonValue>
#include<QDateTime>
#include<QFile>
#define  fileName "../Qtimer_sto/temp.json"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void write_to_Json() ;

signals :
    void timerStart(int) ;
    void sendCountertoDisconnect(int) ;
private slots:
    void stopTimerfun() ;
    void on_actiondisconnect_triggered();
    void on_pushButton_clicked();
    void onsetTimeToLable();
private:
    Ui::MainWindow *ui;
    int counter ;
    Dialog *dialog ;
    QTimer *timer_ ;
    uint16_t minute =0;
    uint16_t second =0;


};
// uint64_t MainWindow::counter = 0 ;
#endif // MAINWINDOW_H
