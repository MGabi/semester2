//
// Created by mgabi on 19.04.2018.
//

#ifndef TESTW8_CONTROLLER_H
#define TESTW8_CONTROLLER_H


#include "RepoMemory.h"

class Controller {
private:
    RepoMemory *repo = nullptr;
public:
    explicit Controller(RepoMemory *repo);

    int addMemoryToRepo(MemoryAllocation allocation);

    int findStaticMemory(const string &label);

    int findDynamicMemory(const string &label);

    void addStaticMemory(MemoryAllocation allocation);

    void addDynamicMemory(MemoryAllocation allocation);

    bool findMemory(const string &label);

    void markMemory(string name);

    void removeMemory(string basic_string);

    void removeLargest();

    void markMemoryStatic(string basic_string);

    void markMemoryDynamic(string basic_string);
};


#endif //TESTW8_CONTROLLER_H
