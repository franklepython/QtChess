#include <iostream>
#include <string>

#include "Roi.h"
#include "Ajout.h"
#include <cmath>
#include "Piece.h"

#include "MainWindowEchec.h" // pour le QObject de type roi

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


bool Roi::movementEstValide(const Position nouvellePos) const {
    // 1. verifier si x et y sont dans l'echiquier et lancer une exception si non
    // 1. verifier si x et y sont differents que les x y de l'objet. Si non, lancer exception

    //2. verifier si sa position varie de plus de 1 en x et en y
    if (abs(position_.x - nouvellePos.x) > 2 || abs(position_.y - nouvellePos.y) > 2) {
        return false;
    }

    return true;
}








/*
bool RoiWidget::validerMouvement(Position position) const {
    //1. verifier que l'objet roi peu faire ce type de mouvement. Si non, return false, si oui --> 2
    //2. verifier s'il y a un objet dans cette position. si non, return true. Si oui -->3
    //3. verifier la couleur de l'objet a cette position, s'ils ont la meme couleur, return false

    if (!ptrRoi_->movementEstValide(position)) {
        return false;
    }

    if (ptrMainWindowEchec_->plateau->getTableauEchec()[position_.y][position.x] == nullptr) {
        return true;
    }
    else {
        if (!ptrMainWindowEchec_->couleurDifferentes(ptrMainWindowEchec_->plateau->getTableauEchec()[position_.y][position.x], ptrRoi_)) {
            return false;
        }
    }

    return true;
}*/

//3. acceder a l'echequier et verifier si une piece de son groupe se trouve dans cette position

/*
void RoiWidget::mousePressEvent(QMouseEvent* event)
{
    // Get the button widget at the current mouse position
    QPushButton* button = qobject_cast<QPushButton*>(childAt(event->pos()));

    if (button && button->parentWidget() == ptrMainWindowEchec->ui->tableWidget) {
        // Save the mouse position and the button position relative to the mouse
        m_lastMousePos = event->pos();
        m_buttonOffset = button->pos() - m_lastMousePos;
    }
}

void RoiWidget::mouseMoveEvent(QMouseEvent* event)
{
    // Check if the left mouse button is down and a button is being dragged
    if (event->buttons() & Qt::LeftButton && !m_buttonOffset.isNull()) {
        // Move the button to the new position
        QPushButton* button = qobject_cast<QPushButton*>(childAt(m_lastMousePos));
        button->move(event->pos() + m_buttonOffset);
    }
}

void RoiWidget::mouseReleaseEvent(QMouseEvent* event)
{
    // Reset the button offset when the left mouse button is released
    if (event->button() == Qt::LeftButton && !m_buttonOffset.isNull()) {
        m_buttonOffset = QPoint();
    }
}*/