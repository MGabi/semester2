#include <iostream>
#include "headers/UI.h"
#include "headers/Controller.h"
#include "headers/CSVRepo.h"
#include "headers/CoverageTests.h"

int main() {
    auto *tests = new CoverageTests();
    tests->startTesting();


    /*string csvfile{"../repo_csv.csv"};
    auto *repo = new CSVRepo(csvfile);
    auto *ctrl = new Controller(repo);
    auto *ui = new UI(ctrl);
    ui->start();

    delete tests;
    delete repo;
    delete ctrl;
    delete ui;*/
}