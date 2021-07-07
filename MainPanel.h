#pragma once

#include "Service.h"
#include "ProgrammerPanel.h"

class MainPanel {
private:
    Service& service;
    std::vector<ProgrammerPanel*> programmerPanels;

public:
    void init();

    explicit MainPanel(Service &s);
};

