//
// Created by Gabi on 3/7/2018.
// Email : ytgabi98@gmail.com
//
#include <iostream>

class Console {
public:
    void runMenu() {
        std::cout << "1. Add country\n";
        std::cout << "2. Delete country\n";
        std::cout << "3. Update country\n";
        std::cout << "4. Display all countries which contain a given string\n";
        std::cout << "5. Display all countries which are from a given continent, sorted ascending by population\n";
        std::cout << "6. Undo last op\n";
        std::cout << "7. Redo last op\n";
    }
};
