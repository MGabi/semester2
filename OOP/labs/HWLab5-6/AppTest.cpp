//
// Created by mgabi on 05.04.2018.
//

#include "AppTest.h"
#include "domain/DynamicVector.h"
#include "domain/PlayList.h"
#include "repository/Repository.h"
#include "service/Controller.h"
#include <cassert>
#include <iostream>

void AppTest::runAll() {
    this->testDynamicVector();
    this->testTutorial();
    this->testPlaylist();
    this->testRepository();
    this->testController();
}

void AppTest::testDynamicVector() {


    DynamicVector d1{1};
    Tutorial t1{"Pres1", "Presenter1", "refLink1", 1, 1};
    Tutorial t2{"Pres2", "Presenter2", "refLink2", 2, 2};
    Tutorial t3{"Pres3", "Presenter3", "refLink3", 3, 3};
    d1.add(t1);
    d1.add(t2);
    assert(d1.getAllElems()[0] == t1);
    assert(d1.getAllElems()[1] == t2);

    DynamicVector d2 {d1};
    d1 = d1;
    d2 = d1;
    assert(d2.getSize() == 2);
    d2 - t1;
    d2 - t3;
    d2.update(1, t1);
    assert(d2.getAllElems()[1] == t1);
}

void AppTest::testTutorial() {
    Tutorial t1{"Title1", "Presenter1", "refLink1", 1, 1};
    std::string s = t1.toString();
    std::string s2 = "refLink1\nTitle1\nPresenter1\n\n";
    assert(s == s2);
    //t1.play();
}

void AppTest::testPlaylist(){
    PlayList playList{};
    assert(playList.size() == 0);
    Tutorial t1{"Title1", "Presenter1", "refLink1", 1, 1};
    playList.add(t1);
    assert(playList.get(0) == t1);
    assert(playList.get(-1) == Tutorial{});

    playList.remove(t1);
    assert(playList.get(0) == Tutorial{});
}

void AppTest::testRepository(){
    Repository repo{};
    std::string tt1{"Title1"};
    std::string pp1{"Presenter1"};
    Tutorial t1{tt1, pp1, "refLink1", 1, 1};
    repo.addTutorial(t1);
    assert(repo.findTutorialByPresenterAndTitle(pp1, tt1) == t1);
    assert(repo.findTutorialByPresenterAndTitle(tt1, pp1) == Tutorial{});
    assert(repo.removeTutorial("Title1", "Presenter1") == 1);
    assert(repo.removeTutorial("Presenter1", "Presenter1") == -1);
    repo.addTutorial(t1);
    t1 = Tutorial{tt1, pp1, "refLink2", 2, 3};
    repo.updateTutorial(tt1, pp1, "refLink2", 2, 3);
    repo.updateTutorial(pp1, tt1, "refLink2", 2, 3);
    assert(repo.getTutorials().getAllElems()[0] == t1);
    assert(repo.findTutorialPosition(pp1, tt1) == -1);
}

void AppTest::testController(){
    Repository repo{};
    Controller ctrl{repo};
    std::string tt1{"Title1"};
    std::string pp1{"Presenter1"};
    std::string rr1{"refLink1"};
    Tutorial t1{tt1, pp1, "refLink1", 1, 1};
    ctrl.addTutorialToPlaylist(t1);
    ctrl.addTutorialToRepo(pp1, tt1, 2, 3, rr1);
    assert(ctrl.getPlaylist().get(0) == t1);
    ctrl.deleteTutorialFromRepo(tt1, pp1);
    assert(ctrl.getRepo().getTutorials().getSize() == 0);
    ctrl.addTutorialToRepo(pp1, tt1, 2, 3, rr1);
    rr1 = std::string{"refLink2"};
    ctrl.updateTutorialFromRepo(pp1, tt1, rr1, 3, 4);
    ctrl.deleteTutorialFromPlaylist(t1);
    assert(ctrl.getPlaylist().size() == 0);
}

