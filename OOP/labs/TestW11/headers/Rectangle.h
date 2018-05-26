//
// Created by mgabi on 17.05.2018.
//

#ifndef TESTW11_RECTANGLE_H
#define TESTW11_RECTANGLE_H


#include "Shape.h"

class Rectangle : public virtual Shape {
public:

    Rectangle(int l, int color);

    void draw(Canvas *canvas, int x, int y) override;

};


#endif //TESTW11_RECTANGLE_H
