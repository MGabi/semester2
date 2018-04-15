//
// Created by mgabi on 09.04.2018.
//

#include <iostream>
#include "../../headers/Tutorial.h"
#include <fstream>

Tutorial::Tutorial(string title, string presenter, string refLink, Duration duration, int like) {
    this->title = title;
    this->presenter = presenter;
    this->refLink = refLink;
    this->duration = duration;
    this->likes = like;
}

ostream &operator<<(ostream &os, const Tutorial &tutorial) {
    os << "Title:     " << tutorial.getTitle() << endl;
    os << "Presenter: " << tutorial.getPresenter() << endl;
    os << "\tlink:  " << tutorial.getRefLink() << endl;
    os << "\tlikes: " << tutorial.getLikes() << endl;
    os << "\tduration: " << endl << tutorial.getDuration() << endl;

    return os;
}

ifstream &operator>>(ifstream &in, Tutorial &tutorial) {
    string title;
    string presenter;
    string refLink;
    string duration;
    string likes;

    getline(in, title, ';');
    getline(in, presenter, ';');
    getline(in, refLink, ';');
    getline(in, duration, ';');
    getline(in, likes, '\n');

    tutorial.title = title;
    tutorial.presenter = presenter;
    tutorial.refLink = refLink;

    auto pos = duration.find(':');

    int minutes = atoi(duration.substr(0, pos).c_str());
    int seconds = atoi(duration.substr(pos+1, duration.size()-1).c_str());
    int lks = atoi(likes.c_str());

    tutorial.duration.setMinutes(minutes);
    tutorial.duration.setSeconds(seconds);
    tutorial.likes = lks;

    return in;
}

Tutorial::Tutorial(const Tutorial &t) {

    this->title = string(t.getTitle());
    this->presenter = string(t.getPresenter());
    this->refLink = string(t.getRefLink());
    this->duration = t.getDuration();
    this->likes = t.getLikes();
}

bool Tutorial::operator==(const Tutorial &t) {
    return t.getTitle() == this->getTitle() &&
           t.getPresenter() == this->getPresenter() &&
           t.getRefLink() == this->getRefLink() &&
           t.getDuration().getMinutes() == this->getDuration().getMinutes() &&
           t.getDuration().getSeconds() == this->getDuration().getSeconds() &&
           t.getLikes() == this->getLikes();
}

Tutorial::~Tutorial() {

}

void Tutorial::play() {
    string cmd{"google-chrome-stable "};
    cmd.append(this->getRefLink());
    system(cmd.c_str());
}





