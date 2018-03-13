//
// Created by Gabi on 3/13/2018.
// Email : ytgabi98@gmail.com
//

#include "../../headers/country.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Country *createCountry(char *name, int continent, int population){
    Country *country = (Country*)malloc(sizeof(Country));
    country -> population = population;
    country -> continent = continent;

    country -> name = (char*)malloc(sizeof(char) * (strlen(name)+1));
    strcpy(country -> name, name);

    return country;
}

void destroyCountry(Country* country){
    if (country == NULL)
        return;

    free(country -> name);
    free(country);
}

Country* copyCountry(Country* c){
    if (c == NULL)
        return NULL;

    Country* newC = createCountry(getName(c), getContinent(c), getPopulation(c));
    return newC;
}

void modifyCountry(Country* country, int population){
    if (country == NULL)
        return;
    country -> population = population;
}

char* getName(Country* c){
    return c -> name;
}

int getContinent(Country* c){
    return c -> continent;
}

int getPopulation(Country* c){
    return c -> population;
}

void toString(Country* c, char str[]){
    if (c == NULL)
        return;
    sprintf(str, "Country name:%s, continent: %d, population %d\n", c -> name, c -> continent, c -> population);
}
