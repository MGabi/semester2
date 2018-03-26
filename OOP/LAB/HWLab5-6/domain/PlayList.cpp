#include "PlayList.h"


PlayList::PlayList() {
	this->current = 0;
}

void PlayList::add(const Tutorial& tutorial) {
	this->tutorials.add(tutorial);
}

Tutorial PlayList::getCurrentTutorial() {
	if (this->current == this->tutorials.getSize())
		this->current = 0;
	Tutorial* elems = this->tutorials.getAllElems();
	if (elems != NULL)
		return elems[this->current];
	return Tutorial{};
}

void PlayList::play() {
	if (this->tutorials.getSize() == 0)
		return;
	this->current = 0;
	Tutorial currentSong = this->getCurrentTutorial();
	currentSong.play();
}

void PlayList::next() {
	if (this->tutorials.getSize() == 0)
		return;
	this->current++;
	Tutorial currentSong = this->getCurrentTutorial();
	currentSong.play();
}

bool PlayList::isEmpty() {
	return this->tutorials.getSize() == 0;
}