#include <iostream>
#include "headers/Canvas.h"
#include "headers/Rectangle.h"
#include "headers/UI.h"
#include "headers/Repo.h"
#include "headers/Triangle.h"

/**
 *  Figura geometrica : clasa abstracta cu o metoda pur virtuala draw
 *  care primeste ca parametru o matrice : virtual void draw(int[][] canvas, x, y)
 *
 *  FIgura geometrica
       int l - lungimea patratului/catetei
       int v - culoarea

    clasa abstracta
	pur virtuala draw(Canvas& canvas, int x, int y)

    x, y - coordonatele de unde incepem sa desenam

    Square
    Triangle

    addSquare()
    addTriangle()
    validare()

    exportCanvas(nume_fis)=> scrie matricea in fisier
 */
int main() {
    auto *repo = new Repo();
    auto *controller = new Controller(repo);
    auto *ui = new UI(controller);
    ui->start();
}