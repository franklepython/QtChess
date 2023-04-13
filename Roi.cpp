#include <iostream>
#include <string>

#include "Roi.h"
#include "Ajout.h"
#include <cmath>
#include "Piece.h"

std::shared_ptr<Piece> Roi::Roi::creationRoi(Couleur couleur) {
    if (roiBlanc == nullptr && couleur == Couleur::blanc) {

        roiBlanc = make_shared<Roi>(Roi({ 0,5 }, Couleur::blanc, "Roi blanc"));
        return roiBlanc;
    }

    else if (roiBlanc != nullptr && couleur == Couleur::blanc) {

        return roiBlanc;
    }

    if (roiNoir == nullptr && couleur == Couleur::noir) {

        roiNoir = make_shared<Roi>(Roi({ 7,5 }, Couleur::noir, "Roi noir"));
        return roiNoir;
    }

    else if (roiNoir != nullptr && couleur == Couleur::noir) {

        return roiNoir;
    }
}

void Roi::Roi::destructionRoi() {
    roiBlanc = nullptr;
    roiNoir = nullptr;
}

Roi::Roi::Roi(Position position, Couleur couleur, string symbole) : Piece(position, couleur, symbole) {
    estRoi = true;
}
