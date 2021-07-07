
#include "Observable.h"

void Observable::notify() {
    for(auto e: this->observers)
        e->refresh();
}

void Observable::addObserver(Observer *obs) {
    this->observers.push_back(obs);
}
