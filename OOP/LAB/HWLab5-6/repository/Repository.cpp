#include "Repository.h"
#include <string>

using namespace std;

void Repository::addTutorial(const Tutorial &s)
{
	this->tutorials.add(s);
}

Tutorial Repository::findTutorialByPresenterAndTitle(const std::string &presenter, const std::string &title)
{
	int position = this->findTutorialPosition(title, presenter);
	if (position == -1)
		return Tutorial{};

	return this->tutorials.getAllElems()[position];
}

int Repository::removeTutorial(std::string title, std::string presenter) {
	int position = this->findTutorialPosition(title, presenter);
	if (position == -1)
		return -1;

	this->tutorials.remove(position);
}

void Repository::updateTutorial(std::string title,
								std::string presenter,
								std::string refLink,
								int duration,
								int likes) {
	int pos = this->findTutorialPosition(title, presenter);
	if (pos == -1)
		return;

	this->tutorials.update(pos, Tutorial{title, presenter, refLink, duration, likes});

}

int Repository::findTutorialPosition(std::string title, std::string presenter) {
	Tutorial* songsInDynamicVector = this->tutorials.getAllElems();
	if (songsInDynamicVector == NULL)
		return -1;

	for (int i = 0; i < this->tutorials.getSize(); i++) {
		Tutorial t = songsInDynamicVector[i];
		if (t.getPresenter() == presenter && t.getTitle() == title) {
			return i;
		}
	}
	return -1;
}
