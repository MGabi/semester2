//
// Created by mgabi on 24.04.2018.
//
#pragma once

#include "UndoAction.h"

class UndoAdd: public UndoAction {
private:
    Repo &repo;
    Tutorial tutorial;
public:
    UndoAdd(Repo &_repo, Tutorial &_tutorial) : repo(_repo), tutorial{_tutorial}{}

    int executeUndo() override;;
};
