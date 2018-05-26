//
// Created by Gabi on 3/13/2018.
// Email : ytgabi98@gmail.com
//

#include "controller.h"
#include "../headers/operations.h"
#include "../headers/country.h"
#include "../headers/dynamic_array.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

Controller* createController(CountriesRepo* repo, OperationsStack* undoStack, OperationsStack* redoStack){
    Controller* c = (Controller*)malloc(sizeof(Controller));
    c -> repo = repo;
    c -> undoStack = undoStack;
    c -> redoStack = redoStack;
    return c;
}

void destroyController(Controller* c){
    destroyRepo(c -> repo);
    free(c);
}

int addCountryController(Controller* ctrl, char* name, int continent, int population){
    Country* c = createCountry(name, continent, population);

    int res = addCountry(ctrl -> repo, c);
    if (res == 1){
        Operation* o1 = createOperation(c, "add");
        Operation* o2 = createOperation(c, "remove");
        push(ctrl->undoStack, o1);
        push(ctrl->redoStack, o2);
        destroyOperation(o1);
        destroyOperation(o2);
    }

    destroyCountry(c);

    return res;
}

int deleteCountryController(Controller* ctrl, char* name){
    Operation* o1 = createOperation(findCountryBy(ctrl->repo, name), "remove");
    Operation* o2 = createOperation(findCountryBy(ctrl->repo, name), "add");
    push(ctrl->undoStack, o1);
    push(ctrl->redoStack, o2);
    destroyOperation(o1);
    destroyOperation(o2);
    deleteCountry(ctrl->repo, name);
}

int modifyCountryController(Controller* ctrl, int pos, int newPopulation){
    Operation* o1 = createOperation(getCountryAt(ctrl->repo, pos), "update");
    push(ctrl->undoStack, o1);
    destroyOperation(o1);

    modifyCountry(getCountryAt(ctrl->repo, pos), newPopulation);

    Operation* o2 = createOperation(getCountryAt(ctrl->repo, pos), "update");
    push(ctrl->redoStack, o2);
    destroyOperation(o2);
}

CountriesRepo* getRepo(Controller* c){
    return c -> repo;
}

int undo(Controller* c){
    if (isEmpty(c->undoStack))
        return 0;

    Operation* opUndo = pop(c->undoStack);

    if (strcmp(getOperationType(opUndo), "add") == 0){
        Country* country = getCountry(opUndo);
        char name[20];
        strcpy(name, getName(country));
        deleteCountry(c->repo, name);
    }else if(strcmp(getOperationType(opUndo), "remove") == 0){
        Country* country = copyCountry(getCountry(opUndo));
        addCountry(c->repo, country);
        free(country);
    }else if(strcmp(getOperationType(opUndo), "update") == 0){
        Country* country = getCountry(opUndo);
        modifyCountry(findCountryBy(c->repo, country->name), country->population);
    }
    destroyOperation(opUndo);
    return 1;
}

void sortCountriesByPop(DynamicArray *countries){
    for (int i = 0; i < countries->length; ++i) {
        for (int j = 0; j < countries->length; ++j) {
            Country* c1 = get(countries, i);
            Country* c2 = get(countries, j);

            if (c1->population > c2->population){
                switchElems(countries, i, j);
            }

        }
    }
}

void sortCountriesByContinent(DynamicArray *countries){
    for (int i = 0; i < countries->length; ++i) {
        for (int j = 0; j < countries->length; ++j) {
            Country* c1 = get(countries, i);
            Country* c2 = get(countries, j);

            if (c1->continent < c2->continent){
                switchElems(countries, i, j);
            }
        }
    }
}

int redo(Controller* c){
    if (isEmpty(c->redoStack))
        return 0;

    Operation* opRedo = popFront(c->redoStack);
    if (strcmp(getOperationType(opRedo), "add") == 0){
        Country* country = getCountry(opRedo);
        char name[20];
        strcpy(name, getName(country));
        deleteCountry(c->repo, name);
    }else if(strcmp(getOperationType(opRedo), "remove") == 0){
        Country* country = copyCountry(getCountry(opRedo));
        addCountry(c->repo, country);
    }else if(strcmp(getOperationType(opRedo), "update") == 0){
        Country* country = getCountry(opRedo);
        modifyCountry(findCountryBy(c->repo, country->name), country->population);
    }
    destroyOperation(opRedo);
    return 1;
}

void testController(){
    CountriesRepo* repo = createRepo();
    OperationsStack* undoStack = createStack();
    OperationsStack* redoStack = createStack();

    Controller* controller = createController(repo, undoStack, redoStack);

    Country* c = createCountry("C1", 1, 1);
    addCountry(controller->repo, c);
    assert(strcmp(getCountryAt(controller->repo, 0)->name, "C1") == 0);
    assert(getCountryAt(controller->repo, 0)->continent == 1);
    assert(getCountryAt(controller->repo, 0)->population == 1);

    //destroyRepo(repo);
    destroyStack(undoStack);
    destroyStack(redoStack);
    destroyController(controller);
    destroyCountry(c);
}
