#pragma once

#include "Programmer.h"
#include "Source.h"
#include "Repository.h"
#include "Observable.h"

class Service :public Observable {
private:
    Repository<std::string> playerRepo;
    int n;
    int mines;

public:
    int map[101][101];
    int mine[101][101];
    int turn;
    int nrdef;
    int foundmines;

    Service();

    void addPlayer(std::string pl);

    Repository<std::string> getPlayerRepo();

    void loadFile();

    int getN() {
        return this->n;

    }

    int getMines() {
        return this->mines;
    }

    void updateMap(int i, int j, int val);

    /*
    void reviseSourceFile(std::string name, std::string programmer);

    
    std::vector<SourceFile> sortByName();

    std::vector<SourceFile> sortByStatus();

    std::vector<SourceFile> sortByCreator();

    std::vector<SourceFile> sortByReviewer();

    std::vector<std::string> tokenize(std::string str, char delimiter);
    */
};