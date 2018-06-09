#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "repo.h"

#include <vector>
class Controller
{
private:
    Repo* repo;
public:
    Controller();
    Controller(Repo* repo);
    std::vector<Jumper*> getJumpers();

};

#endif // CONTROLLER_H
