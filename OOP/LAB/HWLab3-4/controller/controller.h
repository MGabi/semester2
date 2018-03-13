//
// Created by Gabi on 3/13/2018.
// Email : ytgabi98@gmail.com
//
#pragma once

#include "../headers/repository.h"

typedef struct {
    CountriesRepo* repo;
} Controller;

Controller* createController(CountriesRepo* repo);
void destroyController(Controller* c);

int addCountryController(Controller* ctrl, char* name, int continent, int population);

CountriesRepo* getRepo(Controller* c);