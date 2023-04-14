#pragma once
#include "Piece.h"
#include <iostream>
#include "Ajout.h"
#include "Echequier.h"
#include <QApplication>
#include <qguiapplication.h>
#include "MainWindowEchec.h"
#include <memory>
#include <QMouseEvent>
#include <QPushButton>
#include "ui_MainWindowEchec.h"


using namespace std; // enlever ca

class Roi : public Piece
{
public:
    Roi(Position pos, Couleur couleur, string symbole);
    static shared_ptr<Piece> creationRoi(Couleur couleur);
    static void destructionRoi();

    virtual bool movementEstValide(const Position pos) const override;

private:
    inline static shared_ptr<Piece> roiBlanc = nullptr;
    //rajouter une validation de mouvement


    friend class Echequier;
    friend class RoiWidget;

    inline static shared_ptr<Piece> roiNoir = nullptr;


};




// avoir un .h pour cette classe. Les signaux et slots seront entre les QWidgets de pieces et les objets pieces (lies au QWidgets) seront modifies

class RoiWidget : public QWidget {
public:

    Q_OBJECT

    RoiWidget(shared_ptr<MainWindowEchec> ptrMainWindowEchec, Position pos, Couleur couleur) : ptrMainWindowEchec_(ptrMainWindowEchec), 
        position_({ pos.x, pos.y }), couleur_(couleur) {}

    // ~RoiWidget() = default;


    //bool validerMouvement(Position position) const;

signals:
    void positionchangee(Position position);

protected:
    QPoint m_lastMousePos;
    QPoint m_buttonOffset;

    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

private:
    shared_ptr<MainWindowEchec> ptrMainWindowEchec_;
    Position position_;
    Couleur couleur_;
    shared_ptr<Roi> ptrRoi_ = make_shared<Roi>(position_, couleur_, "roi"); // modifier symbol
};