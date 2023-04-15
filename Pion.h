#pragma once
#include "Piece.h"
#include <iostream>
#include "Ajout.h"
#include "Echequier.h"

using namespace std;

class Pion : public Piece {
public:
	Pion(Position position, Couleur couleur, string symbole);
private:
	bool mouvementPion(Position posFinale, vector<vector<shared_ptr<Piece>>>& Echequier);
	friend class Echequier;
};