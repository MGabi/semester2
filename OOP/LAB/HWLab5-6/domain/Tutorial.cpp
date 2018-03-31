//
// Created by mgabi on 26.03.2018.
//
#include <iostream>
#include <cstring>
#include "Tutorial.h"

std::string Tutorial::getTitle() {
    return this->title;
}

std::string Tutorial::getPresenter() {
    return this->presenter;
}

int Tutorial::getDuration() {
    return this->duration;
}

Tutorial::Tutorial(): title(""), presenter(""), refLink(""), duration(0), likes(0) {}

Tutorial::Tutorial(const std::string &title,
                   const std::string &presenter,
                   const std::string &refLink,
                   const int duration,
                   const int likes) {
    this->title = title;
    this->presenter = presenter;
    this->refLink = refLink;
    this->duration = duration;
    this->likes = likes;
}

std::string Tutorial::toString() {
    std::string myString(this->refLink + "\n");
    myString.append(this->title + "\n");
    myString.append(this->presenter + "\n\n");
    return myString;
}

std::string Tutorial::getRefLink() {
    return this->refLink;
}

int Tutorial::getLikes() {
    return this->likes;
}

void Tutorial::play() {
    system("google-chrome-stable http://www.youtube.com");
    std::cout << "Playing: " << this->title;
}

int Tutorial::operator==(const Tutorial t) {
    return this->getTitle().compare(t.getTitle()) == 0 &&
           this->getPresenter().compare(t.getPresenter()) == 0 &&
           this->getRefLink().compare(t.getRefLink()) == 0 &&
           this->getDuration() == t.getDuration() &&
           this->getLikes() == t.getLikes();
}

/*Tutorial::~Tutorial() {
    delete &this->title;
    delete &this->presenter;
    delete &this->refLink;
    delete &this->duration;
    delete &this->likes;
}*/
