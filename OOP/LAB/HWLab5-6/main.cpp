#include <iostream>
#include "repository/Repository.h"
#include "service/Controller.h"
#include "ui/UI.h"
#include "AppTest.h"

int main() {
//    AppTest appTest{};
//    appTest.runAll();

    Repository repository{};

    Tutorial t1{"Title1", "Presenter1", "www.google.com/1", 23, 20};
    Tutorial t2{"Title2", "Presenter2", "www.google.com/2", 40, 10};
    Tutorial t3{"Title3", "Presenter3", "www.google.com/3", 50, 25};
    Tutorial t4{"Title4", "Presenter1", "www.google.com/4", 60, 34};
    Tutorial t5{"Title5", "Presenter5", "www.google.com/5", 42, 21};
    Tutorial t6{"Title6", "Presenter1", "www.google.com/6", 46, 23};

    repository.addTutorial(t1);
    repository.addTutorial(t2);
    repository.addTutorial(t3);
    repository.addTutorial(t4);
    repository.addTutorial(t5);
    repository.addTutorial(t6);

    Controller controller{repository};
    UI ui{controller};
    ui.run();

    return 0;

}