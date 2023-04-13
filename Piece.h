#pragma once
#include "Ajout.h"

#include<iostream>
#include <vector>
#include <string>
#include <memory>
#include <map>

using namespace std;

class Piece {
public:
    Piece();
    Piece(Position pos, Couleur couleur, string symbole);

    //rajouter un validateur de mouvement

    string getSymbole();
    Couleur getCouleur();
    Position getPosition();

protected:
    friend class Echequier;
    Position position_;
    Couleur couleur_;
    string symbole_;
    bool mouvementPossible = true;

    bool debut = true;
    bool estPion = false;
    bool estTour = false;
    bool estRoi = false;
    bool promotion = false;
};
