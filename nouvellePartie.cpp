#include "nouvellePartie.h"
#include "ui_nouvellePartie.h"

NouvellePartie::NouvellePartie(QWidget* parent)
    : QMainWindow(parent)
    , ui_(new Ui::NouvellePartie)
{
    ui_->setupUi(this);
    connect(ui_->start, SIGNAL(pressed()), this, SLOT(signalClicked()));



}
void NouvellePartie::signalClicked(){

    this->close();
    emit clicked();
}


NouvellePartie::~NouvellePartie()
{

    delete ui_;

}


void NouvellePartie::MakeActive() {
    raise();
    this->show();
    this->activateWindow();
    this->raise();
}
