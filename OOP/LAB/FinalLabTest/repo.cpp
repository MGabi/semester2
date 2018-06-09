#include "repo.h"
#include <fstream>

Repo::Repo()
{

}

Repo::Repo(std::string file){
    this->file = file;
    this->loadJumpers();
}

std::vector<Jumper *> Repo::getJumpers(){
return this->jumpers;
}

void Repo::addJumper(Jumper *jumper){
    this->jumpers.push_back(jumper);
}

void Repo::loadJumpers() {
    std::ifstream in(this->file);
    std::string line;
    Jumper j{};
    this->jumpers.clear();
    while(in >> j){
        this->jumpers.push_back(new Jumper(&j));
    }
    in.close();
}

void Repo::saveData() {
    std::string saveFile{this->file};
    saveFile.append(".save");
    std::ofstream out(saveFile, std::ios::out | std::ios::trunc);

    for(auto jumper: this->jumpers){
        out << jumper->name << ";" << jumper->distance << std::endl;
    }
    out.close();
}
