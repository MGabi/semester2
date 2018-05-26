#pragma once
#include "../domain/DynamicVector.h"

class Repository
{
private:
	DynamicVector tutorials;

public:
	/*
		Default constructu=or. 
		Initializes an object of type repository.
	*/
	Repository() = default;

	void addTutorial(const Tutorial &s);

	int removeTutorial(std::string title, std::string presenter);

	int findTutorialPosition(std::string title, std::string presenter);

	/*
		Finds a song, by artist and title.
		Input: artist, title - string
		Output: the song that was found, or an "empty" song (all fields empty and duration 0), if nothing was found.
	*/
	Tutorial findTutorialByPresenterAndTitle(const std::string &presenter, const std::string &title);

	DynamicVector getTutorials() const { return tutorials; }

	void updateTutorial(std::string title, std::string presenter, std::string refLink, int duration, int likes);
};