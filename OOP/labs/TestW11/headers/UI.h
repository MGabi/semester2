//
// Created by mgabi on 17.05.2018.
//

#ifndef TESTW11_UI_H
#define TESTW11_UI_H


#include "Controller.h"

class UI {
private:
    Controller* ctrl;
public:
    explicit UI(Controller *controller);
    void start();
    void printMenu();
};


#endif //TESTW11_UI_H
