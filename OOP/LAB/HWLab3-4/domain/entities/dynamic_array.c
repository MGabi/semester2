//
// Created by Gabi on 3/12/2018.
// Email : ytgabi98@gmail.com
//

#include "../../headers/dynamic_array.h"
#include <stdlib.h>
#include <assert.h>
#define CAPACITY 10

DynamicArray* createDynamicArray(int capacity, DestroyElementFunctionType destroyElemFct, CopyElementFunctionType copyElemFct){
    DynamicArray* da = (DynamicArray*)malloc(sizeof(DynamicArray));
    if (da == NULL)
        return NULL;

    da->capacity = capacity;
    da->length = 0;

    da->elems = (TElement*)malloc(capacity * sizeof(TElement));
    if (da->elems == NULL)
        return NULL;

    da->destroyElemFct = destroyElemFct;
    da->copyElemFct = copyElemFct;

    return da;
}

DynamicArray* copyDynArray(DynamicArray* da){
    if (da == NULL)
        return NULL;

    DynamicArray* dac = (DynamicArray*)malloc(sizeof(DynamicArray));

    dac->capacity = da->capacity;
    dac->length = 0;

    dac->elems = (TElement*)malloc(dac->capacity* sizeof(TElement));
    if (da->elems == NULL)
        return NULL;

    dac -> destroyElemFct = da->destroyElemFct;

    for (int i = 0; i < da->length; i++) {
        TElement new = copy(da, get(da, i));
        add(dac, new);
    }

    return dac;
}

void destroy(DynamicArray* arr)
{
    if (arr == NULL)
        return;

    // deallocate each of the elements
    for (int i = 0; i < arr->length; i++)
        if (arr->elems != NULL)
            arr->destroyElemFct(arr->elems[i]);

    // free the space allocated for the elements
    free(arr->elems);
    arr->elems = NULL;

    // free the space allocated for the dynamic array
    free(arr);
    arr = NULL;
}

TElement copy(DynamicArray* arr, TElement tElement){
    if (tElement == NULL)
        return NULL;

    return arr->copyElemFct(tElement);
}

int resize(DynamicArray* arr)
{
    if (arr == NULL)
        return -1;

    arr->capacity *= 2;

    // version 1 - using realloc
    TElement* aux = (TElement*)realloc(arr->elems, arr->capacity * sizeof(TElement));
    if (aux == NULL)
    	return - 1;
    arr->elems = aux;

    return 0;
}

void add(DynamicArray* arr, TElement t)
{
    if (arr == NULL)
        return;
    if (arr->elems == NULL)
        return;

    // resize the array, if necessary
    if (arr->length == arr->capacity)
        resize(arr);
    arr->elems[arr->length++] = t;
}

void delete(DynamicArray* arr, int pos)
{
    if (arr == NULL)
        return;
    if (arr->elems == NULL)
        return;

    if (pos < 0 || pos >= arr->length)
        return;

    arr->destroyElemFct(arr->elems[pos]);

    for (int i = pos; i < arr->length - 1; i++)
        arr->elems[i] = arr->elems[i + 1];

    arr->length--;
}

int getLength(DynamicArray* arr)
{
    if (arr == NULL)
        return -1;

    return arr->length;
}

TElement get(DynamicArray* arr, int pos)
{
    return arr->elems[pos];
}

void switchElems(DynamicArray* arr, int i, int j){
    TElement t = arr->elems[i];
    arr->elems[i] = arr->elems[j];
    arr->elems[j] = t;

}