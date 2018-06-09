#include <iostream>
#include "../headers/BinaryTree.h"

BinaryTree::BinaryTree(TNode *node) {
    this->rootNode = new TNode(node->info);
}

BinaryTree::BinaryTree() {
    this->rootNode = new TNode();
}

void BinaryTree::initLeaf(TInfo *info) {
    this->rootNode = new TNode();
    this->rootNode->info = info;
}

void BinaryTree::initTree(TInfo *info, BinaryTree *left, BinaryTree *right) {
    this->rootNode = new TNode(info);
    this->rootNode->left = left->rootNode;
    this->rootNode->right = right->rootNode;
}

void BinaryTree::insertLeftSubtree(BinaryTree *left) {
    this->rootNode->left = left->rootNode;
}

void BinaryTree::insertRightSubtree(BinaryTree *right) {
    this->rootNode->right = right->rootNode;
}

TInfo * BinaryTree::root() {
    return this->rootNode->info;
}

TNode *BinaryTree::left() {
    return this->rootNode->left;
}

TNode *BinaryTree::right() {
    return this->rootNode->right;
}

bool BinaryTree::isEmpty() {
    return this->rootNode->info == nullptr;
}

PreorderIterator BinaryTree::iterator() {
    PreorderIterator iterator = PreorderIterator();
    iterator.init(this);

    return iterator;
}

BinaryTree::~BinaryTree() {
    delete(this->rootNode);
}