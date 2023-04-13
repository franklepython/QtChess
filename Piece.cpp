#include "Piece.h"
#include "Roi.h"

#include <iostream>
#include <string>

using namespace std;

Piece::Piece() {
    position_.x = 0;
    position_.y = 0;
    couleur_ = Couleur::vide;
    symbole_ = "aucun";
}

Piece::Piece(Position pos, Couleur couleur, string symbole) : position_(pos), couleur_(couleur), symbole_(symbole){}

//ajouter une methode pour valider les mouvements

string Piece::getSymbole(){
    if (this == nullptr){
        return "Pas de symbole";
    }
    return symbole_;
}

Couleur Piece::getCouleur() {
    if (this == nullptr){
        return Couleur::vide;
    }
    return couleur_;
}

Position Piece::getPosition() {
    return position_;
}
