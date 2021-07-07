

#include <QVBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QDebug>
#include <QMessageBox>
#include "ProgrammerPanel.h"
#include <iostream>

ProgrammerPanel::ProgrammerPanel(Service &s, std::string p) : Observer(), service(s), player(p) {
    this->service.addObserver(this);
    this->end = 0;
    this->initGUI();
    this->refresh();
    this->connectSignalsAndSlots();
    this->show();
}

void ProgrammerPanel::initGUI() {
    auto *mainLayout = new QVBoxLayout{this};

    // table
    this->tableWidget = new QTableWidget;
    this->tableWidget->setRowCount(this->service.getN());
    this->tableWidget->setColumnCount(this->service.getN());
    
    for(int i=0; i<this->service.getN()+1; i++)
    this->tableWidget->setColumnWidth(i, 40);
 

    mainLayout->addWidget(this->tableWidget);

    // labels & buttons
    auto *grid = new QGridLayout{};

    // buttons
    this->mark = new QPushButton{"Mark"};
    this->reveal = new QPushButton{"Reveal"};
    grid->addWidget(mark, 2, 0);
    grid->addWidget(reveal, 2, 1);

    mainLayout->addLayout(grid);

    // line
    auto *formLayout = new QFormLayout;
    this->nameLine = new QLineEdit{};
    this->nameLine->setFixedWidth(100);
    formLayout->addRow("Coordinates:  ", nameLine);
    mainLayout->addLayout(formLayout);

}

void ProgrammerPanel::refresh() {
    if (this->service.nrdef == this->service.getPlayerRepo().getSize())
    {
        QMessageBox::critical(this, "Oops", "You all lost!");
        this->close();
    }

    if (this->service.foundmines == this->service.getMines())
    {
        QMessageBox::critical(this, "Congratulations!", "You won!");
        this->close();
    }

    this->tableWidget->clear();
    for (int i = 0; i < this->service.getN(); i++)
    {
        std::string ss;
        ss = "a";
        ss[0] = 'A' + i;
        this->tableWidget->setHorizontalHeaderItem(i, new QTableWidgetItem(QString::fromStdString(ss)));
    }
        

    for (int i = 0; i < this->service.getN(); i++)
    {
        this->tableWidget->setVerticalHeaderItem(i, new QTableWidgetItem(QString::number(i+1)));

    }

    
    for(int i=0; i<this->service.getN(); i++)
        for (int j = 0; j < this->service.getN(); j++)
        {
            if (this->service.map[i][j] == 0)
            {
                this->tableWidget->setItem(i, j, new QTableWidgetItem());
                this->tableWidget->item(i, j)->setBackground(Qt::green);
            }

            if (this->service.map[i][j] == -1)
            {
                this->tableWidget->setItem(i, j, new QTableWidgetItem("*"));
                this->tableWidget->item(i, j)->setBackground(Qt::red);
            }

            if (this->service.map[i][j] == -10)
            {
                this->tableWidget->setItem(i, j, new QTableWidgetItem("XD"));
                this->tableWidget->item(i, j)->setBackground(Qt::red);
            }

            if (this->service.map[i][j] > 0)
            {
                this->tableWidget->setItem(i, j, new QTableWidgetItem(QString::number(this->service.map[i][j]-1)));
                this->tableWidget->item(i, j)->setBackground(Qt::blue);
            }

        }
    
    int pl = 0;
    for (int i = 0; i < this->service.getPlayerRepo().getSize(); i++)
        if (this->service.getPlayerRepo().getElements()[i] == this->player)
            pl = i;
    
    if (this->service.turn == pl && this->end == 0)
    {
        this->mark->setDisabled(false);
        this->reveal->setDisabled(false);
    }
    else
    {
        this->mark->setDisabled(true);
        this->reveal->setDisabled(true);
    }
    
}

void ProgrammerPanel::connectSignalsAndSlots() {
    QObject::connect(this->mark, &QPushButton::clicked, this, &ProgrammerPanel::markcell);
    QObject::connect(this->reveal, &QPushButton::clicked, this, &ProgrammerPanel::revealcell);
}

void ProgrammerPanel::markcell()
{
    std::string cell = this->nameLine->text().toStdString();
    bool ok = true;
    
    if (!cell.empty() || cell.size()<=3) {
        

        int j = cell[0] - 'A';
        int i = 0;
        if (cell.size() == 3)
        {
            std::string ss = "00";
            ss[0] = cell[1];
            ss[1] = cell[2];
            i = atoi(ss.c_str())-1;
        }
        if (cell.size() == 2)
        {
            std::string ss = "0";
            ss[0] = cell[1];
            i = atoi(ss.c_str());
        }

        if (i > this->service.getN() || i<1 || j>this->service.getN() || j < 0)
            ok = false;
        else
        {
            if (this->service.map[i-1][j] != 0)
                ok = false;
        }

        if (ok) {
            this->service.updateMap(i-1, j, -1);
            if (this->service.mine[i - 1][j] == -1)
                this->service.foundmines++;
        }
        else
            QMessageBox::critical(this, "Error", "Invalid input!");
    }
    else
        QMessageBox::critical(this, "Error", "Invalid input!");
    this->refresh();
}

void ProgrammerPanel::revealcell()
{
    std::string cell = this->nameLine->text().toStdString();
    bool ok = true;

    if (!cell.empty() || cell.size() <= 3) {


        int j = cell[0] - 'A';
        int i = 0;
        if (cell.size() == 3)
        {
            std::string ss = "00";
            ss[0] = cell[1];
            ss[1] = cell[2];
            i = atoi(ss.c_str()) - 1;
        }
        if (cell.size() == 2)
        {
            std::string ss = "0";
            ss[0] = cell[1];
            i = atoi(ss.c_str());
        }

        if (i > this->service.getN() || i<1 || j>this->service.getN() || j < 0)
            ok = false;
        else
        {
            if (this->service.map[i-1][j] != 0)
                ok = false;
        }

        if (ok) {
            int val = 0;

            if (this->service.mine[i - 1][j] == -1)
            {
                this->end = 1;
                this->service.updateMap(i - 1, j, -10);
                this->service.nrdef++;
                QMessageBox::critical(this, "GAME OVER!", "YOU DIED! XD");
            }
            else
            {
                int diri[8] = { 0,0,-1,1,1,1,-1,-1 };
                int dirj[8] = { -1,1,0,0,1,-1,1,-1 };

                int ii = 0;
                int jj = 0;
                for (int k = 0; k <= 7; k++)
                {
                    ii = i - 1 + diri[k];
                    jj = j + dirj[k];
                    if (!(ii > this->service.getN() || ii<1 || jj>this->service.getN() || jj < 0))
                        if (this->service.mine[ii][jj] == -1)
                            val++;
                }
              
                this->service.updateMap(i - 1, j, val+1);
            }
        }
        else
            QMessageBox::critical(this, "Error", "Invalid input!");
    }
    else
        QMessageBox::critical(this, "Error", "Invalid input!");
    this->refresh();
}
