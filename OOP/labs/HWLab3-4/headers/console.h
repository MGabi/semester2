//
// Created by Gabi on 3/12/2018.
// Email : ytgabi98@gmail.com
//
#pragma once

#include "repository.h"

void printMenu();
int isCommandValid(int cmd);
int readIntegerNumber(const char* message);
void listAll(CountriesRepo* repo, char* str);
void listAllByContinent(CountriesRepo* repo, int cont, int pop);
Country* readCountryData();
void readString(char* message, char* str);

