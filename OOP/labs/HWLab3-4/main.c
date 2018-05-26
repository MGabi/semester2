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
 * 1 - AFRICA
 * 2 - AMERICA N
 * 3 - AMERICA S
 * 4 - ANTARCTICA
 * 5 - ASIA
 * 6 - AUSTRALIA
 * 7 - EUROPA
 * */

int main() {
    testsStack();
    testDynamicArray();
    testCountry();
    testController();
    testRepository();



    CountriesRepo *repo = createRepo();
    OperationsStack* undoStack = createStack();
    OperationsStack* redoStack = createStack();
    Controller *ctrl = createController(repo, undoStack, redoStack);

    Country* c1 = createCountry("Maldives", 5, 20000000);
    Country* c2 = createCountry("Latvia", 7, 1200000);
    Country* c3 = createCountry("Afghanistan", 5, 9300000);
    Country* c4 = createCountry("Finland", 7, 1700000);
    Country* c5 = createCountry("Sierra Leone", 1, 5600000);
    Country* c6 = createCountry("Micronesia", 6, 230000);
    Country* c7 = createCountry("Jordan", 5, 5400000);
    Country* c8 = createCountry("Puerto Rico", 2, 1700000);
    Country* c9 = createCountry("Bahamas", 3, 3900000);
//    Country* c10 = createCountry("Swaziland", 5, 3200000);

    addCountry(ctrl->repo, c1);
    addCountry(ctrl->repo, c2);
    addCountry(ctrl->repo, c3);
    addCountry(ctrl->repo, c4);
    addCountry(ctrl->repo, c5);
    addCountry(ctrl->repo, c6);
    addCountry(ctrl->repo, c7);
    addCountry(ctrl->repo, c8);
    addCountry(ctrl->repo, c9);
//    addCountry(ctrl->repo, c10);

    while(True){
        printMenu();
        int op = readIntegerNumber(">>>");
        if(op == 1) {
            Country *c = readCountryData();
            if (findPosition(ctrl->repo, c->name) != -1)
                printf("This country already exists!\n");
            else {
                addCountryController(ctrl, c->name, c->continent, c->population);
            }
            destroyCountry(c);
        }
        else if(op == 2) {
            char *message = (char*)malloc(100* sizeof(char));
            strcpy(message, "Enter a name to delete that country: ");
            char* name = (char*)malloc(15* sizeof(char));
            readString(message, name);
            if (findPosition(ctrl->repo, name) == -1)
                printf("Error deleting the country\n");
            else {
                deleteCountryController(ctrl, name);
                //deleteCountry(ctrl->repo, name);
            }
            free(name);
            free(message);
        }
        else if(op == 3) {
            char *message = (char*)malloc(100* sizeof(char));
            strcpy(message, "Enter a name to update that country: ");
            char* name = (char*)malloc(15* sizeof(char));
            readString(message, name);
            int pop = -1;
            printf("Enter a new population: ");
            scanf("%d", &pop);
            int pos = findPosition(ctrl->repo, name);
            if (pos == -1)
                printf("Error modifying the country\n");
            else {
                modifyCountryController(ctrl, pos, pop);
            }
            free(name);
            free(message);
        }
        else if(op == 4) {
            char *message = (char*)malloc(100* sizeof(char));
            strcpy(message, "Enter a string to display the countries list which contain a given string, sorted ascending by continent.: ");
            char* name = (char*)malloc(15* sizeof(char));
            readString(message, name);
            listAll(ctrl->repo, name);
            free(name);
            free(message);
        }
        else if(op == 5) {
            char *message = (char*)malloc(300* sizeof(char));
            strcpy(message, "Enter a string to filter the countries list by continent:\n"
                    " * 1 - AFRICA N\n"
                    " * 2 - AMERICA S\n"
                    " * 3 - AMERICA N\n"
                    " * 4 - ANTARCTICA\n"
                    " * 5 - ASIA\n"
                    " * 6 - AUSTRALIA\n"
                    " * 7 - EUROPA\n");

            int n = 0;
            int pop = 0;
            n = readIntegerNumber(message);
            if (n != 0) {
                strcpy(message, "Enter a minimum population for filtering: ");
                pop = readIntegerNumber(message);
            }
            listAllByContinent(ctrl->repo, n, pop);
            free(message);
        }
        else if(op == 6) {
            undo(ctrl);
            printf("6\n");
        }
        else if(op == 7) {
            redo(ctrl);
            printf("7\n");
        }
        else if(op == 8) {
            printf("exit\n");

            break;
        }
        else {
            printf("No such option");
        }
    }
//
//    destroyRepo(repo);
    destroyController(ctrl);
    destroyStack(undoStack);
    destroyStack(redoStack);

    destroyCountry(c1);
    destroyCountry(c2);
    destroyCountry(c3);
    destroyCountry(c4);
    destroyCountry(c5);
    destroyCountry(c6);
    destroyCountry(c7);
    destroyCountry(c8);
    destroyCountry(c9);

}