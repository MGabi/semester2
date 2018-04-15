//
// Created by mgabi on 09.04.2018.
//

#include <utility>
#include "../headers/Controller.h"
#include "../headers/Validators.h"
#include "../headers/Playlist.h"

Controller::Controller(Repo *repo, Playlist *playlist) {
    this->repo = dynamic_cast<CSVRepo*>(repo);
    this->playlist = playlist;
}

void Controller::addTutorialToRepo(Tutorial tutorial) {
    repo->addTutorialToRepo(tutorial);
}

bool Controller::deleteTutorial(string title, string presenter) {
    if (repo->tutorialExists(title, presenter)){
        repo->removeTutorial(title, presenter);
        return true;
    }
    return false;
}

bool Controller::updateTutorial(Tutorial tutorial) {
    if(repo->tutorialExists(tutorial.getTitle(), tutorial.getPresenter())){
        repo->updateTutorial(tutorial);
        return true;
    }
    return false;
}

vector<Tutorial*> Controller::getAllTutorials() {
    return repo->getAllTutorials();
}

vector<Tutorial*> Controller::getTutorialsByPresenter(string presenter) {
    return this->repo->getTutorialsBy("", std::move(presenter));

}

void Controller::addTutorialToPlaylist(Tutorial tutorial) {
    playlist->addTutorialToPlaylist(tutorial);
}

vector<Tutorial *> Controller::getPlaylist() {
    return playlist->getUserWatchlist();
}

void Controller::openPlaylistFile() {
    playlist->openPlaylistFile();

}
