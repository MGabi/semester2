//
// Created by mgabi on 09.04.2018.
//
#pragma once

#include "Repo.h"
#include "UndoAction.h"

class CSVRepo : public Repo {
private:
    string csvFile;
    vector<Tutorial*> tutorials;
    vector<UndoAction*> undo;

public:
    CSVRepo() = default;
    explicit CSVRepo(const string &csvFile);
    void addTutorialToRepo(Tutorial t) override;

    long findTutorialPosition(string title, string presenter) override;

    void removeTutorial(string title, string presenter) override;

    void updateTutorial(Tutorial newTutorial) override;

    vector<Tutorial*> getAllTutorials() override;

    Tutorial * getTutorial(string title, string presenter) override;

    vector<Tutorial *> getTutorialsBy(string title, string presenter) override;

    bool tutorialExists(string title, string presenter) override;

    bool loadData() override;

    void saveData();

    Tutorial* getTutorial(int position) override;


    void writeDataToFile();

    void undoOp();
};
