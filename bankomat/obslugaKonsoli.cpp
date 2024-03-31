#include "obslugaKonsoli.h"


using namespace std;
/*
void obslugaKonsoli::Glowna() {
    Bankomat bank1;
    Konto karta1, karta2, karta3;
    karta1.WpiszDane("Jan", "Kowalski", "1111", 111, 100);
    karta2.WpiszDane("Piotr", "Lewandowski", "2222", 222, 200);
    bank1.DodajKonto(karta1);
    bank1.DodajKonto(karta2);
    karty.push_back(karta1);
    karty.push_back(karta2);

    cout << "1. Stw?rz konto \n";
    cout << "2. Zaloguj sie do utworzonych \n";
    cin >> wybor;
    if (wybor == 1) {
        karta3.StworzKonto();
        bank1.DodajKonto(karta3);
        karty.push_back(karta3);
    }
    petla1 == 0;
    while (petla1 == 0)
    {
        bank1.WypiszWszystkieKonta();
        cout << "\nWybierz konto do ktorego chcesz sie zalogowac\n";

        cin >> wybor;
        if (wybor > 0 && wybor <= karty.size()) {
            Konto& wybraneKonto = karty[wybor - 1];
            cout << "Wybra?e? konto numer: " << wybor << "\n";
            cout << "Wprowadz numer pin:\n";
            cin >> pin;
            if (pin == wybraneKonto.ZwrocPIN()) {
                cout << "Pomy?lnie zalogowano do konta \n";
                petla = 0;
                while (petla == 0)
                {
                    TekstWyboru();
                    cin >> wybor2;
                    wyjdz = false;

                    switch (wybor2)
                    {
                    case 1:
                        cout << "\n Stan twojego konta to: " << wybraneKonto.ZwrocSALDO();
                        break;
                    case 2:
                        cout << " \nWybra?e? wp?at? pieni?dzy ";
                        cout << "\n Podaj nomina? banknotu, kt?ry chcesz wp?aci?, dost?pne s?: \n";
                        bank1.WypiszBanknoty();
                        cin >> nominal;
                        cout << "Podaj ile banknot?w chcesz wplaci?: \n";
                        cin >> ilosc;
                        wybraneKonto.DodajPieniadze(nominal * ilosc);
                        bank1.WplacPieniadze(nominal, ilosc);
                        cout << "Suma salda bankomatu:" << bank1.SumaSaldaBankomatu();
                        wybraneKonto.ZwrocSALDO();

                        break;
                    case 3:
                        cout << "Podaj kwote do wyplacenia: \n";
                        cin >> kwota;
                        if ((kwota > 0) && (kwota <= wybraneKonto.ZwrocSALDO())) {
                            bank1.SumaSaldaBankomatuWypisz();
                            bank1.WyplacPieniadze(kwota, wybraneKonto.ZwrocSALDO());
                            wybraneKonto.OdejmijPieniadze(kwota);
                            cout << "\nSaldo uzytkownika: \n" << wybraneKonto.ZwrocSALDO();
                            //cout << "\nSuma salda bankomatu po operacji: \n" << bank1.SumaSaldaBankomatu();
                        }
                        else if (kwota > wybraneKonto.ZwrocSALDO())
                            cout << "Kwota jest wieksza od salda uzytkownika! \n";
                        break;
                    case 4:
                        cout << "\n Wybierz do kogo chcesz przela? pieni?dze \n";
                        bank1.WypiszWszystkieKonta();
                        cin >> przelew;
                        if ((przelew < 4) && (przelew > 0)) {
                            Konto& kontoDoPrzelewu = karty[przelew - 1];
                            cout << "\nSaldo: " << wybraneKonto.ZwrocSALDO() << "\n";
                            cout << "\nIle chcesz przelac?";
                            cin >> kwota;
                            if (kwota <= wybraneKonto.ZwrocSALDO()) {
                                wybraneKonto.OdejmijPieniadze(kwota);
                                kontoDoPrzelewu.DodajPieniadze(kwota);
                                cout << "\nSaldo zalogowanego konta po przelewie:" << wybraneKonto.ZwrocSALDO();
                                cout << "\nSaldo drugiego konta po przelewie: " << kontoDoPrzelewu.ZwrocSALDO() << "\n";
                            }
                            else
                                cout << "\n Wybra?e? z?? liczb?!\n";
                        }
                        break;
                    case 5:
                        bank1.SumaSaldaBankomatuWypisz();
                        break;
                    case 6:
                        petla = 1;
                        break;
                    }
                }
            }
            else
                cout << "\nWprowadziles b??dny pin, Wybierz konto ponownie! \n"; //czy chcesz sprobowac ponownie? dac licznik ktory liczy proby pinu
        }
        else
            cout << "\nNieprawid?owy wyb?r. Wybierz ponownie!\n";

    }
}

void obslugaKonsoli::TekstWyboru() {
    cout << "\n Wybierz co chcesz zrobi??";
    cout << "\n 1. Sprawd? stan konta";
    cout << "\n 2. Wp?a? pieniadz?";
    cout << "\n 3. Wyp?a? pieniadz?";
    cout << "\n 4. Przelej pieniadz?";
    cout << "\n 5. Sprawd? saldo bankomatu";
    cout << "\n 6. Wyloguj\n";
}
*/
