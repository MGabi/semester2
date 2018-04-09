//
// Created by mgabi on 09.04.2018.
//

#include <fstream>
#include <iostream>
#include "../headers/CSVRepo.h"
#include <algorithm>

CSVRepo::CSVRepo(const string &csvFile) {
    this->csvFile = csvFile;
    this->loadData();
}

void CSVRepo::addTutorialToRepo(Tutorial t) {
    this->tutorials.push_back(new Tutorial(t));
}

void CSVRepo::removeTutorial(string title, string presenter) {
    this->tutorials.erase(this->tutorials.begin()+this->findTutorialPosition(title, presenter));
}

void CSVRepo::updateTutorial(Tutorial newTutorial) {
    int pos = this->findTutorialPosition(newTutorial.getTitle(), newTutorial.getPresenter());
    if (pos != -1)
        this->tutorials.at(pos) = new Tutorial(newTutorial);
}

vector<Tutorial*> CSVRepo::getAllTutorials() {
    return this->tutorials;
}

Tutorial CSVRepo::getTutorial(string name, string presenter) {

}

Tutorial* CSVRepo::getTutorial(int position) {
    return this->tutorials[position];
}

vector<Tutorial> CSVRepo::getTutorialsBy(string name, string presenter) {

}

bool CSVRepo::tutorialExists(string name, string presenter) {
    return this->findTutorialPosition(name, presenter) != -1;
}

bool CSVRepo::loadData() {
    ifstream in(this->csvFile);
    string line;
    Tutorial t{};

    while(in >> t){
        this->tutorials.push_back(new Tutorial(t));
    }
}

long CSVRepo::findTutorialPosition(string title, string presenter) {
    auto it = find_if(this->tutorials.begin(), this->tutorials.end(),
                      [title, presenter](Tutorial *tutorial) {
                          return tutorial->getTitle() == title &&
                                 tutorial->getPresenter() == presenter;
                      });

    if (it != this->tutorials.end())
        return it - this->tutorials.begin();

    return -1;
}
