//
// Created by mgabi on 19.04.2018.
//
#include <vector>
#include <string>
#include "MemoryAllocation.h"

using namespace std;
#ifndef TESTW8_REPO_H
#define TESTW8_REPO_H


class RepoMemory {
private:
    vector<MemoryAllocation> staticMemories;
    vector<MemoryAllocation> dynamicMemories;
public:

    vector<MemoryAllocation> getAllStatic();

    vector<MemoryAllocation> getAllDynamic();

    void addStatic(MemoryAllocation allocation);

    void addDynamic(MemoryAllocation allocation);

    bool staticOffsetFree(int offset);

    int fitInsideStatic(int offset, int dataSize);

    void insertStaticOnPosition(MemoryAllocation allocation, int position);

    void insertStaticAtEnd(MemoryAllocation allocation);

    int getLastOffsetStatic();

    bool dynamicOffsetFree(int offset);

    int fitInsideDynamic(int offset, int dataSize);

    void insertDynamicOnPosition(const MemoryAllocation &allocation, int position);

    void insertDynamicAtEnd(MemoryAllocation allocation);

    int getLastOffsetDynamic();

    void removeStatic(string basic_string);

    void removeDynamic(string basic_string);

    void markMemory(string name);

    void markMemoryStatic(string name);

    void markMemoryDynamic(string basic_string);
};


#endif //TESTW8_REPO_H
