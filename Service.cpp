

#include "Service.h"
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <utility>
#include <time.h>

Service::Service() : Observable() {
    this->playerRepo = Repository<std::string>();
    this->nrdef = 0;
    this->foundmines = 0;
    this->loadFile();
}

void Service::addPlayer(std::string pl) {
    this->playerRepo.add(pl);
    this->notify();
}


Repository<std::string> Service::getPlayerRepo() {
    return this->playerRepo;
}

void Service::loadFile() {
    std::string line;
    std::ifstream f("input.txt");
    getline(f, line);
    this->n = atoi(line.c_str());
    getline(f, line);
    this->mines = atoi(line.c_str());

    while (getline(f, line)) {
        this->playerRepo.add(line);
    }
    
    int k = 0;
    srand(time(NULL));
    while (k < this->mines)
    {
        int i = rand() % this->n;
        int j = rand() % this->n;
        if (this->mine[i][j] != -1)
        {
            this->mine[i][j] = -1;
            k++;
        }
    }
    this->turn = 0;
    this->notify();
}

void Service::updateMap(int i, int j, int val)
{
    this->map[i][j] = val;
    this->turn++;
    this->turn = this->turn % this->getPlayerRepo().getSize();
    this->notify();
}
