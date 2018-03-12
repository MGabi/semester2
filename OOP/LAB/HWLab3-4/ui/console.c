//
// Created by Gabi on 3/12/2018.
// Email : ytgabi98@gmail.com
//
#include <stdio.h>
#include <stdlib.h>
#include "console.h"

void printMenu(){
    printf("abcdef");
}

int* readInput(){
    int* option = malloc(sizeof(int));
    printf(" >>> ");
    scanf("%d", option);

    return (int *) *option;
}