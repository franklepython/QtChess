#include "Pion.h"
#include <iostream>
#include <string>
#include <cmath>
#include <memory>

#include <Piece.h>
#include <Ajout.h>

Pion::Pion(Position position, Couleur couleur, string symbole) : Piece(position, couleur, symbole) {
	estPion = true;
}

bool Pion::mouvementPion(Position posFinale, vector<vector<shared_ptr<Piece>>>& Echequier) {
	int positionValide = 0;

	if (this->couleur_ == Couleur::blanc) {
		positionValide = (position_.y + 1 == posFinale.y);
		return true;
	}
	if (this->couleur_ == Couleur::noir) {
		positionValide = (position_.y - 1 == posFinale.y);
		return true;
	}
}