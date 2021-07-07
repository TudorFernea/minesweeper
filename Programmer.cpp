

#include "Programmer.h"

std::string Programmer::getName() {
    return this->name;
}

int Programmer::getRevisedFiles() {
    return this->revisedFiles;
}

int Programmer::getMustRevise() {
    return this->mustRevise;
}

Programmer::Programmer(std::string n, int i1, int i2) : name(n), revisedFiles(i1), mustRevise(i2) {

}

void Programmer::setRevised() {
    this->revisedFiles++;
}

void Programmer::setMustRevise() {
    this->mustRevise--;
}
