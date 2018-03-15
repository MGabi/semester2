//
// Created by Gabi on 3/13/2018.
// Email : ytgabi98@gmail.com
//
#pragma once
/*
Each Country has a unique name, the continent it
 belongs to (may be Europe, America, Africa, Australia and Asia) and a population (stored in millions).*/

typedef struct {
    char *name;
    int continent;
    int population;
} Country;

Country* createCountry(char *name, int continent, int population);
void destroyCountry(Country* country);
Country* copyCountry(Country* country);
void modifyCountry(Country* country, int population);
char* getName(Country* c);
int getContinent(Country* c);
int getPopulation(Country* c);
void toString(Country* c, char str[]);