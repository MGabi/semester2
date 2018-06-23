#include <iostream>
#include <cassert>
#include <cstring>
#include <deque>
#include "Stack.h"

void testStack();
void testActivity();
class E
{
public:
    E() { std::cout << "E{}"; }
    virtual ~E() { std::cout << "~E()"; }
};
class DE : public E
{
public:
    static int n;
    DE() { n++; }
};
int DE::n = 0;
int fct2(int x)
{
    if (x < 0)
    {
        throw E{};
        std::cout << "number less than 0" << std::endl;
    }
    else if (x == 0)
    {
        throw DE{};
        std::cout << "number equal to 0" << std::endl;
    }
    return x % 10;
}

int main() {
    std::deque<std::string> d;
    d.push_back("A");
    d.push_front("B");
    d.push_back("C");
    d.push_front("D");
    auto itBegin = d.begin();
    auto itEnd = d.end();
    itBegin++;
    itEnd--;
    while (itBegin != itEnd)
    {
        std::cout << *itBegin << " ";
        itBegin++;
    }
    return 0;
}


void testStack()
{
    Stack<std::string> s{ 2 };
    assert(s.getMaxCapacity() == 2);
    try {
        s = s + "examination";
        s = s + "oop";
        s = s + "test";
    }
    catch (std::exception& e) {
        assert(strcmp(e.what(), "Stack is full!") == 0);
    }
    assert(s.pop() == "oop");
    assert(s.pop() == "examination");
}