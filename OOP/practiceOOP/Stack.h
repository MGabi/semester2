//
// Created by mgabi on 18.06.2018.
//

#ifndef PRACTICEOOP_STACK_H
#define PRACTICEOOP_STACK_H

#include <vector>
#include <stdexcept>

template <typename T>
class Stack {
private:
    std::vector<T> s;
    int capacity = -1;
public:
    explicit Stack(int capacity);
    Stack<T>& operator+(const T& elem);
    Stack<T>& operator=(const Stack<T> &elem);
    T pop();
    int getMaxCapacity();

};

template<typename T>
Stack<T>::Stack(int capacity) {
    this->capacity = capacity;
    this->s.reserve(capacity);
}

template<typename T>
Stack<T>& Stack<T>::operator+(const T& elem) {
    if (this->s.size() == this->capacity)
        throw std::runtime_error("Stack is full!");
    this->s.push_back(elem);
    return *this;
}

template<typename T>
T Stack<T>::pop() {
    T elem = s.back();
    s.pop_back();
    return elem;
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T> &elem) {
    this->s = elem.s;
    return *this;
}

template<typename T>
int Stack<T>::getMaxCapacity() {
    return this->capacity;
}

#endif //PRACTICEOOP_STACK_H
