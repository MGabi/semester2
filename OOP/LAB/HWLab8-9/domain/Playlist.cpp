//
// Created by mgabi on 10.04.2018.
//

#include <fstream>
#include "../headers/Playlist.h"

vector<Tutorial*> Playlist::getUserWatchlist() {
    return this->playlist;
}

bool Playlist::addTutorialToPlaylist(Tutorial t) {
    this->playlist.push_back(new Tutorial{t});
    this->savePlaylist();
}

void Playlist::openPlaylistFile() {
    system("gedit ../playlist.csv");
}

void Playlist::loadPlaylist() {
    ifstream in(this->playlistFile);
    string line;
    Tutorial t{};
    this->playlist.clear();
    while(in >> t){
        this->playlist.push_back(new Tutorial(t));
    }
    in.close();
}

void Playlist::savePlaylist() {
    ofstream out(this->playlistFile, ios::out | ios::trunc);

    for(auto tutorial: this->playlist){
        out << tutorial->getTitle() << ";" << tutorial->getPresenter() << ";" << tutorial->getRefLink() << ";" << tutorial->getDuration().toString() << ";" << tutorial->getLikes() << endl;
    }
    out.close();
}

Playlist::Playlist(const string &playlistFile) {
    this->playlistFile = playlistFile;
    this->loadPlaylist();
}
