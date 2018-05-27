//
// Created by mgabi on 06.04.2018.
//

#include <iostream>
#include <fstream>
#include "CoverageTests.h"
#include "Tutorial.h"
#include "CSVRepo.h"
#include "Playlist.h"
#include "Controller.h"

void CoverageTests::startTesting() {
    this->testTutorial();
    this->testDuration();
    this->testCSVRepoFile();
    this->testController();
    this->testPlaylist();

    cout << "\nALL TESTS PASSED !!!\n\n";
}

void CoverageTests::testTutorial() {
    Tutorial *t = new Tutorial("title1", "presenter1", "www.youtube.com/1", Duration{2, 30}, 20);
    assert(t->getTitle() == "title1");
    assert(t->getPresenter() == "presenter1");
    assert(t->getRefLink() == "www.youtube.com/1");
    assert(t->getDuration().getMinutes() == 2);
    assert(t->getDuration().getSeconds() == 30);
    assert(t->getLikes() == 20);

    t->setTitle("Title2");
    t->setPresenter("Presenter2");
    t->setRefLink("www.yt.com/2");
    t->setDuration(Duration{3, 40});
    t->setLikes(30);

    assert(t->getTitle() == "Title2");
    assert(t->getPresenter() == "Presenter2");
    assert(t->getRefLink() == "www.yt.com/2");
    assert(t->getDuration().getMinutes() == 3);
    assert(t->getDuration().getSeconds() == 40);
    assert(t->getLikes() == 30);
    delete t;
    cout << "Tutorial test PASSED!" << endl;
}

void CoverageTests::testDuration() {
    Duration *d = new Duration(2, 30);
    assert(d->getMinutes() == 2);
    assert(d->getSeconds() == 30);
    d->setMinutes(3);
    d->setSeconds(20);
    assert(d->getMinutes() == 3);
    assert(d->getSeconds() == 20);
    assert(d->toString() == "3:20");
    delete d;
    cout << "Duration test PASSED!" << endl;
}

void CoverageTests::testCSVRepoFile() {
    writeTestFile();
    CSVRepo *repo = new CSVRepo("../repo_csv_test.csv");
    assert(repo->getAllTutorials().size() == 5);
    Tutorial t3{"Test3", "PTest2", "www.yt.c/3", Duration{3, 30}, 30};
    assert(*repo->getTutorial(2) == t3);
    assert(*repo->getTutorial("Test3", "PTest2") == t3);
    assert(repo->getTutorialsBy("", "PTest2").size() == 3);
    assert(repo->getTutorialsBy("Test1", "").size() == 1);
    assert(repo->getTutorialsBy("Test1", "PTest1").size() == 1);
    assert(repo->getTutorialsBy("", "").size() == 0);

    repo->removeTutorial("Test3", "PTest2");
    assert(repo->getTutorial("Test3", "PTest2") == nullptr);

    Tutorial t2{"Test1", "PTest1", "www.youtube.com/333", Duration{3, 25}, 1000};
    repo->updateTutorial(t2);
    assert(repo->getTutorial("Test1", "PTest1")->getRefLink() == "www.youtube.com/333");
    assert(repo->getTutorial("Test1", "PTest1")->getDuration().getMinutes() == 3);
    assert(repo->getTutorial("Test1", "PTest1")->getDuration().getSeconds() == 25);
    assert(repo->getTutorial("Test1", "PTest1")->getLikes() == 1000);

    repo->saveData();
    repo->loadData();
    assert(repo->getAllTutorials().size() == 4);
    cout << "CSVRepo FILE test PASSED!" << endl;
}

void CoverageTests::writeTestFile() {
    ofstream out("../repo_csv_test.csv", ios::out | ios::trunc);
    out << "Test1;PTest1;www.yt.c/1;1:30;10" << endl;
    out << "Test2;PTest2;www.yt.c/2;2:30;20" << endl;
    out << "Test3;PTest2;www.yt.c/3;3:30;30" << endl;
    out << "Test4;PTest2;www.yt.c/4;4:30;40" << endl;
    out << "Test5;PTest5;www.yt.c/5;5:30;50" << endl;
    out.close();
}

void CoverageTests::writePlaylistFile() {
    ofstream out("../playlist_test.csv", ios::out | ios::trunc);
    out << "Test2;PTest2;www.yt.c/2;2:30;20" << endl;
    out << "Test3;PTest2;www.yt.c/3;3:30;30" << endl;
    out << "Test4;PTest2;www.yt.c/4;4:30;40" << endl;
    out.close();
}

void CoverageTests::testController() {
    writeTestFile();
    writePlaylistFile();
    string csvfile{"../repo_csv_test.csv"};
    string csvplaylist{"../playlist_test.csv"};
    auto *repo = new CSVRepo(csvfile);
    auto *playlist = new Playlist(csvplaylist);
    auto *ctrl = new Controller(repo, playlist);

    Tutorial t("title1", "presenter1", "www.youtube.com/1", Duration{2, 30}, 20);


    ctrl->addTutorialToRepo(t);
    assert(ctrl->getAllTutorials().size() == 6);
    assert(*ctrl->getAllTutorials()[5] == t);
    assert(ctrl->deleteTutorial("title1", "presenter1"));
    assert(!ctrl->deleteTutorial("", ""));
    assert(ctrl->getAllTutorials().size() == 5);

    t = Tutorial("Test1", "PTest1", "www.yt.c/111", Duration{3, 40}, 12);
    assert(ctrl->updateTutorial(t));
    assert(!ctrl->updateTutorial(Tutorial{}));
    assert(*ctrl->getAllTutorials()[0] == t);

    assert(ctrl->getTutorialsByPresenter("PTest2").size() == 3);

    ctrl->addTutorialToPlaylist(t);
    assert(ctrl->getPlaylist().size() == 4);

    cout << "Controller test PASSED!" << endl;
}

void CoverageTests::testPlaylist() {
    writePlaylistFile();
    string csvplaylist{"../playlist_test.csv"};
    auto *playlist = new Playlist(csvplaylist);
    Tutorial t("title1", "presenter1", "www.youtube.com/1", Duration{2, 30}, 20);

    playlist->addTutorialToPlaylist(t);
    assert(playlist->getUserWatchlist().size() == 4);

    cout << "Playlist test PASSED!" << endl;



}
