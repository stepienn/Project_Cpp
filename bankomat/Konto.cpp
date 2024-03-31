#include "Konto.h"
#include "mainwindow.h"
#include <iostream>
#include <QObject>

using namespace std;

Konto::Konto(){
    nr_konta = imie = nazwisko = " " ;
    pin =0;
    Saldo=new int(0);
}

void Konto::WpiszDane(QString imie, QString nazwisko,QString nr_konta, int pin, int saldo)
{
    this->imie = imie;
    this->nazwisko = nazwisko;
    *Saldo = saldo;
    this->pin = pin;
    this->nr_konta = nr_konta;

}

void Konto::StworzKonto() {
    //  ui->oknoText->setText("Podaj imie");
    cout << "\n Podaj imie: ";
    //cin >> this->imie;
    cout << "\n Podaj nazwisko:";
    //cin >> this->nazwisko;
    cout << "\n Podaj numer_konta: ";
    //cin >> this->nr_konta;
    cout << "\n Podaj numer pin: ";
    //cin >> this->pin;
    cout << "\n Podaj saldo poczatkowe: ";
    //cin >> this->saldo;


    PobierzNR_KONTA(this->nr_konta);
    PobierzPIN(this->pin);
    cout << "\nUtworzono konto pomy?lnie!\n";
}
void Konto::PobierzNR_KONTA(QString nr_konta) {
    this->nr_konta = nr_konta;
}
void Konto::PobierzPIN(int pin) {
    this->pin = pin;
}
void Konto::PobierzSALDO(int saldo) {
    *Saldo = saldo;
}
QString Konto::ZwrocImie() const {
    return imie;
}
QString Konto::ZwrocNazwisko() const {
    return nazwisko;
}
QString Konto::ZwrocNR_KONTA() const {
    return nr_konta;
}
int Konto::ZwrocPIN() const {
    return pin;
}
int Konto::ZwrocSALDO() const{
    return *Saldo;
}

void Konto::WypiszDane() const {
    //cout << "Nr konta:" << nr_konta << "\nPIN: " << pin << "\nSALDO: " << saldo << "\n";
}
\
    void Konto::WypiszDanePrzedZalogowaniem() const {

    ZwrocImie();
    ZwrocNazwisko();
    ZwrocNR_KONTA();
    ZwrocSALDO();
    //cout <<"Imie: "<<imie<<"\nNazwisko: "<<nazwisko << "\nNr konta: " << nr_konta << "\nSALDO: " << saldo << "\n";
}

QString Konto::WypiszDaneQT() const {
    WypiszDanePrzedZalogowaniem();

    QString czyszczenieImie = ZwrocImie();
    QString czyszczenieNazwisko = ZwrocNazwisko();
    QString czyszczenieNR_KONTA = ZwrocNR_KONTA();
    QString czyszczenieSALDO = QString::number(ZwrocSALDO());

    return "\nImie: " + czyszczenieImie + "\nNazwisko: " + czyszczenieNazwisko + "\nNr konta: " + czyszczenieNR_KONTA + "\n" + "Saldo: " + czyszczenieSALDO + "\n\n";
    //string->number String.toInt()
    // return "\nSuma salda bankomatu: " + QString::number(SumaSaldaBankomatu());
}


void Konto::OdejmijPieniadze(int gotowka) {
    *Saldo = *Saldo - gotowka;

}
void Konto::DodajPieniadze(int gotowka) {
    *Saldo = *Saldo + gotowka;
}
