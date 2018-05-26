//
// Created by mgabi on 17.05.2018.
//

#include "../headers/Canvas.h"
#include <iostream>

Canvas::Canvas(int n, int m) : n(n), m(m) {
    this->canvas.reserve(static_cast<unsigned long>(n));
    for (int i = 0; i < n; i++) {
        this->canvas[i].reserve(static_cast<unsigned long>(m));
    }
}

const int Canvas::getN() const {
    return n;
}

const int Canvas::getM() const {
    return m;
}

std::ostream &operator<<(std::ostream &os, const Canvas &canvas) {
    for (int i=0; i<canvas.getM(); i++){
        for (int j = 0; j < canvas.getN(); j++) {
            os << canvas.canvas[i][j] << " ";
        }
        os << "\n";
    }
    return os;
}

