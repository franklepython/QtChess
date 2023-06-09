//Echequier.cpp
#include "Echequier.h"
#include "Piece.h"
#include "Roi.h"
#include <iostream>
#include <string>
/*Logique des pieces, travail en cours, sert a rien pour l'instant
unique_ptr<Echequier> Echequier::getEchequier(){
    if (plateau == nullptr)
        plateau = make_unique<Echequier>(Echequier());
    return std::move(plateau);
}


vector<vector<shared_ptr<Piece>>> Echequier:: getTableauEchec() const {
    return tableauEchec;
}

void Echequier::initialisationJeu()
{
    tableauEchec.clear();
    tableauEchec = tableauNul;
    listeEquipeBlanc = listeTemp;
    listeEquipeNoir = listeTemp;

    tableauEchec[0][5] = Roi::creationRoi(Couleur::blanc);
    tableauEchec[7][5] = Roi::creationRoi(Couleur::noir);

    listePieceBlanc[Roi::roiBlanc->getSymbole()] = Roi::roiBlanc;
    listePieceNoir[Roi::roiNoir->getSymbole()] = Roi::roiNoir;
}

void Echequier::initialisationPosition(Position position, shared_ptr<Piece> piece) {
    piece->getPosition() = position;
}

void Echequier::reinitialiseJeu() {
    initialisationPosition({ 0,5 }, Roi::roiBlanc);
    initialisationPosition({ 0,5 }, Roi::Roi::roiNoir);
}

/*
Echequier::Echequier() {
    tableauEchec.resize(8);
    tableauNul.resize(8);
    listeEquipeBlanc.resize(8);
    listeEquipeNoir.resize(8);
    listeTemp.resize(8);
    for (int i = 0; i < 8; ++i) {
        tableauEchec[i].resize(9);
        tableauNul[i].resize(9);
    }

    tableauEchec.resize(8);
    tableauNul.resize(8);

    for (int i = 0; i < 8; ++i) {
        listeEquipeBlanc[i].resize(2);
        listeEquipeNoir[i].resize(2);
        listeTemp[i].resize(2);
    }

    initialisationJeu();

    cout << "Echequier construit" << endl;
}

Echequier::~Echequier() {
    cout << "Echequier detruit" << endl;
}
*/