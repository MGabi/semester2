//
// Created by mgabi on 17.05.2018.
//

#include <iostream>
#include "../headers/Rectangle.h"

void Rectangle::draw(Canvas *canvas, int x, int y) {

    //vertical line
    for (int i=x; i <= x+this->getL(); i++){
        canvas->canvas[x][i] = this->getColor();
        canvas->canvas[x+this->getL()][i] = this->getColor();
    }

    //horizontal line
    for (int i = y; i <= y+this->getL() ; i++) {
        canvas->canvas[i][y] = this->getColor();
        canvas->canvas[i][y+this->getL()] = this->getColor();
    }


}

Rectangle::Rectangle(int l, int color) : Shape(l, color) {}
