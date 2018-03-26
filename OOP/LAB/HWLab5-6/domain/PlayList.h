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

	// Returns the song that is currently playing.
	Tutorial getCurrentTutorial();

	// Starts the playlist with the first tutorial.
	void play();

	// Plays the next song in the playlist.
	void next();

	// Checks if the playlist is empty.
	bool isEmpty();
};

