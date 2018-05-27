#include "mainwindow.h"
#include <QApplication>
#include "CSVRepo.h"
#include "Playlist.h"
#include "Controller.h"
#include "CoverageTests.h"

int main(int argc, char *argv[])
{

//    CoverageTests tests{};
//    tests.startTesting();


    //delete repo;
    //delete ctrl;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
