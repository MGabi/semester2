#pragma once

#include <stack>
#include <vector>
#include "BinaryTree.h"
class BinaryTree;
struct TNode;
struct TInfo;

class PreorderIterator {
private:
    BinaryTree *bt;
    std::stack<TNode*> nodeStack;
    TNode* currentNode;

public:
    PreorderIterator();
    void init(BinaryTree *bt);
    TInfo* getCurrent();
    bool valid();
    void next();
};
