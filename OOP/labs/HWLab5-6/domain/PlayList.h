#pragma once
#include "DynamicVector.h"

class PlayList {
private:
	DynamicVector tutorials;
	int current;

public:
	PlayList();

	// Adds a song to the playlist.
	void add(const Tutorial& tutorial);

	Tutorial get(int i);

	int size();

    void remove(Tutorial tutorial);
};

