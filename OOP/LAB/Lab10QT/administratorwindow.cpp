#include "administratorwindow.h"
#include "ui_administratorwindow.h"
#include <iostream>
#include <vector>
#include "TutorialsModel.h"
#include "Validators.h"
#include <QTableView>
#include <qdebug.h>
//#include <libnotify/notify.h>

AdministratorWindow::AdministratorWindow(QWidget *parent, CSVRepo *repo, Controller *ctrl) :
    QWidget(parent),
    ui(new Ui::AdministratorWindow){
    this->repo = repo;
    this->ctrl = ctrl;
    ui->setupUi(this);
    this->setupDataInTable();
}

AdministratorWindow::~AdministratorWindow()
{
    delete ui;
}

void AdministratorWindow::setupDataInTable(){
    vector<Tutorial*> tutorials = this->ctrl->getAllTutorials();
    this->model = new TutorialsModel(0, tutorials.size(), 5, tutorials);
    ui->tableCourses->setModel(this->model);
    ui->tableCourses->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    connect(ui->tableCourses, SIGNAL(clicked(QModelIndex)), this, SLOT(onCellSelected(QModelIndex)), Qt::AutoConnection);
}

void AdministratorWindow::refreshTutorials(vector<Tutorial*> tutorials){
    ui->tableCourses->setModel(nullptr);
    free(this->model);
    this->model = new TutorialsModel(0, tutorials.size(), 5, tutorials);
    ui->tableCourses->setModel(this->model);
    ui->tableCourses->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void AdministratorWindow::onCellSelected(QModelIndex index){
    this->currentRow = index.row();
    this->currentColumn = index.column();
    Tutorial *t = this->ctrl->getAllTutorials()[index.row()];
    ui->titleLineEdit->setText(t->getTitle().c_str());
    ui->presenterLineEdit->setText(t->getPresenter().c_str());
    ui->refLinkLineEdit->setText(t->getRefLink().c_str());
    ui->durationLineEdit->setText(QString("%1").arg(t->getDuration().getMinutes()*60+t->getDuration().getSeconds()));
    ui->likesLineEdit->setText(QString("%1").arg(t->getLikes()));
    qDebug() << t->getLikes();
}

void AdministratorWindow::on_buttonAdd_clicked()
{
    qDebug("add");
    qDebug() << ui->titleLineEdit->text();

    Tutorial t(ui->titleLineEdit->text().toStdString(),
                ui->presenterLineEdit->text().toStdString(),
                ui->refLinkLineEdit->text().toStdString(),
                Duration(ui->durationLineEdit->text().toInt()/60, ui->durationLineEdit->text().toInt()%60),
                ui->likesLineEdit->text().toInt());
    Validators v;
    if(!(v.validateTutorial(t))){
//        notify_init("Bad data");
//        NotifyNotification* n = notify_notification_new("Bad input data!",
//                                                        "Please review all the fields!",
//                                                        0);
//        notify_notification_set_timeout(n, 2000);
        return;
    }

    this->ctrl->addTutorialToRepo(t);
    this->refreshTutorials(this->ctrl->getAllTutorials());
}

void AdministratorWindow::on_buttonDelete_clicked()
{
    if(this->currentColumn < 0 || this->currentRow < 0 )
        return;
    qDebug("delete");
    Tutorial *t = this->ctrl->getAllTutorials()[this->currentRow];
    this->ctrl->deleteTutorial(t->getTitle(), t->getPresenter());
    qDebug() << this->ctrl->getAllTutorials().size();
    this->refreshTutorials(this->ctrl->getAllTutorials());
}

void AdministratorWindow::on_buttonUpdate_clicked()
{
    qDebug("update");

    Tutorial t(ui->titleLineEdit->text().toStdString(),
                ui->presenterLineEdit->text().toStdString(),
                ui->refLinkLineEdit->text().toStdString(),
                Duration(ui->durationLineEdit->text().toInt()/60, ui->durationLineEdit->text().toInt()%60),
                ui->likesLineEdit->text().toInt());
    Validators v;
    if(!(v.validateTutorial(t))){
//        notify_init("Bad data");
//        NotifyNotification* n = notify_notification_new("Bad input data!",
//                                                        "Please review all the fields!",
//                                                        0);
//        notify_notification_set_timeout(n, 2000);
        return;
    }

    this->ctrl->updateTutorial(t);
    this->refreshTutorials(this->ctrl->getAllTutorials());
}
