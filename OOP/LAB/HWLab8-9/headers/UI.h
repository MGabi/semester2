//
// Created by mgabi on 09.04.2018.
//
#include <iostream>
#include "Controller.h"

using namespace std;

#pragma once

class UI {
private:
    Controller *ctrl;

public:
    UI() = default;
    explicit UI(Controller *ctrl);
    void start();

    void printAdministratorMenu();
    void printStartMenu();
    void printUserMenu();

    void readOption(int &op, int maxOp);

    void startAdministratorMode();

    void startUserMode();

    void readTutorialData(Tutorial &tutorial);

    void readTitleAndPresenter(string *pString, string *pBasic_string);
};
