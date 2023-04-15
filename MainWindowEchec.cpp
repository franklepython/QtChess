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
    connect(ui->listeNoire, SIGNAL(cellClicked(int, int)), this, SLOT(promotionNoir(int, int)));
    connect(ui->listeBlanche, SIGNAL(cellClicked(int, int)), this, SLOT(promotionBlanc(int, int)));
    
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
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
            QTableWidgetItem* item = new QTableWidgetItem;
            ui->tableWidget->setItem(row, col, item);

            // Set the background color for the black squares
            if ((row + col) % 2 != 0) {
                item->setBackground(QBrush(QColor(0, 0, 0))); // Set the background color to black
            }
        }
    }

    ui->listeNoire->setMaximumWidth(tailleHorizontaleListeNoire);
    ui->listeNoire->setMaximumHeight(tailleVerticaleListeNoire);

    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
    ui->resetButton->setStyleSheet("background : rgba(94,94,94)");





    ui->listeBlanche->setIconSize(QSize(25, 25));
    ui->listeNoire->setIconSize(QSize(25, 25));

    //QString message = QString("Turn : <font color = #FF7676 > White < / font>");

    //ui->tourRole->setText(message);
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
            QTableWidgetItem* item = new QTableWidgetItem;
            ui->tableWidget->setItem(row, col, item);
        }
    }

    mettreLeToutEnNoir();

    ui->tableWidget->viewport()->update();

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 2; j++) {
            QTableWidgetItem* itemBlanc = new QTableWidgetItem;
            itemBlanc->setIcon(QIcon());
            QTableWidgetItem* itemNoir = new QTableWidgetItem;
            itemNoir->setIcon(QIcon());
            ui->listeBlanche->setItem(i, j, itemBlanc);
            ui->listeNoire->setItem(i, j, itemNoir);
        }
    }
}

void MainWindowEchec::deplacementPiece(int row, int col) {
    QTableWidgetItem* currentItem = ui->tableWidget->item(row, col);

    // Check if it's the first click (source cell)
    if (premierClic) {
        // Store the source position and set premierClic to false
        sourcePosition = QPoint(row, col);
        premierClic = false;
    }
    else {
        // Move the piece by swapping the QTableWidgetItem contents
        QTableWidgetItem* sourceItem = ui->tableWidget->item(sourcePosition.x(), sourcePosition.y());
        currentItem->setIcon(sourceItem->icon());
        currentItem->setText(sourceItem->text());
        sourceItem->setIcon(QIcon());
        sourceItem->setText("");

        // Reset premierClic
        premierClic = true;
    }
}
 

void MainWindowEchec::MakeActive(){
        raise();
        this->show();
        this->activateWindow();
        this->raise();
}

void MainWindowEchec::resizeEvent(QResizeEvent* event)
{
        cout << "Height " << this->size().height() << endl;
        cout << "Width" << this->size().width() << endl;

        int tailleHorizontaleTableWidget = ui->tableWidget->horizontalHeader()->sectionSize(0);
        int tailleVerticaleTableWidget = ui->tableWidget->verticalHeader()->sectionSize(0);
        int nouvelleTailleHorizontale = (25 * tailleHorizontaleTableWidget) / 30;


        ui->tableWidget->setIconSize(QSize(nouvelleTailleHorizontale, tailleVerticaleTableWidget));
        QMainWindow::resizeEvent(event);
}


void MainWindowEchec::remettreJeuxInitiale() {
        if (premierClic == false) {
           // remettreCouleurCaseAvant();
           // listeCaseColoriee.clear();
        }
        
        for (int i = 0; i < 8; i++) {
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
        }
        /*
        for (auto&& piece : plateau->listePieceBlanc) {
            auto item = ui->tableWidget->item(piece.second->getPosition().x, piece.second->getPosition().y-1);
            item->setIcon(QIcon());
        }

        for (auto&& piece : plateau->listePieceNoir) {
            auto item = ui->tableWidget->item(piece.second->getPosition().x, piece.second->getPosition().y-1);
            item->setIcon(QIcon());
        }*/

        mettreLeToutEnNoir();

        //plateau->resetGame();
        tourBlanc = true;
        premierClic = true;

       // ui->tableWidget->item(0, 4)->setIcon(QIcon("RoiBleu.png"));
        ui->tableWidget->item(0, 4)->setText("Patrice le Roi");
        ui->tableWidget->item(7, 3)->setText("Francis le Roi");
        ui->tableWidget->item(1, 5)->setText("Pion Blanc");
        ui->tableWidget->item(1, 6)->setText("Pion Noir");
        ui->tableWidget->item(0, 0)->setText("Tour");
        ui->tableWidget->item(7, 7)->setText("Tour");
            

        //ui->tableWidget->item(7, 4)->setIcon(QIcon(":/Ressource/image/roiNoir.png"));



}
MainWindowEchec::~MainWindowEchec() {
        delete ui;
}

bool MainWindowEchec::couleurDifferentes(shared_ptr<Piece> const piece1, shared_ptr<Piece> const piece2) const {
    if (piece1->getCouleur() == piece2->getCouleur()) {
        return false;
    }

    return true;
}