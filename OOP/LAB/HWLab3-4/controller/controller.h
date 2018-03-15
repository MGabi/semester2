//
// Created by Gabi on 3/13/2018.
// Email : ytgabi98@gmail.com
//
#pragma once

#include "../headers/repository.h"
#include "../headers/operations.h"

typedef struct {
    CountriesRepo* repo;
    OperationsStack* undoStack;
    OperationsStack* redoStack;
} Controller;

Controller* createController(CountriesRepo* repo, OperationsStack* undoStack, OperationsStack* redoStack);
void destroyController(Controller* c);

int addCountryController(Controller* ctrl, char* name, int continent, int population);
int deleteCountryController(Controller* ctrl, char* name);
void sortCountriesByPop(DynamicArray *countries);
void sortCountriesByContinent(DynamicArray *countries);
int modifyCountryController(Controller* ctrl, int pos, int newPopulation);
CountriesRepo* getRepo(Controller* c);

int undo(Controller* c);
int redo(Controller* c);