//
// Created by mgabi on 09.04.2018.
//

#include "../headers/UI.h"
#include "../headers/Validators.h"

UI::UI(Controller *ctrl) {
    this->ctrl = ctrl;
}

void UI::start() {
    this->printStartMenu();
    int op = 1;
    this->readOption(op, 2);
    switch (op){
        //Administrator mode
        case 1:
            this->startAdministratorMode();
            break;
        //User mode
        case 2:
            this->startUserMode();
            break;
        default:
            cout << "Something went wrong.\nThe program will close gracefully.";
            return;
    }

}

void UI::printStartMenu() {
    cout << "How do you want to use the program?" << endl;
    cout << "\t1. As Administrator" << endl;
    cout << "\t2. As User" << endl;
}

void UI::printAdministratorMenu() {
    cout << "Available commands:" << endl;
    cout << "\t1. Add a tutorial" << endl;
    cout << "\t2. Delete a tutorial" << endl;
    cout << "\t3. Update a tutorial" << endl;
    cout << "\t4. List all tutorials" << endl;
    cout << "\t5. Print menu again" << endl;
    cout << "\t6. Exit" << endl;
}

void UI::printUserMenu() {
    cout << "Available commands:" << endl;
    cout << "\t1. See all the videos having a given presenter" << endl;
    cout << "\t2. See your playlist" << endl;
    cout << "\t3. Start your playlist" << endl;
    cout << "\t4. Exit" << endl;
}

void UI::readOption(int &op, int maxOp) {
    try {
        while (true){
            cout << ">>> ";
            cin >> op;
            if (Validators::isOptionValid(op, maxOp))
                break;
        }
    }catch (int ex){
        op = -1;
        cout << "Exception nr. " << ex << " raised during runtime" << endl;
    }
}

void UI::startAdministratorMode() {
    int op;
    this->printAdministratorMenu();
    while(true){
        this->readOption(op, 5);
        switch (op){
            case 1:{
                Tutorial t{};
                readTutorialData(t);
                if(Validators::validateTutorial(t))
                    ctrl->addTutorialToRepo(t);
                else
                    cout << "Error adding this tutorial to Repo!" << endl;
                break;
            }case 2:{
                string title;
                string presenter;
                readTitleAndPresenter(&title, &presenter);
                if (ctrl->deleteTutorial(title, presenter))
                    cout << "Tutorial with title: " << title
                         << "\nand presenter: " << presenter
                         << " was deleted!" << endl;
                else
                    cout << "Error when deleting requested tutorial!" << endl;
                break;
            }case 3:{
                cout << "Enter the name and presenter for the tutorial\nyou want to update and the new details about it: \n";
                Tutorial t{};
                this->readTutorialData(t);
                if(Validators::validateTutorial(t)){
                    if(ctrl->updateTutorial(t))
                        cout << "Tutorial with title: " << t.getTitle()
                             << "\nand presenter: " << t.getPresenter()
                             << " was updated!" << endl;
                    else
                        cout << "Tutorial with title: " << t.getTitle()
                             << "\nand presenter: " << t.getPresenter()
                             << " is not present in the list!" << endl;
                } else
                    cout << "Something's wrong with tutorial's data!" << endl;
                break;
            }case 4:{
                cout << "Currently available tutorials are: " << endl;
                for ( auto tutorial: ctrl->getAllTutorials() )
                    cout << *tutorial << endl;
                break;
            }case 5:{
                this->printAdministratorMenu();
                break;
            }case 6:{
                cout << "The administrator mode is now closed!";
                return;
            }
            default:
                cout << "Something went wrong.\nThe program will close gracefully." << endl;
                return;
        }
    }
}

void UI::startUserMode() {

}

void UI::readTutorialData(Tutorial &tutorial) {
    cout << "Enter the title: ";
    string title;
    cin.ignore();
    getline(cin, title);

    cout << "Enter the presenter: ";
    string presenter;
    getline(cin, presenter);

    cout << "Youtube link: ";
    string refLink;
    getline(cin, refLink);

    int seconds = 0;
    int minutes = 0;
    cout << "Enter the duration: " << endl;
    cout << "\tMinutes: ";
    cin >> minutes;
    cin.ignore();
    cout << "\tSeconds: ";
    cin >> seconds;
    cin.ignore();

    int likes = 0;
    cout << "Enter the number of likes: ";
    cin >> likes;
    cin.ignore();

    tutorial.setPresenter(presenter);
    tutorial.setTitle(title);
    tutorial.setRefLink(refLink);
    tutorial.setDuration(Duration{minutes, seconds});
    tutorial.setLikes(likes);
}

void UI::readTitleAndPresenter(string *title, string *presenter) {
    cout << "Enter the title: ";
    cin.ignore();
    getline(cin, *title);

    cout << "Enter the presenter: ";
    getline(cin, *presenter);
}
