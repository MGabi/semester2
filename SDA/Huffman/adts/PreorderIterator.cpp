#include "../headers/PreorderIterator.h"
#include <iostream>
PreorderIterator::PreorderIterator() = default;

void PreorderIterator::init(BinaryTree *bt) {
    this->bt = bt;
    this->currentNode = bt->rootNode;
    nodeStack.push(bt->rootNode);
    this->next();
}

TInfo *PreorderIterator::getCurrent() {
    return this->currentNode->info;
}

bool PreorderIterator::valid() {
    return this->currentNode != nullptr;
}

void PreorderIterator::next() {
    if (nodeStack.empty()){
        this->currentNode = nullptr;
        return;
    }
    TNode* node = nodeStack.top();
    nodeStack.pop();
    this->currentNode = node;

    if(node->right != nullptr)
        nodeStack.push(node->right);
    if(node->left != nullptr)
        nodeStack.push(node->left);
}
