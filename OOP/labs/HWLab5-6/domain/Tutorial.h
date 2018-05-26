//
// Created by mgabi on 26.03.2018.
//
#include <string>
#pragma once

class Tutorial {
public:
    Tutorial();
    Tutorial(const std::string &title, const std::string &presenter, const std::string &refLink, const int duration, const int likes);
    //~Tutorial();
    std::string getTitle();
    std::string getPresenter();
    std::string getRefLink();
    int operator==(Tutorial t);
    int getDuration();
    int getLikes();
    void play();

    std::string toString();

private:
    std::string title;
    std::string presenter;
    std::string refLink;
    int duration;
    int likes;

};