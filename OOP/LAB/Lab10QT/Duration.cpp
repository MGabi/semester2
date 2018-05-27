//
// Created by mgabi on 09.04.2018.
//

#include "Duration.h"

Duration::Duration(int minutes, int seconds) {
    this->minutes = minutes;
    this->seconds = seconds;
}

int Duration::getMinutes() const {
    return minutes;
}

void Duration::setMinutes(int minutes) {
    Duration::minutes = minutes;
}

int Duration::getSeconds() const {
    return seconds;
}

void Duration::setSeconds(int seconds) {
    Duration::seconds = seconds;
}

ostream &operator<<(ostream &os, const Duration &duration) {
    os << "\t\tMinutes: " << duration.getMinutes() << endl;
    os << "\t\tSeconds: " << duration.getSeconds() << endl;

    return os;
}

string Duration::toString() const {
    return string{to_string(this->minutes).append(":").append(to_string(this->seconds))};
}
