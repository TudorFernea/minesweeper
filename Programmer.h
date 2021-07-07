#pragma once

#include <string>

class Programmer {
private:
    std::string name;
    int revisedFiles;
    int mustRevise;

public:
    Programmer(std::string name, int i1, int i2);

    std::string getName();

    int getRevisedFiles();

    int getMustRevise();

    void setRevised();

    void setMustRevise();
};
