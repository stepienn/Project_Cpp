#pragma once
#include "Bankomat.h"
#include "Konto.h"
#include <vector>
#include <string>
#include <iostream>
//#include <stdlib.h>
class obslugaKonsoli
{
private:
    bool wyjdz = false;
    int wybor2;
    void TekstWyboru();
    int nominal;
    int ilosc;
    int przelew;
    int petla;
    int petla1;
public:
    void Glowna();
    string nr_konta; //wprowadzenia
    int pin, wybor; //wprowadzenia
    vector<Konto> karty;
    int kwota;
    //POZNIEJ SPROBOWAC ZMEINIC
};

