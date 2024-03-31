#pragma once
#include "Konto.h"
#include <vector>
#include <QString>


using namespace std;
class Bankomat
{
private:
    int saldo_uzytkownika;
    int saldo_bankomatu;
    int kwota_do_wyplacenia;
    int kwota_do_wyplacenia_przedoperacja;
    int typ_banknotu[9];
    int ilosc_banknotow[9];
    int ilosc_banknotow_przedoperacja[9];
    int suma_salda_bankomatu;
    int wybor_wyplaty;
    int ilosc_banknotow_wplata;
    int kwota_karty;
    vector<Konto> listakont;

public:
    QString WypiszIloscZasobow();
    QString WypiszBanknotyQT();
    void WypiszBanknoty();
    int SumaSaldaBankomatu();
    QString SumaSaldaBankomatuWypisz();
    Bankomat();
    void DodajKonto(const Konto& noweKonto);
    int CzytajSaldo(int saldo);
    int WyplacPieniadze(int kwota_do_wyplacenia, int kwota_karty);
    void WplacPieniadze(int nominal, int ilosc);
    void WypiszWszystkieKonta();
    QString WypiszWszystkieKontaQT();
};
