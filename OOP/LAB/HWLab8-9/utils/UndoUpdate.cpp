//
// Created by mgabi on 24.04.2018.
//

#include "../headers/UndoUpdate.h"

int UndoUpdate::executeUndo() {
    this->repo.updateTutorial(this->tutorial);
}
