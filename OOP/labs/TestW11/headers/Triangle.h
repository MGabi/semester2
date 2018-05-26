//
// Created by mgabi on 17.05.2018.
//

#ifndef TESTW11_TRIANGLE_H
#define TESTW11_TRIANGLE_H


#include "Shape.h"

class Triangle: public virtual Shape {
public:

    Triangle(int l, int color);

    void draw(Canvas *canvas, int x, int y) override;

};


#endif //TESTW11_TRIANGLE_H
