//
// Created by mgabi on 06.04.2018.
//

#include <iostream>
#include "headers/CoverageTests.h"
#include "headers/Tutorial.h"
#include "headers/CSVRepo.h"

void CoverageTests::startTesting() {
    this->testTutorial();
    this->testDuration();
    this->testCSVRepo();
    cout << "ALL TESTS PASSED !!!\n\n";
}

void CoverageTests::testTutorial() {
    Tutorial *t = new Tutorial("title1", "presenter1", "www.youtube.com/1", Duration{2, 30}, 20);
    assert(t->getTitle() == "title1");
    assert(t->getPresenter() == "presenter1");
    assert(t->getRefLink() == "www.youtube.com/1");
    assert(t->getDuration().getMinutes() == 2);
    assert(t->getDuration().getSeconds() == 30);
    assert(t->getLikes() == 20);
}

void CoverageTests::testDuration() {
    Duration *d = new Duration(2, 30);
    assert(d->getMinutes() == 2);
    assert(d->getSeconds() == 30);
}

void CoverageTests::testCSVRepo() {
    CSVRepo *repo = new CSVRepo();
    Tutorial t{"Title1", "Pres1", "www.youtube.com", Duration{1, 30}, 20};
    Tutorial t2{"Title2", "Pres2", "www.youtube.com", Duration{2, 32}, 30};
    repo->addTutorialToRepo(t);
    repo->addTutorialToRepo(t2);
    assert(t == *repo->getTutorial(0));

    repo->removeTutorial("Title1", "Pres1");
    assert(!(t == *repo->getTutorial(0)));

    Tutorial t3{"Title2", "Pres2", "www.youtube.com/333", Duration{3, 25}, 1000};
    repo->updateTutorial(t3);
    assert(t3 == *repo->getTutorial(0));
}
