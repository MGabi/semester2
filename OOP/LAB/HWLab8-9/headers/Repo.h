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

    virtual void addTutorialToRepo(Tutorial t){}

    virtual void removeTutorial(string title, string presenter) {}

    virtual void updateTutorial(Tutorial newTutorial) {}

    virtual vector<Tutorial *> getAllTutorials(){}

    virtual Tutorial getTutorial(string name, string presenter){}
    virtual Tutorial * getTutorial(int position){}

    virtual vector<Tutorial> getTutorialsBy(string name = "", string presenter = ""){}

    virtual bool tutorialExists(string name, string presenter){}

    virtual bool loadData(){}

    virtual long findTutorialPosition(string title, string presenter){}
};


#endif //HWLAB8_9_REPO_H
