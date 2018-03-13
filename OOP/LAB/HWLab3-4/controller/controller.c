//
// Created by Gabi on 3/13/2018.
// Email : ytgabi98@gmail.com
//

#include "controller.h"
#include <stdlib.h>
#include <string.h>

Controller* createController(CountriesRepo* repo){
    Controller* c = (Controller*)malloc(sizeof(Controller));
    c -> repo = repo;

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
        //TODO: CREATE UNDO
    }

    destroyCountry(c);

    return res;
}

CountriesRepo* getRepo(Controller* c){
    return c -> repo;
}
