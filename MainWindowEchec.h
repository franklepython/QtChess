#pragma once
#include <QMainWindow>
#include "Echequier.h"
#include "Ajout.h"
#include "Piece.h"
#include <qtablewidget.h>
#include <QLabel>
//#include <QMediaPlayer>

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

public slots:

    //void deplacementPiece(int x, int y);
    void resizeEvent(QResizeEvent*);
    void remettreJeuxInitiale();
    void MakeActive();

    //void promotionNoir(int x, int y);
    //void promotionBlanc(int x, int y);
    //void promotion(int x, int y, bool listeBlanche);
signals:
    void echec();

private:
    void eliminationPieceVue(shared_ptr<Piece> pieceAttaquante,shared_ptr<Piece> pieceAttaquee);
    bool caseNoir(Position position);
    void coloriageCaseValide(Position positionPieceSelectionne);
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
