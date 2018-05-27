#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "administratorwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnAdministrator_clicked()
{
    string csvfile{"../repo_csv.csv"};
    string csvplaylist{"../playlist.csv"};
    auto *repo = new CSVRepo(csvfile);
    auto *playlist = new Playlist(csvplaylist);
    auto *ctrl = new Controller(repo, playlist);

    repo->saveData();
    AdministratorWindow * admin = new AdministratorWindow(0, repo, ctrl);
    admin->show();
    this->hide();
}
