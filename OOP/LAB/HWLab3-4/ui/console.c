//
// Created by Gabi on 3/12/2018.
// Email : ytgabi98@gmail.com
//
#include <stdio.h>
#include <stdlib.h>
#include "../headers/console.h"
#include "../headers/repository.h"
#include "../headers/country.h"
#include <string.h>

void printMenu(){
    printf("1.Add country\n");
    printf("2.Delete country\n");
    printf("3.Update country\n");
    printf("4.Display all countries whose names contains a given string\n");
    printf("5.Display all countries on a given continent\n");
    printf("6.Undo\n");
    printf("7.Redo\n");
    printf("8.Exit\n");
}

int isCommandValid(int cmd){
    return cmd >= 1 && cmd <=8;
}

int readIntegerNumber(const char* message)
{
    char s[16];
    int res = 0;
    int flag = 0;
    int r = 0;

    while (flag == 0)
    {
        printf(message);
        scanf("%s", s);

        r = sscanf(s, "%d", &res);	// reads data from s and stores them as integer, if possible; returns 1 if successful
        flag = (r == 1);
        if (flag == 0)
            printf("Error reading number!\n");
    }
    return res;
}

void readString(char* message, char *str){
    printf(message);
    scanf("%s", str);
}

void listAll(CountriesRepo* repo, char *str){
    int l = getRepoLen(repo);

    if (l == 0)
        printf("There are no countries\n");

    if (strcmp(str, "-") == 0){
        for (int i = 0; i < l; i++) {
            char s[200];
            toString(getCountryAt(repo, i), s);
            printf("%s\n", s);
        }
    } else{
        for (int i = 0; i < l; i++) {
            char s[200];
            if(strstr(getCountryAt(repo, i)->name, str) != NULL) {
                toString(getCountryAt(repo, i), s);
                printf("%s\n", s);
            }
        }
    }
}


Country* readCountryData(){
    char *name =(char*)malloc(15* sizeof(char));
    int pop;
    int cont;
    printf("Country name: ");
    scanf("%s", name);
    printf("\n");

    printf("Country continent: ");
    scanf("%d", &cont);
    printf("\n");

    printf("Country population: ");
    scanf("%d", &pop);
    printf("\n");

    return createCountry(name, cont, pop);
}