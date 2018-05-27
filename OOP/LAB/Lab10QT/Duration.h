//
// Created by mgabi on 09.04.2018.
//
#include <iostream>
#pragma once
using namespace std;
class Duration {
private:
    int minutes;
    int seconds;
public:
    int getMinutes() const;

    void setMinutes(int minutes);

    int getSeconds() const;

    void setSeconds(int seconds);

    string toString()const;

    friend ostream &operator<<(ostream &os, const Duration &duration);


public:
    Duration() = default;
    Duration(int minutes, int seconds);
};
