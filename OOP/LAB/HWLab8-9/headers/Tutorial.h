//
// Created by mgabi on 09.04.2018.
//
#pragma once

#include <string>
#include "Duration.h"

using namespace std;
class Tutorial {
public:
    Tutorial() = default;
    Tutorial(string title, string presenter, string refLink, Duration duration, int like);
    Tutorial(const Tutorial &t);

    const string &getTitle() const {
        return title;
    }

    void setTitle(const string &title) {
        this->title = title;
    }

    const string &getPresenter() const {
        return presenter;
    }

    void setPresenter(const string &presenter) {
        this->presenter = presenter;
    }

    const string &getRefLink() const {
        return refLink;
    }

    void setRefLink(const string &refLink) {
        this->refLink = refLink;
    }

    const Duration &getDuration() const {
        return duration;
    }

    void setDuration(const Duration &duration) {
        this->duration = duration;
    }

    int getLikes() const {
        return likes;
    }

    void setLikes(int likes) {
        this->likes = likes;
    }

    bool operator==(const Tutorial&t);

    friend ifstream &operator>>(ifstream &in, Tutorial &tutorial);
    friend ostream &operator<<(ostream &os, const Tutorial &tutorial);

private:
    string title;
    string presenter;
    string refLink;
    Duration duration;
    int likes;
};
