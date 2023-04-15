//Echequier.h
#pragma once
#include "Ajout.h"

#include<iostream>
#include <vector>
#include <string>
#include <memory>
#include <map>
#include "Piece.h"

using namespace std;


// Modele
class Echequier
{
public:
    vector<vector<shared_ptr<Piece>>> listeEquipeBlanc;
    vector<vector<shared_ptr<Piece>>> listeEquipeNoir;

    map<string, shared_ptr<Piece>> listePieceBlanc;
    map<string, shared_ptr<Piece>> listePieceNoir;

    ~Echequier();

    static unique_ptr<Echequier> getEchequier();
    vector<vector<shared_ptr<Piece>>> getTableauEchec() const;

    //bool mouvementPiece(shared_ptr<Piece>& piece, Position position);
    const shared_ptr<Piece> getPiece(int x, int y);

private:
    friend class Piece;

    vector<vector<shared_ptr<Piece>>> tableauEchec; // tableau 2D avec dimensions specifiees dans le constructeur (8x8)
    vector<vector<shared_ptr<Piece>>> tableauNul;
    vector<vector<shared_ptr<Piece>>> listeTemp;
    inline static unique_ptr<Echequier> plateau = nullptr; 


    Echequier();
    void initialisationJeu();
    void initialisationPosition(Position poisition, shared_ptr<Piece> piece);
    void reinitialiseJeu();
    //void eliminationPiece(Position position);
};
