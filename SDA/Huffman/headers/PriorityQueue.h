#pragma once

#include <cstdlib>
#include "BinaryTree.h"

typedef BinaryTree TElem;
struct TRelation{
    bool operator()(const TElem *a, const TElem *b){
        return a->rootNode->info->freq > b->rootNode->info->freq;
    }
};

class PriorityQueue {
private:
    TElem **elems;
    int capacity;
    TRelation rel;
    int len;

public:
    PriorityQueue();
    ~PriorityQueue();
    void push(TElem* elem);
    int size();
    TElem * pop();
    TElem* top();
    bool isEmpty();
};