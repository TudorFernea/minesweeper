#pragma once

#include <QTableWidget>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "Programmer.h"
#include "Service.h"

class ProgrammerPanel: public QWidget, public Observer {
private:
    Service &service;
    std::string player;

    //graphical
    QTableWidget *tableWidget;
    QPushButton* mark, * reveal;
    QLineEdit *nameLine;
    int end;

public:
    ProgrammerPanel(Service &s, std::string player);

    void connectSignalsAndSlots();

    void initGUI();

    void refresh();

 

    void markcell();

    void revealcell();

   
};

