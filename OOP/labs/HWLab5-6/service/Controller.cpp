#include "Controller.h"

void Controller::addTutorialToRepo(const std::string &presenter,
								   const std::string &title,
								   int duration,
								   int likes,
								   const std::string &refLink) {
	Tutorial tutorial{ title, presenter, refLink, duration, likes };
	this->repo.addTutorial(tutorial);
}


void Controller::deleteTutorialFromRepo(std::string title, std::string presenter) {
	this->repo.removeTutorial(title, presenter);
}

void Controller::updateTutorialFromRepo(std::string title,
										std::string presenter,
										std::string refLink,
										int duration,
										int likes) {

	this->repo.updateTutorial(title, presenter, refLink, duration, likes);
}

void Controller::addTutorialToPlaylist(const Tutorial &tutorial) {
	this->playList.add(tutorial);
}

void Controller::deleteTutorialFromPlaylist(Tutorial tutorial) {
	this->playList.remove(tutorial);
}
