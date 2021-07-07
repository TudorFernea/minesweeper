#include "MainPanel.h"

void MainPanel::init() {
    for (auto elem : this->service.getPlayerRepo().getElements()) {
        auto *programmerPanel = new ProgrammerPanel(service, elem);
        this->programmerPanels.push_back(programmerPanel);
        programmerPanel->setWindowTitle(elem.c_str());
        programmerPanel->show();
    }
}

MainPanel::MainPanel(Service &s) : service(s){
    this->init();
}
