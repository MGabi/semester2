//
// Created by mgabi on 09.04.2018.
//

#include <fstream>
#include <iostream>
#include "CSVRepo.h"
#include "UndoAdd.h"
#include <algorithm>

CSVRepo::CSVRepo(const string &csvFile) {
    this->csvFile = csvFile;
    this->writeDataToFile();
    this->loadData();
}

void CSVRepo::addTutorialToRepo(Tutorial t) {
    //this->tutorials.push_back(new Tutorial(t));
    this->tutorials.push_back(new Tutorial{t});
    //this->undo.push_back(new UndoAdd(dynamic_cast<Repo&>(this), Tutorial{t}));
    this->saveData();
}

void CSVRepo::removeTutorial(string title, string presenter) {
    int pos = (int)this->findTutorialPosition(title, presenter);
    if(pos != -1) {
        this->tutorials.erase(this->tutorials.begin() + pos);
        this->saveData();
    }
}

void CSVRepo::updateTutorial(Tutorial newTutorial) {
    int pos = (int)this->findTutorialPosition(newTutorial.getTitle(), newTutorial.getPresenter());
    if (pos != -1) {
        this->tutorials[pos]->setRefLink(newTutorial.getRefLink());
        this->tutorials[pos]->setDuration(newTutorial.getDuration());
        this->tutorials[pos]->setLikes(newTutorial.getLikes());
        this->saveData();
    }
}

vector<Tutorial*> CSVRepo::getAllTutorials() {
    return this->tutorials;
}

Tutorial* CSVRepo::getTutorial(string title, string presenter) {
    int pos = (int)this->findTutorialPosition(title, presenter);
    if (pos != -1)
        return this->tutorials[pos];
    else
        return nullptr;
}

Tutorial* CSVRepo::getTutorial(int position) {
    return this->tutorials[position];
}

vector<Tutorial*> CSVRepo::getTutorialsBy(string title = "", string presenter = "") {
    vector<Tutorial*> filtered;
    copy_if (this->tutorials.begin(), this->tutorials.end(), back_inserter(filtered),
                       [&title, &presenter](Tutorial* t){
                           if(title.empty())
                               return t->getPresenter() == presenter;
                           else if(presenter.empty())
                               return t->getTitle() == title;
                           else
                               return t->getPresenter() == presenter &&
                                       t->getTitle() == title;
                        });
    return filtered;
}

bool CSVRepo::tutorialExists(string title, string presenter) {
    return this->findTutorialPosition(title, presenter) != -1;
}

void CSVRepo::loadData() {
    ifstream in(this->csvFile);
    string line;
    Tutorial t{};
    this->tutorials.clear();
    while(in >> t){
        this->tutorials.push_back(new Tutorial(t));
    }
    in.close();
}

void CSVRepo::saveData() {
    ofstream out(this->csvFile, ios::out | ios::trunc);

    for(auto tutorial: this->tutorials){
        out << tutorial->getTitle() << ";" << tutorial->getPresenter() << ";" << tutorial->getRefLink() << ";" << tutorial->getDuration().toString() << ";" << tutorial->getLikes() << endl;
    }
    out.close();
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

void CSVRepo::writeDataToFile() {
    ofstream out("../repo_csv.csv", ios::out | ios::trunc);
    out << "Title1;Presenter1;www.youtube.com/1;1:30;10" << endl;
    out << "Title2;Presenter2;www.youtube.com/2;2:30;20" << endl;
    out << "Title3;Presenter3;www.youtube.com/3;3:30;30" << endl;
    out << "Title4;Presenter2;www.youtube.com/4;4:30;40" << endl;
    out << "Title5;Presenter2;www.youtube.com/5;5:30;50" << endl;
    out << "Title6;Presenter6;www.youtube.com/6;6:30;60" << endl;
    out.close();
}

void CSVRepo::undoOp() {
    this->undo[this->undo.size()-1]->executeUndo();
    this->undo.pop_back();
}
