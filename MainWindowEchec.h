#pragma once
#include <QMainWindow>
#include "Echequier.h"
#include "Ajout.h"
#include "Piece.h"
#include <qtablewidget.h>
#include <QLabel>
//#include <QMediaPlayer>

// vue et controleur

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindowEchec; }
QT_END_NAMESPACE

using namespace std;

class MainWindowEchec : public QMainWindow
{
    Q_OBJECT

public:
    MainWindowEchec(QWidget* parent = nullptr);
    ~MainWindowEchec();

    Ui::MainWindowEchec* ui;

    friend class RoiWidget;

    void mettreLeToutEnNoir();

public slots:

    //void deplacementPiece(int x, int y);
    void resizeEvent(QResizeEvent*);
    void remettreJeuxInitiale();
    void MakeActive();
    bool couleurDifferentes(shared_ptr<Piece> const piece1, shared_ptr<Piece> const piece2) const;

    //void promotionNoir(int x, int y);
    //void promotionBlanc(int x, int y);
    //void promotion(int x, int y, bool listeBlanche);
signals:
    void echec();

private:
    void eliminationPieceVue(shared_ptr<Piece> pieceAttaquante,shared_ptr<Piece> pieceAttaquee);
    bool caseNoir(Position position);
    void coloriageCaseValide(Position positionPieceSelectionne); 
    void coloriageCaseInvalide(Position positionPieceSelectionne); // utiliser en parallele avec remettreCouleurCaseAvant
    //void remettreCouleurCaseAvant();
    void initialisationFenetre();
    //void mouvementValide(shared_ptr<Piece> piece, Position position, bool castling, shared_ptr<Piece> tour);

    //void verificationEchec();

    //void effetMusiqueDeplacement();
    string listeChoisi = "";

    Position positionPieceSelectionne;
    bool premierClic = true;
    bool tourBlanc = true;
    shared_ptr<Echequier> plateau = Echequier::getEchequier();
    vector<Position> listeCaseColoriee;
    shared_ptr<Piece> pieceSelectionne = nullptr;



};
