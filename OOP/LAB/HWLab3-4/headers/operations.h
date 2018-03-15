//
// Created by Gabi on 3/14/2018.
// Email : ytgabi98@gmail.com
//
#pragma once

#include "country.h"

typedef struct {
    Country* country;
    char* operationType;

}Operation;

Operation* createOperation(Country* c, char* operationType);
void destroyOperation(Operation* o);
Operation* copyOperation(Operation* o);
char* getOperationType(Operation* o);
Country* getCountry(Operation* o);

typedef struct {
    Operation* operations[100];
    int length;
}OperationsStack;

OperationsStack* createStack();
void destroyStack(OperationsStack* s);
void push(OperationsStack* s, Operation* o);
Operation* pop(OperationsStack* s);
Operation* popFront(OperationsStack* s);
int isEmpty(OperationsStack* s);
int isFull(OperationsStack* s);

void testsStack();