//
// Created by mgabi on 17.05.2018.
//

#include <vector>
#include <ostream>

#ifndef TESTW11_CANVAS_H
#define TESTW11_CANVAS_H


class Canvas {
public:
    Canvas(int n, int m);

private:
    int n;
    int m;

public:
    const int getN() const;
    const int getM() const;

    friend std::ostream &operator<<(std::ostream &os, const Canvas &canvas);

    std::vector<std::vector<int>> canvas;
};


#endif //TESTW11_CANVAS_H
