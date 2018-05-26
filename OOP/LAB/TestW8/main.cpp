#include <iostream>
#include "headers/UI.h"
#include "headers/Controller.h"
#include "headers/RepoMemory.h"
#include <string>
#include <cassert>
using namespace std;

void testAll();

int main() {
    RepoMemory *repo = new RepoMemory();
    Controller *ctrl = new Controller(repo);
    UI *ui = new UI{ctrl};

    //ui->runUI();
    testAll();
    delete repo;
    delete ctrl;
    delete ui;
}

void testAll() {
    RepoMemory *repo = new RepoMemory();
    Controller *ctrl = new Controller(repo);
    MemoryAllocation m{"d", 1, "v1", 20, false};
    MemoryAllocation m2{"s", 1, "v2", 30, false};
    ctrl->addMemoryToRepo(m);
    ctrl->addMemoryToRepo(m2);


    assert(repo->getAllDynamic().size() == 1);
    assert(repo->getAllStatic().size() == 1);

    //repo->markMemoryDynamic("v1");
    //repo->markMemoryStatic("v2");
    //ctrl->markMemoryStatic("v2");
    //ctrl->markMemoryDynamic("v1");


    ctrl->markMemory("v1");
    ctrl->markMemory("v2");

    assert(repo->getAllDynamic()[0].isUsed());
    assert(repo->getAllStatic()[0].isUsed());

    repo->removeDynamic("v1");
    repo->removeStatic("v2");


    assert(repo->getAllStatic().size() == 0);
    assert(repo->getAllDynamic().size() == 0);


}