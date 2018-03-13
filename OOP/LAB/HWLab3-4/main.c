#include <stdio.h>
#include "headers/console.h"
#include "headers/country.h"
#include "headers/repository.h"
#include "controller/controller.h"
#include <string.h>
#include <stdlib.h>

#define True 1
#define False 0

/*
a. The application must allow adding, deleting or updating a
country. Updating must also consider the case of migration: a
        given number of people leave one country to migrate in another.
b. The application should offer the possibility to display all the
 countries whose names contain a given string (if the string is empty,
 all the countries should be considered).
c. The application should allow displaying all the countries on a given
 continent (if the continent is empty, all states should be considered),
 whose populations are greater than a given value, sorted ascending by population.
d. The application must provide multiple undo and redo functionality.
 Each step will undo/redo the previous operation performed by the user.
*/
/*
 * 1 - AMERICA N
 * 2 - AMERICA S
 * 3 - EUROPA
 * 4 - ASIA
 * 5 - AFRICA
 * 7 - AUSTRALIA
 * 8 - ANTARCTICA
 * */
int main() {

    CountriesRepo *repo = createRepo();
    Controller *ctrl = createController(repo);

    addCountryController(ctrl, "Romania", 3, 20000000);
    addCountryController(ctrl, "Germania", 3, 90000000);
    addCountryController(ctrl, "USA", 1, 12000000);

    while(True){
        printMenu();
        int op = readIntegerNumber(">>>");
        if(op == 1) {
            Country *c = readCountryData();
            addCountryController(ctrl, c->name, c->continent, c->population);
            destroyCountry(c);
            printf("1\n");
        }
        else if(op == 2) {
            char *message = (char*)malloc(100* sizeof(char));
            strcpy(message, "Enter a name to delete that country: ");
            char* name = (char*)malloc(15* sizeof(char));
            readString(message, name);
            deleteCountry(ctrl -> repo, name);
            free(name);
            printf("2\n");
        }
        else if(op == 3) {
            char *message = (char*)malloc(100* sizeof(char));
            strcpy(message, "Enter a name to delete that country: ");
            char* name = (char*)malloc(15* sizeof(char));
            readString(message, name);
            int pop = -1;
            printf("Enter a new population: ");
            scanf("%d", &pop);
            modifyCountry(getCountryAt(ctrl -> repo, findPosition(ctrl->repo, name)), pop);
            free(name);
            free(message);
            printf("3\n");
        }
        else if(op == 4) {
            printf("4\n");
            char *message = (char*)malloc(100* sizeof(char));
            strcpy(message, "Enter a string to filter the countries list: ");
            char* name = (char*)malloc(15* sizeof(char));
            readString(message, name);
            listAll(ctrl->repo, name);
            free(name);
            free(message);
        }
        else if(op == 5) {
            printf("5\n");
        }
        else if(op == 6) {
            printf("6\n");
        }
        else if(op == 7) {
            printf("7\n");
        }
        else if(op == 8) {
            printf("exit\n");

            exit(0);
        }
        else {
            break;
            printf("default\n");
        }
    }
}