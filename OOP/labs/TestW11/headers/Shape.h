//
// Created by mgabi on 17.05.2018.
//

#ifndef TESTW11_SHAPE_H
#define TESTW11_SHAPE_H


#include "Canvas.h"

class Shape {
private:
    int l;
    int color;
public:
    Shape(int l, int color) : l(l), color(color) {}

    virtual void draw(Canvas *canvas, int x, int y) = 0;

    int getL() {
        return l;
    }

    int getColor() {
        return color;
    }
};


#endif //TESTW11_SHAPE_H
