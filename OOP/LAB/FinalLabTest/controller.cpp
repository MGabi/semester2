#include "controller.h"
#include "repo.h"

Controller::Controller()
{

}

Controller::Controller(Repo *repo)
{
    this->repo = repo;
}

std::vector<Jumper *> Controller::getJumpers()
{
    return this->repo->getJumpers();
}
