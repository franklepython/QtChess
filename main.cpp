
#include "MainWindowEchec.h"

#include <QApplication>
#include <QDesktopWidget>
#include <qguiapplication.h>

#include <iostream>
#include <vector>
#include "nouvellePartie.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSharedPointer<MainWindowEchec> p(new MainWindowEchec());
    QSharedPointer<NouvellePartie> w(new NouvellePartie());

    QObject::connect(w.get(), &NouvellePartie::clicked, p.get(), &MainWindowEchec::MakeActive);
    QObject::connect(p.get(), &MainWindowEchec::echec, w.get(), &NouvellePartie::MakeActive);

    w->show();
    return a.exec();
}
