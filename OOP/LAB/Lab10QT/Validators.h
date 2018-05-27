//
// Created by mgabi on 09.04.2018.
//
#pragma once

#include "Tutorial.h"

class Validators {
public:
    static bool isOptionValid(int option, int maxOp);
    static bool validateTutorial(Tutorial tutorial);
};
