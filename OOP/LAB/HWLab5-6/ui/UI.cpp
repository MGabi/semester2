#include "UI.h"
#include <string>
#include <iostream>

using namespace std;

void UI::printMenu() {
	cout << endl;
	cout << "1. Administrator mode"<<endl;
	cout << "2. User mode" << endl;
	cout << "0. Exit." << endl;
}

void UI::printAdministratorMenu() {
	cout << "Available commands:" << endl;
	cout << "\t1. Add a tutorial" << endl;
	cout << "\t2. Delete a tutorial" << endl;
	cout << "\t3. Update a tutorial" << endl;
	cout << "\t4. List all tutorials" << endl;
	cout << "\t0. EXIT" << endl;
}

void UI::printUserMenu() {
	cout << "Available commands:" << endl;
	cout << "\t1. Add a video to your playlist" << endl;
	cout << "\t3. Delete a tutorial from your list" << endl;
	cout << "\t4. Next." << endl;
	cout << "\t0. Back." << endl;
}

void UI::addTutorialToRepo() {
	cout << "Enter the presenter: ";
	std::string presenter;
	getline(cin, presenter);
	cout << "Enter the title: ";
	std::string title;
	getline(cin, title);
	int seconds = 0;
	cout << "Enter the duration: " << endl;
	cout << "\tSeconds: ";
	cin >> seconds;
	cin.ignore();
	int likes = 0;
	cout << "Enter the number of likes";
	cin >> likes;
	cin.ignore();
	cout << "Youtube link: ";
	std::string refLink;
	getline(cin, refLink);

	this->ctrl.addTutorialToRepo(presenter, title, seconds, likes, refLink);
}


void UI::deleteTutorialFromRepo() {
	cout << "Enter tutorial title: ";
	std::string title;
	getline(cin, title);
	cout << "Enter tutorial presenter: ";
	std::string presenter;
	getline(cin, presenter);
	this->ctrl.deleteTutorialFromRepo(title, presenter);
	cout << "delete";
}

void UI::updateTutorialFromRepo() {
	cout << "Enter the presenter: ";
	std::string presenter;
	getline(cin, presenter);
	cout << "Enter the title: ";
	std::string title;
	getline(cin, title);
	int seconds = 0;
	cout << "Enter the duration: " << endl;
	cout << "\tSeconds: ";
	cin >> seconds;
	cin.ignore();
	int likes = 0;
	cout << "Enter the number of likes";
	cin >> likes;
	cin.ignore();
	cout << "Youtube link: ";
	std::string refLink;
	getline(cin, refLink);

	this->ctrl.updateTutorialFromRepo(title, presenter, refLink, seconds, likes);
}

void UI::displayAllTutorialsFromRepo() {
	DynamicVector v = this->ctrl.getRepo().getTutorials();
	Tutorial* tutorials = v.getAllElems();
	if (tutorials == NULL)
		return;

	if (v.getSize() == 0) {
		cout << "There are no tutorials available!\n";
		return;
	}

	for (int i = 0; i < v.getSize(); i++) {
		Tutorial t = tutorials[i];
		int d = t.getDuration();
		cout << t.getPresenter()
			 << " - "
			 << t.getTitle()
			 << "; "
			 << t.getDuration()
			 << " seconds"
			 << endl;
	}
}

void UI::addTutorialToPlaylist() {
	cout << "Enter the presenter: ";
	std::string presenter;
	getline(cin, presenter);
	cout << "Enter the title: ";
	std::string title;
	getline(cin, title);

	Tutorial s = this->ctrl.getRepo().findTutorialByPresenterAndTitle(presenter, title);
	if (s.getPresenter() == "" && s.getTitle() == "") {
		cout << "There are no tutorial with given presenter and title.\n"
				"Aborting operation!" << endl;
		return;
	}

	this->ctrl.addTutorialToPlaylist(s);
}

void UI::addAllTutorialsByPresenterToPlaylist() {
	cout << "Enter the artist: ";
	std::string artist;
	getline(cin, artist);

	this->ctrl.addAllTutorialsByPresenterToPlaylist(artist);
}

void UI::run() {

	while (true)
	{
		UI::printMenu();
		int command{ 0 };
		cout << "Choose an operating mode: ";
		cin >> command;
		cin.ignore();

		if (command == 0)
			break;
		else if (command == 1) {
			// administrator mode
			while (true)
			{
				UI::printAdministratorMenu();
				int commandRepo{0};
				cout << ">>> ";
				cin >> commandRepo;
				cin.ignore();
				if (commandRepo == 0)
					break;
				switch (commandRepo) {
					case 1:
						this->addTutorialToRepo();
						break;
					case 2:
						this->deleteTutorialFromRepo();
						break;
					case 3:
						this->updateTutorialFromRepo();
						break;
					case 4:
						this->displayAllTutorialsFromRepo();
						break;
					case 5:
						exit(0);
					default:
						break;
				}
			}			
		}else if (command == 2) {
			//user part
			while (true)
			{
				UI::printUserMenu();
				int commandPlaylist{0};
				cout << "Input the command: ";
				cin >> commandPlaylist;
				cin.ignore();
				if (commandPlaylist == 0)
					break;
				switch (commandPlaylist) {
					case 1:
						this->addTutorialToPlaylist();
						break;
					case 2:
						this->addAllTutorialsByPresenterToPlaylist();
						break;
					case 3: {
						if (this->ctrl.getPlaylist().isEmpty()) {
							cout << "Nothing to play, the playlist is empty." << endl;
							continue;
						}
						this->ctrl.startPlaylist();
						Tutorial s = this->ctrl.getPlaylist().getCurrentTutorial();
						cout << "Now playing: " << s.getPresenter() << " - " << s.getTitle() << endl;
						break;
					}
					case 4: {
						if (this->ctrl.getPlaylist().isEmpty())
						{
							cout << "Nothing to play, the playlist is empty." << endl;
							continue;
						}
						this->ctrl.nextTutorialPlaylist();
						Tutorial s = this->ctrl.getPlaylist().getCurrentTutorial();
						cout << "Now playing: " << s.getPresenter() << " - " << s.getTitle() << endl;
						break;
					}
				}
			}
		}else{
			continue;
		}
	}
}
