#include "controller.h"
#include "mainwindow.h"
#include "repo.h"
#include "ui_mainwindow.h"
#include <random>
#include <time.h>
#include <qdebug.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->startApp();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startApp(){
    srand(time(NULL));
    ui->saveBtn->hide();
    Repo* repo = new Repo("../jumpers");
    Controller* controller = new Controller(repo);
//    for(auto jumper: controller->getJumpers()){
//        ui->jumpersList->addItem(QString("%1").arg(jumper->getName().c_str()));
//    }
    for(int i=0; i<5; i++){
        double speed = rand()%20;
        int duration = rand()%15;
        int windDir = rand()%2 - 1;
        int windSp = rand()%20;
        double dist = (speed + windDir*windSp)*duration;

        //                                nume  speed duration windSpeed windDirection distance
        this->ui->jumpersList->addItem(QString("Dist:%1  Name:%2%3  %4  %5  %6  %7")
                                 .arg(dist)     //distance
                                 .arg("Name")
                                 .arg(i)
                                 .arg(speed)    // speed
                                 .arg(duration)     // duration
                                 .arg(windSp)    // windSpeed
                                 .arg(windDir)); // windDirection

    }
}

void MainWindow::on_jumpBtn_clicked()
{
    if(this->ui->jumpersList->count() == 0)
        return;

    QString jumper = this->ui->jumpersList->takeItem(0)->text();
    if(this->ui->jumpersList->count() == 0)
        this->ui->saveBtn->show();
    //this->ui->jumpersList->takeItem(0);
    ui->afterJumpList->addItem(jumper);
    this->ui->jumpersList->sortItems(Qt::DescendingOrder);
}

void MainWindow::on_saveBtn_clicked()
{
    qDebug() << "here";
    std::ofstream out("jumpers.out");
    for(int i=0; i<ui->afterJumpList->count(); i++){
        QString jumper = ui->afterJumpList->item(i)->text();
        out << jumper.toStdString() << std::endl;
    }
}
