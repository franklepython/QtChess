#pragma once
#include "Piece.h"
#include <iostream>
#include "Ajout.h"
#include "Echequier.h"

using namespace std;

class Roi : public Piece
{
public:
    static shared_ptr<Piece> creationRoi(Couleur couleur);
    static void destructionRoi();
private:
    inline static shared_ptr<Piece> roiBlanc = nullptr;
    //rajouter une validation de mouvement

    Roi(Position pos, Couleur couleur, string symbole);

    friend class Echequier;

    inline static shared_ptr<Piece> roiNoir = nullptr;


};
