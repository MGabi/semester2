//
// Created by mgabi on 17.05.2018.
//

#include <iostream>
#include "../headers/Triangle.h"

void Triangle::draw(Canvas *canvas, int x, int y) {
    for (int i=y; i <= y+this->getL(); i++){
        canvas->canvas[i][x] = this->getColor();
        canvas->canvas[x+this->getL()][i] = this->getColor();
    }

    for (int i=x; i<x+this->getL(); i++){
        for (int j = y; j < y+i; j++) {
            canvas->canvas[i][j] = this->getColor();
        }
    }
}

Triangle::Triangle(int l, int color) : Shape(l, color) {}
