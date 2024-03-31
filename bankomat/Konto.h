#pragma once
//#include <string>
#include <QString>
using namespace std;
class Konto
{
private:

    QString nr_konta, imie, nazwisko;
    int pin;
    int* Saldo;

public:
    QString WypiszDaneQT() const ;
    void WpiszDane(QString imie, QString nazwisko, QString nr_konta, int pin, int saldo);
    void WypiszDane() const;
    void WypiszDanePrzedZalogowaniem() const          ;
    void OdejmijPieniadze(int gotowka);
    void DodajPieniadze(int gotowka);
    void StworzKonto();



    void PobierzPIN(int pin);
    void PobierzNR_KONTA(QString nr_konta);
    void PobierzSALDO(int saldo);
    Konto();
    QString ZwrocImie() const;
    QString ZwrocNazwisko() const;
    int  ZwrocPIN() const;
    QString  ZwrocNR_KONTA() const;
    int  ZwrocSALDO() const;
};
