//
// Created by Gabi on 3/13/2018.
// Email : ytgabi98@gmail.com
//
#include "../headers/repository.h"
#include "../headers/country.h"
#include "../headers/operations.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

CountriesRepo* createRepo(){
    CountriesRepo* repo = (CountriesRepo*)malloc(sizeof(CountriesRepo));
    repo -> countries = createDynamicArray(CAPACITY, (DestroyElementFunctionType) &destroyCountry,
                                           (CopyElementFunctionType) &copyCountry);

    return repo;
}

void destroyRepo(CountriesRepo* r){
    if(r == NULL)
        return;
    destroy(r -> countries);
    free(r);
}

int findPosition(CountriesRepo* repo, char* strFilter){
    if (repo == NULL)
        return -1;

    for(int i=0; i<getLength(repo -> countries); i++){
        Country* c = get(repo -> countries, i);
        if (strcmp(c -> name, strFilter) == 0)
            return i;
    }
    return -1;
}

Country* findCountryBy(CountriesRepo* repo, char* strFilter){
    if (repo == NULL)
        return NULL;

    int pos = findPosition(repo, strFilter);
    if (pos == -1)
        return NULL;

    return get(repo -> countries, pos);
}

Country* getCountryAt(CountriesRepo* repo, int pos){
    if (repo == NULL)
        return NULL;

    if (pos < 0 || pos >= getLength(repo -> countries))
        return NULL;

    return get(repo -> countries, pos);
}

int addCountry(CountriesRepo* repo, Country* country){
    if (repo == NULL)
        return 0;

    if (findCountryBy(repo, country -> name) != NULL)
        return 0;

    Country* cpy = copyCountry(country);
    add(repo->countries, cpy);

    return 1;
}

int getRepoLen(CountriesRepo* repo){
    if (repo == NULL)
        return -1;
    return getLength(repo->countries);
}

int deleteCountry(CountriesRepo* repo, char* countryName){
    if (repo == NULL)
        return -1;

    int pos = findPosition(repo, countryName);
    if (pos == -1)
        return -1;

    delete(repo -> countries, pos);
    return 1;
}

void testRepository(){
    CountriesRepo* repo = createRepo();
    Country* c = createCountry("C1", 1, 1);
    addCountry(repo, c);
    assert(strcmp(getCountryAt(repo, 0)->name, "C1") == 0);
    assert(getCountryAt(repo, 0)->continent == 1);
    assert(getCountryAt(repo, 0)->population == 1);
    destroyCountry(c);
    destroyRepo(repo);

}