
#ifndef NOUVELLEPARTIE_H
#define NOUVELLEPARTIE_H
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class NouvellePartie; }
QT_END_NAMESPACE

class NouvellePartie : public QMainWindow
{
    Q_OBJECT

public:
    NouvellePartie(QWidget *parent = nullptr);
    ~NouvellePartie();

signals:
    void clicked();

public slots:
    void signalClicked();
    void MakeActive();

private:
    Ui::NouvellePartie *ui_;


};
#endif // NOUVELLEPARTIE_H
