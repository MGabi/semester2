#include <cstring>
#include <iostream>
#include "../headers/PriorityQueue.h"

PriorityQueue::PriorityQueue() {
    this->capacity = 10;
    this->len = 0;
    this->elems = new TElem*[this->capacity];
}

void PriorityQueue::push(TElem *elem) {
    if(this->len == this->capacity){
        auto ** newArr = new TElem*[this->capacity*2];
        memcpy(newArr, this->elems, (size_t)this->capacity * sizeof(TElem*));
        this->capacity *= 2;
        delete this->elems;
        this->elems = newArr;
    }

    this->elems[this->len++] = elem;
    int i = this->len-1;

    while(i > 0 && rel.operator()(this->elems[i], this->elems[i-1])){
        TElem* aux = this->elems[i];
        this->elems[i] = this->elems[i-1];
        this->elems[i-1] = aux;
        i--;
    }
}

TElem * PriorityQueue::pop() {
    this->len--;
    return this->elems[this->len+1];
}

TElem *PriorityQueue::top() {
    return this->elems[this->len-1];
}

bool PriorityQueue::isEmpty() {
    return this->len == 0;
}

PriorityQueue::~PriorityQueue(){
    for(int i=0; i<len; i++){
        delete(elems[i]);
    }

    delete(elems);
    this->elems = nullptr;
}

int PriorityQueue::size() {
    return this->len;
}
