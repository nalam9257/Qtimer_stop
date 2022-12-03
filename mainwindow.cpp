#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer_ = new QTimer(this) ;
    dialog = new Dialog(this) ;
    connect(timer_,SIGNAL(timeout()),this,SLOT(onsetTimeToLable()));
    connect(dialog,SIGNAL(counterReq()),this,SLOT(stopTimerfun()));



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::write_to_Json()
{

    QJsonDocument doc;
    QJsonObject jsonobj ;
    jsonobj.insert("timestamp",QDateTime::currentDateTime().toString());
    jsonobj.insert("Total Time",QString::number(counter/60)+":"+QString::number(counter%60));
    doc.setObject(jsonobj);
    QFile file ("../Qtimer_stop/temp.json");
//        file.open(QIODevice ::WriteOnly | QIODevice::ReadOnly | QIODevice::Truncate) ;
        QByteArray bytes = doc.toJson(QJsonDocument::Indented);
    if (file.open( QIODevice ::WriteOnly | QIODevice::Append ))
    {
        qDebug() << "save" ;
//       qDebug()<< file.errorString();

        QByteArray bytefile = doc.toJson(QJsonDocument::Indented);
        QTextStream stream(&file);
        stream.setCodec("utf-8") ;
        stream << bytefile ;

    }


}




void MainWindow::on_actiondisconnect_triggered()
{
    dialog->show() ;

}

void MainWindow::stopTimerfun()
{
    write_to_Json();
    qDebug() << "time" << counter/60 <<" " << counter%60;
    timer_->stop() ;
    counter = 0 ;
    minute = 0 ;
    second = 0 ;
    ui->timerLable->setText("00:00");

}




void MainWindow::onsetTimeToLable()
{

    second ++ ;
    counter ++ ;
    if(second == 60)
    {
        minute ++ ; ;
        ui->timerLable->setText(QString::number(minute)+":"+QString::number(second));
        second = 0;
    }
    ui->timerLable->setText(QString::number(minute)+":"+QString::number(second));
}


void MainWindow::on_pushButton_clicked()
{
    timer_->start(1000);
}

