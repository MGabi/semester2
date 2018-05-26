#include <iostream>
#include "headers/UI.h"
#include "headers/Controller.h"
#include "headers/CSVRepo.h"
#include "headers/CoverageTests.h"
#include "headers/Playlist.h"

int main() {
    CoverageTests tests{};
    tests.startTesting();

    string csvfile{"../repo_csv.csv"};
    string csvplaylist{"../playlist.csv"};
    auto *repo = new CSVRepo(csvfile);
    auto *playlist = new Playlist(csvplaylist);
    auto *ctrl = new Controller(repo, playlist);
    auto *ui = new UI(ctrl);
    ui->start();

    repo->saveData();
    delete repo;
    delete ctrl;
    delete ui;
}