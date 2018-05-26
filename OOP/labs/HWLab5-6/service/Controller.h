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

	void addTutorialToRepo(const std::string &presenter,
						   const std::string &title,
						   int duration,
						   int likes,
						   const std::string &refLink);

	void deleteTutorialFromRepo(std::string title, std::string presenter);

	void updateTutorialFromRepo(std::string title, std::string presenter, std::string refLink, int duration, int likes);
	void addTutorialToPlaylist(const Tutorial &tutorial);

	void deleteTutorialFromPlaylist(Tutorial tutorial);
};

