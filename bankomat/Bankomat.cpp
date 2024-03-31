#include <vector>
#include <iostream>
#include "Bankomat.h"
using namespace std;


Bankomat::Bankomat() :ilosc_banknotow{ 1,1,1,1,1,1,1,1,1 }, typ_banknotu{ 500,200,100,50,20,10,5,2,1 }, suma_salda_bankomatu(0), ilosc_banknotow_przedoperacja{}, saldo_uzytkownika(0), saldo_bankomatu(0), kwota_do_wyplacenia(0), kwota_do_wyplacenia_przedoperacja(0), wybor_wyplaty(0), ilosc_banknotow_wplata(0) {

}
int Bankomat::CzytajSaldo(int saldo_uzytkownika) {
    this->saldo_uzytkownika = saldo_uzytkownika; //do naszej prywatnej zmiennej (po lewej) czytamy to co otrzymujemy z czytajacej metody
    return saldo_uzytkownika;
}
QString Bankomat::WypiszIloscZasobow(){
    QString napis_ilosci;
    napis_ilosci ="Ilosc danych banknotow w bankomacie:\n" "500: "+ QString::number(ilosc_banknotow[0])+"x\n" +"200: "+ QString::number(ilosc_banknotow[1])+"x\n" + "100: "+ QString::number(ilosc_banknotow[2])+"x\n"
                   + "50: "+ QString::number(ilosc_banknotow[3])+"x\n" + "20: "+ QString::number(ilosc_banknotow[4])+"x\n" + "10: "+ QString::number(ilosc_banknotow[5])+"x\n"
                   + "5: "+ QString::number(ilosc_banknotow[6])+"x\n" + "2: "+ QString::number(ilosc_banknotow[7])+"x\n" + "1: "+ QString::number(ilosc_banknotow[8])+"x\n";
    return napis_ilosci;
}
int Bankomat::SumaSaldaBankomatu() {
    suma_salda_bankomatu = 0;
    for (int i = 0; i < 9; i++)
    {
        if(ilosc_banknotow[i]>0)
            suma_salda_bankomatu += (typ_banknotu[i] * ilosc_banknotow[i]);
    }
    return suma_salda_bankomatu;
}
QString Bankomat::SumaSaldaBankomatuWypisz() {
    //cout <<"\nSuma salda bankomatu: " << SumaSaldaBankomatu()<<"\n";
    QString czyszczenie = "";
    czyszczenie = QString::number(SumaSaldaBankomatu());
    return "Saldo bankomatu wynosi: " + czyszczenie;
}

int Bankomat::WyplacPieniadze(int kwota_do_wyplacenia, int kwota_karty) {

    this->kwota_do_wyplacenia = kwota_do_wyplacenia;
    this->kwota_karty = kwota_karty;
    if (kwota_do_wyplacenia <= kwota_karty)
    {
        //sprawdzenie salda bankomatu
        for (int i = 0; i < 9; i++)
        {
            suma_salda_bankomatu = (suma_salda_bankomatu + (typ_banknotu[i] * ilosc_banknotow[i]));
        }

        kwota_do_wyplacenia_przedoperacja = kwota_do_wyplacenia; //zapis kwoty do drugich zmiennych aby je odwtorzyc w razie gdyby zabraklo bankontow w bankomacie
        memcpy(ilosc_banknotow_przedoperacja, ilosc_banknotow, 9 * sizeof(int));

        //proces wydawania kasy
        if (suma_salda_bankomatu >= kwota_do_wyplacenia)
        {

            for (int i = 0; i < 9; i++)
            {
                while ((kwota_do_wyplacenia >= typ_banknotu[i]) && (ilosc_banknotow[i] > 0) && (kwota_do_wyplacenia != 0))
                {
                    kwota_do_wyplacenia = kwota_do_wyplacenia - typ_banknotu[i];
                    ilosc_banknotow[i] = ilosc_banknotow[i] - 1;
                }
            }

            if (kwota_do_wyplacenia != 0)
            {
                //brak srodkow w bankomacie
                //przywrocenie wczesniejszych wartosci
                //kwota_do_wyplacenia = kwota_do_wyplacenia_przedoperacja;
                memcpy(ilosc_banknotow, ilosc_banknotow_przedoperacja, 9 * sizeof(int));
                cout << "\nBrak srodkow na koncie bankomatu!";
                return 0; //
            }
            else if (kwota_do_wyplacenia == 0)
            {
                cout << "\n?rodki zosta?y pomy?lnie wyp?acone! ";
                return kwota_do_wyplacenia_przedoperacja;
            }
        }
    }

    cout << "Kwota do wyplacenia jest wieksza niz kwota karty\n";
    return 0;

}

void Bankomat::WplacPieniadze(int nominal, int ilosc)
{
    for (int i = 0; i < 9; i++)
        if (typ_banknotu[i] == nominal)
            ilosc_banknotow[i] += ilosc;
}

void Bankomat::DodajKonto(const Konto& noweKonto) {
    listakont.push_back(noweKonto);
}

void Bankomat::WypiszWszystkieKonta() {
    // int i = 1;
    for (const auto& konto : listakont) {
        //cout << "\nKonto numer: " << i <<"\n";
        konto.WypiszDaneQT();
        //i++;
    }
}
QString Bankomat::WypiszWszystkieKontaQT() {
    WypiszWszystkieKonta();
    QString tekstWynikowy;
    int i = 1;
    for (const auto& konto : listakont){
        tekstWynikowy =  tekstWynikowy  +"Konto numer: "+QString::number(i) +"." +konto.WypiszDaneQT()  ;
        i++;
    }

    return tekstWynikowy;
}
void Bankomat::WypiszBanknoty() {
    for (int i = 0; i < 9; i++) {
        cout <<"\n"<< typ_banknotu[i];
    }

}
QString Bankomat::WypiszBanknotyQT(){
    return "W bankomacie wystepuja ponizsze nominaly: \n500\n200\n100\n50\n20\n10\n5\n2\n1\n";
}
