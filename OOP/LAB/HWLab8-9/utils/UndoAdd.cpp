//
// Created by mgabi on 24.04.2018.
//

#include "../headers/UndoAdd.h"

int UndoAdd::executeUndo() {
    this->repo.removeTutorial(this->tutorial.getTitle(), this->tutorial.getPresenter());
}
