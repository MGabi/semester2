#ifndef REPO_H
#define REPO_H
#include "jumper.h"

#include <vector>

class Repo
{
private:
    std::vector<Jumper*> jumpers;
    std::string file;

public:
    Repo();
    Repo(std::string file);
    std::vector<Jumper*> getJumpers();
    void addJumper(Jumper* jumper);
    void loadJumpers();
    void saveData();
};

#endif // REPO_H
