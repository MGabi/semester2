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
	cout << "\t0. Exit" << endl;
}

void UI::printUserMenu() {
	cout << "Available commands:" << endl;
	cout << "\t1. See all the videos having a given presenter" << endl;
	cout << "\t2. See your playlist" << endl;
	cout << "\t3. Start your playlist" << endl;
	cout << "\t0. Exit" << endl;
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

void UI::showAllVideosByPresenter() {
	DynamicVector v = this->ctrl.getRepo().getTutorials();
	Tutorial* tutorials = v.getAllElems();
	if (tutorials == NULL)
		return;

	if (v.getSize() == 0) {
		cout << "There are no tutorials available!\n";
		return;
	}

	cout << " 	enter a presenter: ";
	std::string presenter;
	getline(cin, presenter);

	for (int i = 0; i < v.getSize(); i++) {
		Tutorial t = tutorials[i];
		if (t.getPresenter().compare(presenter) == 0) {
			int d = t.getDuration();
			cout << t.getPresenter()
				 << " - "
				 << t.getTitle()
				 << "; "
				 << t.getDuration()
				 << " seconds"
				 << endl;

			cout << "Like? (y/n)";
			std::string like;
			getline(cin, like);
			if(like.compare("y") == 0) {
				this->ctrl.addTutorialToPlaylist(t);
				cout << "Video added to playlist";
			}else{
				cout << "Not added to playlist";
			}
		}
	}
}

void UI::showPlaylist() {
	for (int i=0; i<ctrl.getPlaylist().size(); i++){
		cout << ctrl.getPlaylist().get(i).toString();
	}

}

void UI::startPlaylist() {
	for (int i=0; i<ctrl.getPlaylist().size(); i++){
		Tutorial t = ctrl.getPlaylist().get(i);
		cout << "Playing: " << t.toString() << endl;
		t.play();
        this->ctrl.deleteTutorialFromPlaylist(t);
		cout << "Play the next one? (y/n) :";
		std::string next;
		getline(cin, next);
		if (next.compare("y") != 0)
			break;

	}
}

void UI::run() {

	while (true)
	{
		UI::printMenu();
		int command{ 0 };
		cout << "Choose an operating mode: ";
		cin >> command;
		cin.ignore();
		//command = 2;
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
			this->ctrl.addTutorialToPlaylist(this->ctrl.getRepo().getTutorials().getAllElems()[0]);
			this->ctrl.addTutorialToPlaylist(this->ctrl.getRepo().getTutorials().getAllElems()[3]);
			this->ctrl.addTutorialToPlaylist(this->ctrl.getRepo().getTutorials().getAllElems()[5]);
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
						this->showAllVideosByPresenter();
						break;
					case 2:
						this->showPlaylist();
						break;
					case 3:
						this->startPlaylist();
				}
			}
		}else{
			continue;
		}
	}
}
