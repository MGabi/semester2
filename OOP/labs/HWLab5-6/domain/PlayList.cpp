#include "PlayList.h"


PlayList::PlayList() {
	this->current = 0;
}

void PlayList::add(const Tutorial& tutorial) {
	this->tutorials.add(tutorial);
}

int PlayList::size() {
	return this->tutorials.getSize();
}

Tutorial PlayList::get(int i) {
	if (i >= 0 && i < this->size())
		return this->tutorials.getAllElems()[i];
	return Tutorial{};
}

void PlayList::remove(Tutorial tutorial) {
	for (int i = 0; i < this->tutorials.getSize(); ++i) {
		if (this->tutorials.getAllElems()[i].getTitle() == tutorial.getTitle()){
		    this->tutorials.remove(i);
			break;
		}
	}
}
