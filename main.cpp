#include <iostream>
#include <QApplication>
#include "Service.h"
#include "MainPanel.h"

int main(int argc, char** argv) {
    QApplication a(argc, argv);
    Service s;
    MainPanel m(s);
    return a.exec();
}
