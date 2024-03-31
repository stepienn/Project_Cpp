#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Konto.h"
#include "Bankomat.h"
#include <QMainWindow>
#include <QWidget>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();
    Bankomat bank1;
    Konto karta1,karta2,karta3;
    QString ImieDodawane, NazwiskoDodawane, NrKontaDodawane;
    int pin_dodawany, saldo_dodawane;
    int il_kont=2;


public slots:
    void Loguj();
    void PrzeslijKonto();
    void PodajPin();
    void ZalogowanoPoprawnie();
    void SprawdzStanKonta();
    void SprawdzSaldoBankomatu();
    void ZacznijWplacPieniadze();
    void WplacPieniadze();
    void ZacznijWyplacPieniadze();
    void WyplacPieniadze();
    void ZacznijPrzelew();
    void WTrakciePrzelew();
    void Przelew();
    void Wyloguj();
    void Powrot();
    void SprawdzSaldoBankomatuPOZALOGOWANIU();
    void UtworzUzytkownikaZacznij();
    void WyslijImie();
    void WyslijNazwisko();
    void WyslijNrKonta();
    void WyslijNrPin();
    void WyslijSaldoPoczatkowe();
    void UtworzenieKontaZpodanych();

    // void Zaloguj();
    //  void PrzejdzDalej();
    // void SprawdzPin();
    // void wyswietlTekst();
    // void PobierzTekstNapis();
    //   void PobierzTekstLiczby();

private:
    Ui::MainWindow *ui;

    int stanlog = 0;
    string nr_konta;
    int pin, wybor;
    vector<Konto> karty;
    int kwota;

    bool wyjdz = false;
    int wybor2;
    void TekstWyboru();
    int nominal;
    int ilosc;
    int przelew;
    Konto* wybraneKonto;
    Konto* kontoDoPrzelewu;

    //POZNIEJ SPROBOWAC ZMEINIC
};
#endif // MAINWINDOW_H
