#pragma once
#include "../service/Controller.h"

class UI
{
private:
	Controller ctrl;

public:
	explicit UI(const Controller& c) : ctrl(c) {}

	void run();

private:
	static void printMenu();
	static void printAdministratorMenu();
	static void printUserMenu();
	void addTutorialToRepo();
	void deleteTutorialFromRepo();
	void updateTutorialFromRepo();
	void displayAllTutorialsFromRepo();
	void addTutorialToPlaylist();

    void showAllVideosByPresenter();

	void showPlaylist();

	void startPlaylist();
};

