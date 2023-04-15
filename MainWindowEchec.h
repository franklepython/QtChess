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

    void deplacementPiece(int x, int y);
    void remettreJeuxInitiale();
    void MakeActive();

signals:
    void echec();

private:
    QPoint positionInitiale;
    void initialisationFenetre();

    string listeChoisi = "";

    Position positionPieceSelectionne;
    bool premierClic = true;
    //shared_ptr<Echequier> plateau = Echequier::getEchequier();
    shared_ptr<Piece> pieceSelectionne = nullptr;



};
