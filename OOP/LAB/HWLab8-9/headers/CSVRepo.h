//
// Created by mgabi on 09.04.2018.
//
#pragma once

#include "Repo.h"

class CSVRepo : public Repo {
private:
    string csvFile;
    vector<Tutorial*> tutorials;

public:
    CSVRepo() = default;

    void addTutorialToRepo(Tutorial t) override;

    long findTutorialPosition(string title, string presenter) override;

    void removeTutorial(string title, string presenter) override;

    void updateTutorial(Tutorial newTutorial) override;

    vector<Tutorial*> getAllTutorials() override;

    Tutorial getTutorial(string name, string presenter) override;

    vector<Tutorial> getTutorialsBy(string name, string presenter) override;

    bool tutorialExists(string name, string presenter) override;

    bool loadData() override;

    explicit CSVRepo(const string &csvFile);

    Tutorial* getTutorial(int position) override;


};
