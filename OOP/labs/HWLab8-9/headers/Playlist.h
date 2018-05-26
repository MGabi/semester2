//
// Created by mgabi on 10.04.2018.
//
#pragma once

#include <vector>
#include "Tutorial.h"

using namespace std;

class Playlist {
private:
    string playlistFile;
    vector<Tutorial*> playlist;
public:

    explicit Playlist(const string& playlistFile);

    void loadPlaylist();
    void savePlaylist();

    vector<Tutorial *> getUserWatchlist();

    bool addTutorialToPlaylist(Tutorial t);

    void openPlaylistFile();
};
