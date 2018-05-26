//
// Created by Gabi on 3/14/2018.
// Email : ytgabi98@gmail.com
//

#include <stdlib.h>
#include "../../headers/operations.h"
#include <string.h>
#include <assert.h>

Operation* createOperation(Country* c, char* operationType)
{
    Operation* o = (Operation*)malloc(sizeof(Operation));
    o->country = copyCountry(c);

    if (operationType != NULL)
    {
        o->operationType = (char*)malloc(sizeof(char) * (strlen(operationType) + 1));
        strcpy(o->operationType, operationType);
    }
    else
        o->operationType = NULL;

    return o;
}

void destroyOperation(Operation* o)
{
    if (o == NULL)
        return;

    destroyCountry(o->country);
    free(o->operationType);
    free(o);
}

Operation* copyOperation(Operation * o)
{
    if (o == NULL)
        return NULL;

    Operation* newOp = createOperation(o->country, o->operationType);
    return newOp;
}

char* getOperationType(Operation* o)
{
    return o->operationType;
}

Country* getCountry(Operation* o)
{
    return o->country;
}

// ---------------------------------------------------------------

OperationsStack* createStack()
{
    OperationsStack* s = (OperationsStack*)malloc(sizeof(OperationsStack));
    s->length = 0;

    return s;
}

void destroyStack(OperationsStack* s)
{
    if (s == NULL)
        return;

    for (int i = 0; i < s->length; i++)
        destroyOperation(s->operations[i]);

    free(s);
}

void push(OperationsStack* s, Operation* o)
{
    if (isFull(s))
        return;

    s->operations[s->length++] = copyOperation(o);
}

Operation* pop(OperationsStack* s)
{
    if (isEmpty(s))
        return NULL;
    s->length--;
    return s->operations[s->length];
}

Operation* popFront(OperationsStack* s){
    if (isEmpty(s))
        return NULL;
    Operation* o = copyOperation(s->operations[0]);
    if (s->length == 1)
        s->operations[0] = s->operations[1];
    else {
        for (int i = 0; i < s->length - 1; i++)
            s->operations[i] = s->operations[i + 1];
    }
    s->length--;
    return o;
}

int isEmpty(OperationsStack* s)
{
    return (s->length == 0);
}

int isFull(OperationsStack* s)
{
    return s->length == 100;
}


// Tests
void testsStack()
{
    OperationsStack* s = createStack();

    Country* p1 = createCountry("Austria", 3, 120000);
    Country* p2 = createCountry("Belgia", 3, 130000);
    Operation* o1 = createOperation(p1, "add");
    Operation* o2 = createOperation(p2, "add");
    Operation* o3 = createOperation(p1, "remove");

    destroyCountry(p1);
    destroyCountry(p2);

    push(s, o1);
    push(s, o2);
    push(s, o3);

    destroyOperation(o1);
    destroyOperation(o2);
    destroyOperation(o3);

    assert(isFull(s) == 0);
    assert(isEmpty(s) == 0);
    Operation* o = pop(s);
    assert(strcmp(o->operationType, "remove") == 0);
    destroyOperation(o);

    o = pop(s);
    assert(strcmp(o->operationType, "add") == 0);
    destroyOperation(o);

    o = pop(s);
    assert(strcmp(o->operationType, "add") == 0);
    destroyOperation(o);

    assert(isEmpty(s) == 1);

    destroyStack(s);
}