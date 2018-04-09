//
// Created by mgabi on 09.04.2018.
//
#pragma once

#include "Repo.h"
#include "CSVRepo.h"

class Controller {
private:
    CSVRepo *repo;
public:
    Controller();

    explicit Controller(Repo* repo);

    void addTutorialToRepo(Tutorial tutorial);

    bool deleteTutorial(string title, string presenter);

    bool updateTutorial(Tutorial tutorial);

    vector<Tutorial*> getAllTutorials();
};
