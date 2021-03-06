//
// Created by mgabi on 09.04.2018.
//
#include "Validators.h"

bool Validators::isOptionValid(int option, int maxOp) {
    return option >= 1 && option <= maxOp;
}

bool Validators::validateTutorial(Tutorial tutorial) {
    return !tutorial.getTitle().empty() &&
           !tutorial.getPresenter().empty() &&
           !tutorial.getRefLink().empty() &&
           !tutorial.getLikes() >= 0;
}
