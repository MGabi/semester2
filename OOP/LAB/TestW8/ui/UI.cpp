//
// Created by mgabi on 19.04.2018.
//

#include "../headers/MemoryAllocation.h"
#include "../headers/UI.h"
#include <iostream>

void UI::runUI() {
    while (true){
        this->printMenu();
        switch (readOption(4)){
            case 1:{
                MemoryAllocation mem = this->readMemoryData();
                this->ctrl->addMemoryToRepo(mem);
                break;
            }
            case 2:{
                string name;
                cout << "\n>>> ";
                cin >> name;
                this->removeMemory(name);
                break;
            }
            case 3:{
                string name;
                cout << "\n>>> ";
                cin >> name;
                this->markMemory(name);
                break;
            }
            case 4:{
                this->removeLargestDynamically();
                break;
            }
            case 0:{
                exit(0);
                break;
            }
            case -1:{
                break;
            }
        }
    }
}

void UI::printMenu() {
    cout << "\t1. Add a memory allocation\n";
    cout << "\t2. Deallocate a dynamic memory\n";
    cout << "\t3. Mark the usage of a variable\n";
    cout << "\t4. Find the largest dynamically allocated\n\tmemory and remove it in order to free heap space\n";
    cout << "\t0. Exit";
}

UI::UI(Controller *ctrl) {
    this->ctrl = ctrl;
}

int UI::readOption(int maxOp) {
    cout << "\n>>> ";
    int op = -1;
    cin >> op;
    if (op >= 1 && op <= maxOp)
        return op;

    return -1;

}

MemoryAllocation UI::readMemoryData() {
    cout << "\nType (s/d) : ";
    string type;
    cin >> type;

    cout << "\nOffset (integer) : ";
    int startingLocation;
    cin >> startingLocation;

    cout << "\nLabel (string) : ";
    string label;
    cin >> label;

    cout << "\nData type (integer) : ";
    int representation;
    cin >> representation;

    return MemoryAllocation{type, startingLocation, label, representation, false};
}

void UI::removeMemory(string name) {
    this->ctrl->removeMemory(name);
}

void UI::markMemory(string name) {
    this->ctrl->markMemory(name);
}

void UI::removeLargestDynamically() {
    this->ctrl->removeLargest();
}
