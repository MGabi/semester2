//
// Created by mgabi on 24.04.2018.
//

#include "../headers/UndoRemove.h"

int UndoRemove::executeUndo() {
    this->repo.addTutorialToRepo(this->tutorial);
}
