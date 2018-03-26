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

void Controller::addAllTutorialsByPresenterToPlaylist(const std::string &presenter) {
	// get all the tutorials from the repository
	DynamicVector v = this->repo.getTutorials();
	Tutorial* tutorials = v.getAllElems();
	for (int i = 0; i < v.getSize(); i++)
	{
		Tutorial t = tutorials[i];
		if (t.getPresenter() == presenter)
			this->playList.add(t);
	}
}

void Controller::startPlaylist() {
	this->playList.play();
}

void Controller::nextTutorialPlaylist() {
	this->playList.next();
}