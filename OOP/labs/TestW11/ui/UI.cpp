//
// Created by mgabi on 17.05.2018.
//

#include <iostream>
#include <fstream>
#include "../headers/UI.h"
#include "../headers/Triangle.h"
#include "../headers/Rectangle.h"

#define True 1
#define False 0

UI::UI(Controller *controller) {
    this->ctrl = controller;
}

void UI::printMenu() {
    std::cout << "1. Add triangle\n";
    std::cout << "2. Add rectangle\n";
    std::cout << "3. Save to file\n";
    std::cout << "0. Exit\n";
}

void UI::start() {
    std::cout << "Enter the size of canvas: \n";
    int x = -1, y = -1;
    std::cout << "x = ";
    std::cin >> x;
    std::cout << "y = ";
    std::cin >> y;

    if (x < 1 || y < 1){
        std::cout << "Invalid size!\nclosing the program...\n";
        return;
    }

    this->ctrl->setCanvas(new Canvas{x, y});

    while (True){
        this->printMenu();
        int op = -1;
        std::cout << ">>> ";
        std::cin >> op;
        switch (op){
            case 0:{
                exit(0);
                break;
            }
            case 1:{
                int len = -1;
                int color = -1;
                std::cout << "Lenght of the triangle: ";
                std::cin >> len;
                std::cout << "\nColor of the triangle(int) :";
                std::cin >> color;

                if (len < 1){
                    std::cout << "\nInvalid lenght!\n";
                    continue;
                }

                ctrl->addTriangle(len, color);
                break;
            }
            case 2:{
                int len = -1;
                int color = -1;
                std::cout << "Lenght of the rectangle: ";
                std::cin >> len;
                std::cout << "\nColor of the rectangle(int) :";
                std::cin >> color;

                if (len < 1){
                    std::cout << "\nInvalid lenght!\n";
                    continue;
                }

                ctrl->addRectangle(len, color);
                break;
            }
            case 3:{
                std::vector<Shape*> shapes = this->ctrl->getShapes();
                for (auto &shape : shapes) {
                    int x = -1;
                    int y = -1;
                    std::cout << "Enter x position: ";
                    std::cin >> x;
                    std::cout << "Enter y position: ";
                    std::cin >> y;

                    if (x < 0 ||
                        y < 0 ||
                        x > this->ctrl->getCanvas()->getM() ||
                        y > this->ctrl->getCanvas()->getN() ||
                        x + shape->getL() > this->ctrl->getCanvas()->getM() ||
                        y + shape->getL() > this->ctrl->getCanvas()->getN()) {
                        std::cout << "Invalid position\n";
                        continue;
                    }
                    shape->draw(this->ctrl->getCanvas(), x, y);
                }
                std::ofstream outFile("canvas.txt", std::ios::out | std::ios::trunc);
                outFile << *this->ctrl->getCanvas();
                outFile.close();
                break;
            }
            default:{
                std::cout << "Something's went wrong, the program will be closed!\n";
                break;
            }
        }
    }
}
