//
// Created by mgabi on 09.04.2018.
//

#ifndef HWLAB8_9_REPO_H
#define HWLAB8_9_REPO_H

#include <vector>
#include "Tutorial.h"

class Repo {
private:
    vector<Tutorial> tutorials;
public:
    Repo() = default;

    virtual void addTutorialToRepo(Tutorial t) = 0;

    virtual void removeTutorial(string title, string presenter) = 0;

    virtual void updateTutorial(Tutorial newTutorial) = 0;

    virtual vector<Tutorial *> getAllTutorials() = 0;

    virtual Tutorial * getTutorial(string title, string presenter) = 0;
    virtual Tutorial * getTutorial(int position) = 0;

    virtual vector<Tutorial *> getTutorialsBy(string title = "", string presenter = "") = 0;

    virtual bool tutorialExists(string title, string presenter) = 0;

    virtual void loadData() = 0;

    virtual long findTutorialPosition(string title, string presenter) = 0;
};


#endif //HWLAB8_9_REPO_H
