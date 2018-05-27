//
// Created by mgabi on 24.04.2018.
//
#pragma once

#include "Repo.h"

class UndoAction{
public:
    virtual int executeUndo() = 0;
};
