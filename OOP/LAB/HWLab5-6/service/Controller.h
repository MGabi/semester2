#pragma once

#include <utility>

#include "../repository/Repository.h"
#include "../domain/PlayList.h"

class Controller {

private:
	Repository repo;
	PlayList playList;

public:
	explicit Controller(Repository r) : repo{std::move(r)} {}

	Repository getRepo() const { return repo; }
	PlayList getPlaylist() const { return playList; }

	// Adds a song with the given data to the song repository.
	void addTutorialToRepo(const std::string &presenter,
						   const std::string &title,
						   int duration,
						   int likes,
						   const std::string &refLink);

	// Delete a certain tutorial, given by it's title and presenter
	void deleteTutorialFromRepo(std::string title, std::string presenter);

	void updateTutorialFromRepo(std::string title, std::string presenter, std::string refLink, int duration, int likes);

	/*
		Adds a given song to the current playlist.
		Input: song - Song, the song must belong to the repository.
		Output: the song is added to the playlist.
	*/
	void addTutorialToPlaylist(const Tutorial &tutorial);

	// Adds all the tutorials from the repository, that have the given artist, to the current playlist.
	void addAllTutorialsByPresenterToPlaylist(const std::string &presenter);

	void startPlaylist();
	void nextTutorialPlaylist();

};

