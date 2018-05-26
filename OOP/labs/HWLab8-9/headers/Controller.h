//
// Created by mgabi on 09.04.2018.
//
#pragma once

#include "Repo.h"
#include "CSVRepo.h"
#include "Playlist.h"

class Controller {
private:
    CSVRepo *repo;
    Playlist *playlist;

public:

    explicit Controller(Repo *repo, Playlist *playlist);

    void addTutorialToRepo(Tutorial tutorial);

    bool deleteTutorial(string title, string presenter);

    bool updateTutorial(Tutorial tutorial);

    vector<Tutorial*> getAllTutorials();

    vector<Tutorial *> getTutorialsByPresenter(string presenter);

    void addTutorialToPlaylist(Tutorial tutorial);

    vector<Tutorial *> getPlaylist();

    void openPlaylistFile();

    void undo();
};
