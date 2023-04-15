#include <iostream>
#include <string>
#include <QTableWidget>
#include <QMessageBox>
#include <QPixmap>
#include <qscreen.h>
#include <QLabel>
#include <QBrush>
#include <QColor>

#include "MainWindowEchec.h"
#include "ui_MainWindowEchec.h"

MainWindowEchec::MainWindowEchec(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowEchec)
{
    ui->setupUi(this);

    connect(ui->tableWidget, SIGNAL(cellClicked(int, int)), this, SLOT(deplacementPiece(int, int)));
    connect(ui->resetButton, SIGNAL(clicked()), this, SLOT(remettreJeuxInitiale()));
    
    initialisationFenetre();
}

void MainWindowEchec::mettreLeToutEnNoir() {
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
            QTableWidgetItem* item = new QTableWidgetItem;
            ui->tableWidget->setItem(row, col, item);
            if ((row + col) % 2 != 0) {
                item->setBackground(QBrush(QColor(0, 0, 0)));
            }
        }
    }
}

void MainWindowEchec::initialisationFenetre() {
    premierClic = true;
    ui->gridLayout->setAlignment(ui->tableWidget, Qt::AlignCenter);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setFixedWidth(25);
    ui->tableWidget->horizontalHeader()->setFixedHeight(35);
    
    //On initialise ici les listes de pieces dans l'affichage Qt, mais on ne les utilises pas encore
    int tailleHorizontaleListeBlanche = 0;
    for (int col = 0; col < ui->listeBlanche->columnCount(); ++col) {
        tailleHorizontaleListeBlanche += ui->listeBlanche->horizontalHeader()->sectionSize(col);
    }

    int tailleVerticaleListeBlanche = 0;
    for (int row = 0; row < ui->listeBlanche->rowCount(); ++row) {
        tailleVerticaleListeBlanche += ui->listeBlanche->verticalHeader()->sectionSize(row);
    }

    ui->listeBlanche->setMaximumWidth(tailleHorizontaleListeBlanche);
    ui->listeBlanche->setMaximumHeight(tailleVerticaleListeBlanche);

    int tailleHorizontaleListeNoire = 0;
    for (int col = 0; col < ui->listeNoire->columnCount(); ++col) {
        tailleHorizontaleListeNoire += ui->listeNoire->horizontalHeader()->sectionSize(col);
    }

    int tailleVerticaleListeNoire = 0;
    for (int row = 0; row < ui->listeNoire->rowCount(); ++row) {
        tailleVerticaleListeNoire += ui->listeNoire->verticalHeader()->sectionSize(row);
    }

    ui->listeNoire->setMaximumWidth(tailleHorizontaleListeNoire);
    ui->listeNoire->setMaximumHeight(tailleVerticaleListeNoire);
    
    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
    ui->resetButton->setStyleSheet("background : rgba(94,94,94)");

    ui->listeBlanche->setIconSize(QSize(25, 25));
    ui->listeNoire->setIconSize(QSize(25, 25));

    mettreLeToutEnNoir();

    ui->tableWidget->viewport()->update();
}

void MainWindowEchec::deplacementPiece(int row, int col) {
    QTableWidgetItem* itemInitial = ui->tableWidget->item(row, col);

    if (premierClic) {
        positionInitiale = QPoint(row, col);
        premierClic = false;
    }
    else {
        QTableWidgetItem* sourceItem = ui->tableWidget->item(positionInitiale.x(), positionInitiale.y());
        itemInitial->setIcon(sourceItem->icon());
        itemInitial->setText(sourceItem->text());
        sourceItem->setIcon(QIcon());
        sourceItem->setText("");

        premierClic = true;
    }
}
 

void MainWindowEchec::MakeActive(){
        raise();
        this->show();
        this->activateWindow();
        this->raise();
}

void MainWindowEchec::remettreJeuxInitiale() {
        if (premierClic == false) {
            mettreLeToutEnNoir();
        }
        
        //On va utiliser une logique avec des listes pour les pieces des deux equipes, mais en ce moment ces lignes ne servent a rien
        /*for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 2; j++) {
                if (plateau->listeEquipeBlanc[i][j] != nullptr) {
                    auto item = ui->listeBlanche->item(i, j);
                    item->setIcon(QIcon());

                }
                if (plateau->listeEquipeNoir[i][j] != nullptr) {
                    auto item = ui->listeNoire->item(i, j);
                    item->setIcon(QIcon());
                }
            }
        }*/

        ui->tableWidget->item(0, 4)->setText("Patrice le Roi");
        ui->tableWidget->item(7, 3)->setText("Francis le Roi");
        ui->tableWidget->item(1, 5)->setText("Pion Blanc");
        ui->tableWidget->item(1, 6)->setText("Pion Noir");
        ui->tableWidget->item(0, 0)->setText("Tour");
        ui->tableWidget->item(7, 7)->setText("Tour");


}
MainWindowEchec::~MainWindowEchec() {
        delete ui;
}
