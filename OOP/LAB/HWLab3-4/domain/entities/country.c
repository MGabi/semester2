//
// Created by Gabi on 3/13/2018.
// Email : ytgabi98@gmail.com
//

#include "../../headers/country.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

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
    /*
 * 1 - AFRICA
 * 2 - AMERICA N
 * 3 - AMERICA S
 * 4 - ANTARCTICA
 * 5 - ASIA
 * 6 - AUSTRALIA
 * 7 - EUROPA
 * */

    if (c == NULL)
        return;
    char* continent = malloc(15* sizeof(char));
    switch (c->continent){
        case 1:
            strcpy(continent, "Africa");
            break;
        case 2:
            strcpy(continent, "America N");
            break;
        case 3:
            strcpy(continent, "America S");
            break;
        case 4:
            strcpy(continent, "Antarctica");
            break;
        case 5:
            strcpy(continent, "Asia");
            break;
        case 6:
            strcpy(continent, "Australia");
            break;
        case 7:
            strcpy(continent, "Europa");
            break;
        default:
            strcpy(continent, "NULL");
    }
    sprintf(str, "Country continent:%s, continent: %s, population %d\n", c -> name, continent, c -> population);
    free(continent);
}

void testCountry(){
    Country* c = createCountry("abcd", 1, 2);
    assert(strcmp(c->name, "abcd") == 0);
    assert(c->continent == 1);
    assert(c->population == 2);
    destroyCountry(c);
}