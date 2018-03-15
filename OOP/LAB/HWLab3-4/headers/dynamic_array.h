//
// Created by Gabi on 3/12/2018.
// Email : ytgabi98@gmail.com
//
#pragma once

#define CAPACITY 10

typedef void* TElement;
typedef void (*DestroyElementFunctionType)(void*);
typedef TElement (*CopyElementFunctionType)(void*);

typedef struct
{
    TElement* elems;
    int length;			// actual length of the array
    int capacity;		// maximum capacity of the array
    DestroyElementFunctionType destroyElemFct; // function pointer to the function responsible with deallocating the elements stored in the array
    CopyElementFunctionType copyElemFct;
} DynamicArray;

DynamicArray* createDynamicArray(int capacity, DestroyElementFunctionType destroyElemFct, CopyElementFunctionType copyElemFct);
DynamicArray* copyDynArray(DynamicArray* da);

void destroy(DynamicArray* arr);

TElement copy(DynamicArray* arr, TElement tElement);

void add(DynamicArray* arr, TElement t);

void delete(DynamicArray* arr, int pos);

int getLength(DynamicArray* arr);

TElement get(DynamicArray* arr, int pos);

void switchElems(DynamicArray* arr, int i, int j);