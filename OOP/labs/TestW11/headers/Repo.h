//
// Created by mgabi on 17.05.2018.
//

#ifndef TESTW11_REPO_H
#define TESTW11_REPO_H


#include "Shape.h"

class Repo {
private:
    std::vector<Shape*> shapes;

public:
    explicit Repo() = default;

    std::vector<Shape*> getAll();
    void addShape(Shape *shape);
};


#endif //TESTW11_REPO_H
