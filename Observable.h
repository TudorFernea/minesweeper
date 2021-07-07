#pragma once

#include <vector>
#include "Observer.h"

class Observable {
private:
    std::vector<Observer*> observers;

public:
    Observable() { this->observers = std::vector<Observer*>(); }

    void addObserver(Observer* obs);

    void notify();
};

