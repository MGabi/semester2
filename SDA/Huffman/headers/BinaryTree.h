#pragma once

#include "PreorderIterator.h"

struct TInfo{
    char data;
    int freq;
    TInfo(char data, int freq){
        this->data = data;
        this->freq = freq;
    }
};

struct TNode{
    TInfo *info;
    TNode *left, *right;

    TNode(){
        info = nullptr;
        left = nullptr;
        right = nullptr;
    }

    explicit TNode(TInfo *info){
        this->left = nullptr;
        this->right = nullptr;
        this->info = info;
    }
};

class PreorderIterator;

class BinaryTree {
public:
    TNode *rootNode;
public:
    BinaryTree();
    ~BinaryTree();
    explicit BinaryTree(TNode *node);
    void initLeaf(TInfo *info);
    void initTree(TInfo *info, BinaryTree *left, BinaryTree *right);
    void insertLeftSubtree(BinaryTree *left);
    void insertRightSubtree(BinaryTree *right);
    TInfo * root();
    TNode* left();
    TNode* right();
    bool isEmpty();
    PreorderIterator iterator();
};
