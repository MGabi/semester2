//
// Created by mgabi on 19.04.2018.
//

#include <utility>
#include "../headers/Controller.h"

Controller::Controller(RepoMemory *repo) {
    this->repo = repo;
}

int Controller::addMemoryToRepo(MemoryAllocation allocation) {
    /**
     * Add a new memory to the stack / heap
     * If the memory with this label exists,
     * the function will return -1
     * If the memory is added successfully,
     * it will return 1
     */
    if(this->findMemory(allocation.getLabel())) {
        if (allocation.getType() == "s") {
            this->addStaticMemory(allocation);
        } else {
            this->addDynamicMemory(allocation);
        }
    }
    return -1;
}

int Controller::findStaticMemory(const string &label) {
    /**
     * Searches for a memory label in static memory
     * @return: 1 if a memory with name @label exists
     *          -1 if there's no such memory allocated
     */
    for (auto mem : this->repo->getAllStatic())
        if (mem.getLabel() == label)
            return 1;
    return -1;
}

int Controller::findDynamicMemory(const string &label) {
    /**
     * Searches for a memory label in dynamic
     * @return: 1 if a memory with name @label exists
     *          -1 if there's no such memory allocated
     */
    for (auto mem : this->repo->getAllDynamic())
        if (mem.getLabel() == label)
            return 1;
    return -1;
}

void Controller::addStaticMemory(MemoryAllocation allocation) {
    this->repo->addStatic(std::move(allocation));
}

void Controller::addDynamicMemory(MemoryAllocation allocation) {
    this->repo->addDynamic(allocation);
}

bool Controller::findMemory(const string &label) {
    return this->findStaticMemory(label) == -1 &&
           this->findDynamicMemory(label) == -1;
}

void Controller::markMemory(string name) {
    if(this->findStaticMemory(name) == 1)
        this->markMemoryStatic(name);
    else if(this->findDynamicMemory(name) == 1)
        this->markMemoryDynamic(name);
}

void Controller::removeMemory(string basic_string) {

}

void Controller::removeLargest() {

}

void Controller::markMemoryStatic(string basic_string) {
    this->repo->markMemoryStatic(basic_string);
}

void Controller::markMemoryDynamic(string basic_string) {
    this->repo->markMemoryDynamic(basic_string);
}
