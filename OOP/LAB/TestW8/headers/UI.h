//
// Created by mgabi on 19.04.2018.
//

#ifndef TESTW8_UI_H
#define TESTW8_UI_H


#include "Controller.h"

class UI {
private:
    Controller *ctrl = nullptr;
public:
    explicit UI(Controller *ctrl);

    void runUI();

    void printMenu();

    int readOption(int maxOp);

    MemoryAllocation readMemoryData();

    void removeMemory(string name);

    void markMemory(string name);

    void removeLargestDynamically();
};


#endif //TESTW8_UI_H
