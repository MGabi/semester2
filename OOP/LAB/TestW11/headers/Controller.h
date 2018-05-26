//
// Created by mgabi on 17.05.2018.
//

#ifndef TESTW11_CONTROLLER_H
#define TESTW11_CONTROLLER_H


#include "Repo.h"
#include "Triangle.h"
#include "Rectangle.h"

class Controller {
private:
    Repo * repo;
    Canvas * canvas;
public:
    Canvas *getCanvas() const {
        return canvas;
    }

    void setCanvas(Canvas *canvas) {
        Controller::canvas = canvas;
    }

    explicit Controller(Repo *repo);
    void addTriangle(int len, int color);
    void addRectangle(int len, int color);
    std::vector<Shape*> getShapes();
};


#endif //TESTW11_CONTROLLER_H
