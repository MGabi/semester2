#include <stdio.h>
#include "ui/console.h"

int main() {
    int* op = readInput();
    printf("\noption: %d", (int) op);
}