//
// Created by mgabi on 24.04.2018.
//
#pragma once

#include "UndoAction.h"

class UndoRemove: public UndoAction {
private:
    Repo &repo;
    Tutorial &tutorial;
public:
    UndoRemove(Repo &_repo, Tutorial &_tutorial) : repo(_repo), tutorial{_tutorial}{}

    int executeUndo() override;;
};
