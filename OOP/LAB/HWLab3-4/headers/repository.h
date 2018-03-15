//
// Created by Gabi on 3/13/2018.
// Email : ytgabi98@gmail.com
//
#pragma once

#include "dynamic_array.h"
#include "country.h"

typedef struct {
    DynamicArray * countries;

} CountriesRepo;

CountriesRepo* createRepo();
Country* findCountryBy(CountriesRepo* repo, char* strFilter);
Country* getCountryAt(CountriesRepo* repo, int pos);
int findPosition(CountriesRepo* repo, char* strFilter);
int addCountry(CountriesRepo* repo, Country* country);
int getRepoLen(CountriesRepo* repo);
int deleteCountry(CountriesRepo* repo, char* countryName);
void destroyRepo(CountriesRepo* r);
