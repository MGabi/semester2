#include <iostream>
#include "repository/Repository.h"
#include "service/Controller.h"
#include "ui/UI.h"

int main() {
    Repository repository{};

    Tutorial t1{"Title1", "Presenter1", "www.youtube.com", 23, 20};
    Tutorial t2{"Title2", "Presenter2", "www.youtube.com", 40, 10};
    Tutorial t3{"Title3", "Presenter3", "www.youtube.com", 50, 25};
    Tutorial t4{"Title4", "Presenter4", "www.youtube.com", 60, 34};
    Tutorial t5{"Title5", "Presenter5", "www.youtube.com", 42, 21};

    repository.addTutorial(t1);
    repository.addTutorial(t2);
    repository.addTutorial(t3);
    repository.addTutorial(t4);
    repository.addTutorial(t5);
    Controller controller{repository};
    UI ui{controller};
    ui.run();

    return 0;

}