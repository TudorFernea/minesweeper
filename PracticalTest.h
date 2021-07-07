#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PracticalTest.h"

class PracticalTest : public QMainWindow
{
    Q_OBJECT

public:
    PracticalTest(QWidget *parent = Q_NULLPTR);

private:
    Ui::PracticalTestClass ui;
};
