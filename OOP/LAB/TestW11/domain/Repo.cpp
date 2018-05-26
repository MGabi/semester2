//
// Created by mgabi on 17.05.2018.
//

#include "../headers/Repo.h"

std::vector<Shape*> Repo::getAll() {
    return this->shapes;
}

void Repo::addShape(Shape *shape) {
    this->shapes.push_back(shape);
}
