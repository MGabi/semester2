//
// Created by mgabi on 17.05.2018.
//

#include "../headers/Controller.h"
#include "../headers/Triangle.h"

Controller::Controller(Repo *repo){
    this->repo = repo;
}

void Controller::addTriangle(int len, int color) {
    repo->addShape(new Triangle{len, color});
}

void Controller::addRectangle(int len, int color) {
    repo->addShape(new Rectangle{len, color});
}

std::vector<Shape*> Controller::getShapes() {
    return this->repo->getAll();
}
