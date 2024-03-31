    #include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Konto.h"
#include "Bankomat.h"

int stateWPLAC = 0;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , wybraneKonto(nullptr)
    , kontoDoPrzelewu(nullptr)

{

    karta1.WpiszDane("Jan", "Kowalski", "1111", 111, 100);
    karta2.WpiszDane("Piotr", "Lewandowski", "2222", 222, 200);

    bank1.DodajKonto(karta1);
    bank1.DodajKonto(karta2);
    karty.push_back(karta1);
    karty.push_back(karta2);
    QWidget::setWindowTitle("BANKOMAT");

    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked,this, &MainWindow::Loguj);
    connect(ui->pushButton_2, &QPushButton::clicked,this, &MainWindow::UtworzUzytkownikaZacznij);
    connect(ui->pushButton_5 ,&QPushButton::clicked,this, &MainWindow::SprawdzSaldoBankomatu);


    connect(ui->pushButton_8, &QPushButton::clicked,this, &MainWindow::PrzeslijKonto);
    connect(ui->pushButton_9, &QPushButton::clicked,this, &MainWindow::SprawdzStanKonta);
    connect(ui->pushButton_10, &QPushButton::clicked,this, &MainWindow::PodajPin);
    connect(ui->pushButton_11, &QPushButton::clicked,this, &MainWindow::WplacPieniadze);
    connect(ui->pushButton_12, &QPushButton::clicked,this, &MainWindow::Wyloguj);
    connect(ui->pushButton_13, &QPushButton::clicked,this, &MainWindow::ZacznijWplacPieniadze);
    connect(ui->pushButton_14, &QPushButton::clicked,this, &MainWindow::WyplacPieniadze);
    connect(ui->pushButton_15, &QPushButton::clicked,this, &MainWindow::ZacznijWyplacPieniadze);
    connect(ui->pushButton_16, &QPushButton::clicked,this, &MainWindow::ZacznijPrzelew);
    connect(ui->pushButton_17, &QPushButton::clicked,this, &MainWindow::WTrakciePrzelew);
    connect(ui->pushButton_18, &QPushButton::clicked,this, &MainWindow::Przelew);
    connect(ui->pushButton_19, &QPushButton::clicked,this, &MainWindow::Powrot);

    connect(ui->pushButton_7 ,&QPushButton::clicked,this, &MainWindow::WyslijImie);
    connect(ui->pushButton_26, &QPushButton::clicked,this, &MainWindow::WyslijNazwisko);
    connect(ui->pushButton_27, &QPushButton::clicked,this, &MainWindow::WyslijNrKonta);
    connect(ui->pushButton_28, &QPushButton::clicked,this, &MainWindow::WyslijNrPin);
    connect(ui->pushButton_29, &QPushButton::clicked,this, &MainWindow::WyslijSaldoPoczatkowe);
    connect(ui->pushButton_30, &QPushButton::clicked,this, &MainWindow::UtworzenieKontaZpodanych);

    ui->pushButton->show();
    ui->pushButton_2->show();
    ui->pushButton_5->hide();
    ui->wczytajTekst->show();
    ui->pushButton_7->show();
    ui->pushButton_8->hide();
    ui->pushButton_9->hide();
    ui->pushButton_10->hide();
    ui->pushButton_11->hide();
    ui->pushButton_12->hide();
    ui->pushButton_13->hide();
    ui->pushButton_14->hide();
    ui->pushButton_15->hide();
    ui->pushButton_16->hide();
    ui->pushButton_17->hide();
    ui->pushButton_18->hide();
    ui->pushButton_19->hide();

    ui->wczytajTekst->hide();
    ui->pushButton_7->hide();
    ui->pushButton_26->hide();
    ui->pushButton_27->hide();
    ui->pushButton_28->hide();
    ui->pushButton_29->hide();
    ui->pushButton_30->hide();
    ui->wczytajIlosc->hide();

    ui->label_3->hide();

    // ui->button_7->hide();


}

void MainWindow::Loguj(){
    // ui->oknoText->setText("");

    ui->oknoText->append("\n");
    bank1.WypiszWszystkieKontaQT();
    ui->oknoText->append(bank1.WypiszWszystkieKontaQT());

    ui->oknoText->append("\nWprowadź numer konta, do którego chcesz się zalogować: ");

    ui->pushButton->hide();
    ui->pushButton_2->hide();

    ui->pushButton_5->hide();

    ui->pushButton_7->hide();
    ui->pushButton_8->show();
    ui->pushButton_9->hide();
    ui->pushButton_10->hide();
    ui->pushButton_11->hide();
    ui->pushButton_12->hide();
    ui->pushButton_13->hide();
    ui->pushButton_14->hide();
    ui->pushButton_15->hide();
    ui->pushButton_16->hide();
    ui->pushButton_17->hide();
    ui->pushButton_18->hide();


    ui->wczytajTekst->hide();
    ui->pushButton_7->hide();
    ui->pushButton_26->hide();
    ui->pushButton_27->hide();
    ui->pushButton_28->hide();
    ui->pushButton_29->hide();
    ui->pushButton_30->hide();
    ui->wczytajIlosc->hide();
    ui->wczytajIlosc->hide();
    ui->label_3->hide();

}
void MainWindow::PrzeslijKonto(){
    QString wyborKonta;
    wyborKonta = ui->wczytajLiczby->toPlainText();
    if(wyborKonta.toInt() == NULL){
        ui->oknoText->append("-----------------------");
        ui->oknoText->append("Wprowadź liczbę");
    }
    else if((wyborKonta.toInt() )<4){
        ui->wczytajLiczby->setText("");
        ui->oknoText->setText("\nWybraleś konto numer: " + wyborKonta);
        wybraneKonto = &karty[wyborKonta.toInt() -1];
        ui->oknoText->append(wybraneKonto->WypiszDaneQT());
        ui->oknoText->append("Podaj pin: ");

        ui->pushButton->hide();
        ui->pushButton_2->hide();


        ui->pushButton_5->hide();

        ui->pushButton_7->hide();
        ui->pushButton_8->hide();
        ui->pushButton_9->hide();
        ui->pushButton_10->show();
        ui->pushButton_11->hide();
        ui->pushButton_12->hide();
        ui->pushButton_13->hide();
        ui->pushButton_14->hide();
        ui->pushButton_15->hide();
        ui->pushButton_16->hide();
        ui->pushButton_17->hide();
        ui->pushButton_18->hide();
        ui->wczytajIlosc->hide();
        ui->label_3->hide();

        ui->wczytajTekst->hide();
        ui->pushButton_7->hide();
        ui->pushButton_26->hide();
        ui->pushButton_27->hide();
        ui->pushButton_28->hide();
        ui->pushButton_29->hide();
        ui->pushButton_30->hide();
        ui->wczytajIlosc->hide();


    }
    else    {
        ui->wczytajLiczby->setText("");
        ui->oknoText->append("Wybrales niepoprawny numer konta, sproboj ponownie!");

    }

}
void MainWindow::PodajPin(){
    ui->oknoText->setText("\n");
    QString podanyPin;
    podanyPin = ui->wczytajLiczby->toPlainText();
    if(podanyPin.toInt() == NULL){

        ui->oknoText->append("Wprowadz pin ponownie");
        ui->pushButton->show();
    }
    else if(podanyPin.toInt() == (wybraneKonto->ZwrocPIN())){
        ZalogowanoPoprawnie();
        ui->wczytajLiczby->setText("");
    }
    else
    {    ui->oknoText->setText("");
        ui->oknoText->append("Wprowadzono nie poprawny pin!");
        ui->oknoText->append("------------------------------------");
        ui->wczytajLiczby->setText("");
        Loguj();
    }
}
void MainWindow::ZalogowanoPoprawnie(){

    if(stanlog == 0){
        ui->oknoText->append("Wprowadzono poprawny pin!\n");
        stanlog++;
    }
    ui->wczytajLiczby->setText("");
    ui->oknoText->append("Wybierz co chcesz zrobić: ");
    ui->oknoText->append("1. Sprawdź stan konta");
    ui->oknoText->append("2. Wpłać pieniądze");
    ui->oknoText->append("3. Wypłać pieniądze");
    ui->oknoText->append("4. Przelej pieniądze");
    ui->oknoText->append("5. Sprawadź saldo bankomatu");
    ui->oknoText->append("6. Wyloguj");
    ui->pushButton->hide();
    ui->pushButton_2->hide();


    ui->pushButton_5->show();

    ui->pushButton_7->hide();
    ui->pushButton_8->hide();
    ui->pushButton_9->show();
    ui->pushButton_10->hide();
    ui->pushButton_11->hide();
    ui->pushButton_12->show();
    ui->pushButton_13->show();
    ui->pushButton_14->hide();
    ui->pushButton_15->show();
    ui->pushButton_16->show();
    ui->pushButton_17->hide();
    ui->pushButton_18->hide();
    ui->pushButton_18->hide();
    ui->pushButton_19->hide();
    ui->wczytajIlosc->hide();
    ui->label_3->hide();

}
void MainWindow::SprawdzStanKonta(){
    ui->oknoText->setText("\n");

    ui->oknoText->setText("\nTwój stan konta wynosi: ");
    ui->oknoText->append(QString::number(wybraneKonto->ZwrocSALDO()));

    ui->pushButton->hide();
    ui->pushButton_2->hide();


    ui->pushButton_5->hide();

    ui->pushButton_7->hide();
    ui->pushButton_8->hide();
    ui->pushButton_9->hide();
    ui->pushButton_10->hide();
    ui->pushButton_11->hide();
    ui->pushButton_12->hide();
    ui->pushButton_13->hide();
    ui->pushButton_14->hide();
    ui->pushButton_15->hide();
    ui->pushButton_16->hide();
    ui->pushButton_17->hide();
    ui->pushButton_18->hide();
    ui->pushButton_19->show();

    ui->wczytajIlosc->hide();
    ui->label_3->hide();

}

void MainWindow::SprawdzSaldoBankomatu(){ //zrobic przed operacja i po operacji
    ui->oknoText->setText("\n");
    ui->oknoText->setText(bank1.SumaSaldaBankomatuWypisz());
    ui->oknoText->append(bank1.WypiszIloscZasobow());
    ui->pushButton->hide();
    ui->pushButton_2->hide();


    ui->pushButton_5->hide();

    ui->pushButton_7->hide();
    ui->pushButton_8->hide();
    ui->pushButton_9->hide();
    ui->pushButton_10->hide();
    ui->pushButton_11->hide();
    ui->pushButton_12->hide();
    ui->pushButton_13->hide();
    ui->pushButton_14->hide();
    ui->pushButton_15->hide();
    ui->pushButton_16->hide();
    ui->pushButton_17->hide();
    ui->pushButton_18->hide();
    ui->pushButton_19->show();

    ui->wczytajIlosc->hide();
    ui->label_3->hide();

}
void MainWindow::UtworzUzytkownikaZacznij(){
    il_kont = 3;
    ui->wczytajTekst->show();
    ui->pushButton_7->show();
    ui->pushButton_26->hide();
    ui->pushButton_27->hide();
    ui->pushButton_28->hide();
    ui->pushButton_29->hide();
    ui->pushButton_30->hide();
    ui->wczytajIlosc->hide();
    ui->wczytajTekst->setText("");
    ui->oknoText->setText("\n");
    ui->oknoText->append("Wybraleś utworzenie użytkownika!");
    ui->oknoText->append("Podaj imie:");


}
void MainWindow::WyslijImie(){


    ImieDodawane = ui->wczytajTekst->toPlainText();
    if(ImieDodawane != ""){
        ui->wczytajTekst->setText("");
        ui->oknoText->setText("");
        ui->oknoText->append("Podaj nazwisko: ");
        ui->wczytajTekst->show();
        ui->pushButton_7->hide();
        ui->pushButton_26->show();
        ui->pushButton_27->hide();
        ui->pushButton_28->hide();
        ui->pushButton_29->hide();
        ui->pushButton_30->hide();
        ui->wczytajIlosc->hide();
    }
    else
        ui->oknoText->append("Wprowadź ponownie ");
}
void MainWindow::WyslijNazwisko(){


    NazwiskoDodawane = ui->wczytajTekst->toPlainText();
    if(NazwiskoDodawane != ""){
        ui->wczytajTekst->setText("");
        ui->oknoText->setText("");
        ui->oknoText->append("Podaj numer konta: ");
        ui->wczytajTekst->show();
        ui->pushButton_7->hide();
        ui->pushButton_26->hide();
        ui->pushButton_27->show();
        ui->pushButton_28->hide();
        ui->pushButton_29->hide();
        ui->pushButton_30->hide();
        ui->wczytajIlosc->hide();
    }
    else
        ui->oknoText->append("Wprowadź ponownie");
}

void MainWindow::WyslijNrKonta(){

    NrKontaDodawane = ui->wczytajTekst->toPlainText();
    if( NrKontaDodawane != ""){
        ui->wczytajTekst->setText("");
        ui->oknoText->setText("");
        ui->oknoText->append("Podaj PIN: ");

        ui->wczytajTekst->show();
        ui->pushButton_7->hide();
        ui->pushButton_26->hide();
        ui->pushButton_27->hide();
        ui->pushButton_28->show();
        ui->pushButton_29->hide();
        ui->pushButton_30->hide();
        ui->wczytajIlosc->hide();
    }
    else
        ui->oknoText->append("Wprowadź ponownie");
}
void MainWindow::WyslijNrPin(){
    ui->wczytajTekst->show();
    ui->pushButton_7->hide();
    ui->pushButton_26->hide();
    ui->pushButton_27->hide();
    ui->pushButton_28->hide();
    ui->pushButton_29->show();
    ui->pushButton_30->hide();
    ui->wczytajIlosc->hide();
    pin_dodawany = ui->wczytajTekst->toPlainText().toInt();
    ui->wczytajTekst->setText("");
    ui->oknoText->setText("");
    ui->oknoText->append("Podaj saldo początkowe ");
}
void MainWindow::WyslijSaldoPoczatkowe(){
    ui->wczytajTekst->show();
    ui->pushButton_7->hide();
    ui->pushButton_26->hide();
    ui->pushButton_27->hide();
    ui->pushButton_28->hide();
    ui->pushButton_29->hide();
    ui->pushButton_30->show();
    ui->wczytajIlosc->hide();
    saldo_dodawane = ui->wczytajTekst->toPlainText().toInt();
    ui->wczytajTekst->setText("");
    ui->oknoText->setText("\n");
    ui->oknoText->append("Zatwierdz konto!");
}
void MainWindow::UtworzenieKontaZpodanych(){
    ui->oknoText->setText("");
    ui->wczytajTekst->show();
    ui->pushButton_7->hide();
    ui->pushButton_26->hide();
    ui->pushButton_27->hide();
    ui->pushButton_28->hide();
    ui->pushButton_29->hide();
    ui->pushButton_30->hide();
    ui->wczytajIlosc->hide();
    ui->wczytajTekst->setText("");
    karta3.WpiszDane(ImieDodawane, NazwiskoDodawane, NrKontaDodawane, pin_dodawany, saldo_dodawane);
    bank1.DodajKonto(karta3);
    karty.push_back(karta3);
    ui->oknoText->setText("");
    Loguj();
}
void MainWindow::SprawdzSaldoBankomatuPOZALOGOWANIU(){
    ui->oknoText->setText("\n");

    ui->oknoText->setText(bank1.SumaSaldaBankomatuWypisz());
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_5->show();
    ui->pushButton_7->hide();
    ui->pushButton_8->hide();
    ui->pushButton_9->hide();
    ui->pushButton_10->hide();
    ui->pushButton_11->hide();
    ui->pushButton_12->hide();
    ui->pushButton_13->show();
    ui->pushButton_14->hide();
    ui->pushButton_15->show();
    ui->pushButton_16->show();
    ui->pushButton_17->hide();
    ui->pushButton_18->hide();
    ui->pushButton_19->show();

    ui->wczytajIlosc->hide();
    ui->label_3->hide();


}
void MainWindow::ZacznijWplacPieniadze(){
    ui->oknoText->setText("\n");
    ui->wczytajIlosc->show();
    ui->wczytajLiczby->setText("");
    ui->oknoText->setText(bank1.WypiszBanknotyQT());
    ui->oknoText->append("\n W głównym oknie podaj jaki nominał chcesz wpłacić");
    ui->oknoText->append("\n W oknie dodatkowym podaj ilość nominałów");

    ui->pushButton->hide();
    ui->pushButton_2->hide();


    ui->pushButton_5->hide();

    ui->pushButton_7->hide();
    ui->pushButton_8->hide();
    ui->pushButton_9->hide();
    ui->pushButton_10->hide();
    ui->pushButton_11->show();
    ui->pushButton_12->hide();
    ui->pushButton_13->hide();
    ui->pushButton_14->hide();
    ui->pushButton_15->hide();
    ui->pushButton_16->hide();
    ui->pushButton_17->hide();
    ui->pushButton_18->hide();
    ui->pushButton_19->show();
    ui->wczytajIlosc->show();
    ui->label_3->show();

}
void MainWindow::WplacPieniadze(){

    ui->oknoText->setText("");

    QString nominal, ilosc;
    int nominal_w, ilosc_w;
    nominal = ui->wczytajLiczby->toPlainText();
    ilosc = ui->wczytajIlosc->toPlainText();
    nominal_w = nominal.toInt();
    ilosc_w = ilosc.toInt();
    if(((ilosc_w > 0))&&((nominal_w == 500) || (nominal_w == 200) || (nominal_w == 100) || (nominal_w == 50) || (nominal_w == 20) || (nominal_w == 10) || (nominal_w == 5) || (nominal_w == 2) || (nominal_w == 1))){


        wybraneKonto->DodajPieniadze(nominal_w * ilosc_w);
        bank1.WplacPieniadze(nominal_w, ilosc_w);

        ui->oknoText->append("\nStan twojego konta po wpłacie: " + QString::number(wybraneKonto->ZwrocSALDO())+"\n");
        ui->oknoText->append("\nSuma salda bankomatu po wypłacie: " + QString::number(bank1.SumaSaldaBankomatu()));
        ui->oknoText->append(bank1.WypiszIloscZasobow());
        bank1.WypiszWszystkieKontaQT();

        ui->pushButton->hide();
        ui->pushButton_2->hide();


        ui->pushButton->hide();
        ui->pushButton_2->hide();
        ui->pushButton_5->hide();
        ui->pushButton_7->hide();
        ui->pushButton_8->hide();
        ui->pushButton_9->hide();
        ui->pushButton_10->hide();
        ui->pushButton_11->hide();
        ui->pushButton_12->hide();
        ui->pushButton_13->hide();
        ui->pushButton_14->hide();
        ui->pushButton_15->hide();
        ui->pushButton_16->hide();
        ui->pushButton_17->hide();
        ui->pushButton_18->hide();
        ui->pushButton_19->show();
        ui->wczytajIlosc->setText("");
        ui->wczytajLiczby->setText("");
        ui->wczytajIlosc->hide();
        ui->label_3->hide();
    }
    else
        ui->oknoText->append("Podaj poprawne wartości");
}

void MainWindow::ZacznijWyplacPieniadze(){
    ui->oknoText->setText("");
    ui->wczytajLiczby->setText("");
    if((wybraneKonto->ZwrocSALDO()) != 0){
        ui->oknoText->append("\nAktualnie posiadasz: "+ QString::number(wybraneKonto->ZwrocSALDO()));
        ui->oknoText->append(bank1.SumaSaldaBankomatuWypisz());
        ui->oknoText->append("\nPodaj kwote do wypłacenia: ");

        ui->pushButton->hide();
        ui->pushButton_2->hide();


        ui->pushButton_5->hide();

        ui->pushButton_7->hide();
        ui->pushButton_8->hide();
        ui->pushButton_9->hide();
        ui->pushButton_10->hide();
        ui->pushButton_11->hide();
        ui->pushButton_12->hide();
        ui->pushButton_13->hide();
        ui->pushButton_14->show();
        ui->pushButton_15->hide();
        ui->pushButton_16->hide();
        ui->pushButton_17->hide();
        ui->pushButton_18->hide();
        ui->pushButton_19->show();

        ui->wczytajIlosc->hide();
        ui->label_3->hide();
    }
    else
        ui->oknoText->append("\nBrak środków na koncie ");


}
void MainWindow::WyplacPieniadze(){
    QString pieniadze;
    int pieniadze_w;
    ui->oknoText->setText("");
    pieniadze = ui->wczytajLiczby->toPlainText();
    pieniadze_w = pieniadze.toInt();
    if((pieniadze_w <= wybraneKonto->ZwrocSALDO()) && (pieniadze_w>0)){
        //przejdz do operacji

        int do_odejmowania = bank1.WyplacPieniadze(pieniadze_w, wybraneKonto->ZwrocSALDO());
        wybraneKonto->OdejmijPieniadze(do_odejmowania);
        if(do_odejmowania == 0)
            ui->oknoText->append("Bankomat nie posiada odpowiednich nominalow do zrealizowania operacji");
        ui->oknoText->append("\nSaldo uzytkownika po operacji: " + QString::number(wybraneKonto->ZwrocSALDO()));
        ui->oknoText->append("\n");
        ui->oknoText->append(bank1.WypiszIloscZasobow());
        ui->pushButton->hide();
        ui->pushButton_2->hide();
        ui->pushButton_5->hide();
        ui->pushButton_7->hide();
        ui->pushButton_8->hide();
        ui->pushButton_9->hide();
        ui->pushButton_10->hide();
        ui->pushButton_11->hide();
        ui->pushButton_12->hide();
        ui->pushButton_13->hide();
        ui->pushButton_14->hide();
        ui->pushButton_15->hide();
        ui->pushButton_16->hide();
        ui->pushButton_17->hide();
        ui->pushButton_18->hide();
        ui->pushButton_19->show();

        ui->wczytajLiczby->setText("");

        ui->wczytajIlosc->hide();
        ui->label_3->hide();


    }
    else //za malo kasy
    {

        ui->oknoText->setText("");
        ui->wczytajLiczby->setText("");
        ui->oknoText->append("\nZa malo srodkow w banku, na koncie, lub niepoprawnie wpisana kwota");
        ui->oknoText->append("------------------------------------------------------\n");
        ui->pushButton->hide();
        ui->pushButton_2->hide();
        ui->pushButton_5->hide();
        ui->pushButton_7->hide();
        ui->pushButton_8->hide();
        ui->pushButton_9->hide();
        ui->pushButton_10->hide();
        ui->pushButton_11->hide();
        ui->pushButton_12->hide();
        ui->pushButton_13->hide();
        ui->pushButton_14->hide();
        ui->pushButton_15->hide();
        ui->pushButton_16->hide();
        ui->pushButton_17->hide();
        ui->pushButton_18->hide();
        ui->pushButton_19->show();
        ui->wczytajIlosc->setText("");
        ui->wczytajLiczby->setText("");
        ui->wczytajIlosc->hide();
        ui->label_3->hide();

    }
}
void MainWindow::ZacznijPrzelew(){

    if((wybraneKonto->ZwrocSALDO()) != 0){
        ui->oknoText->setText("");
        ui->wczytajLiczby->setText("");
        bank1.WypiszWszystkieKontaQT();

        ui->oknoText->append("\nWybierz do kogo chcesz zrobic przelew: ");
        ui->oknoText->append(bank1.WypiszWszystkieKontaQT());
        ui->pushButton->hide();
        ui->pushButton_2->hide();
        ui->pushButton_5->hide();
        ui->pushButton_7->hide();
        ui->pushButton_8->hide();
        ui->pushButton_9->hide();
        ui->pushButton_10->hide();
        ui->pushButton_11->hide();
        ui->pushButton_12->hide();
        ui->pushButton_13->hide();
        ui->pushButton_14->show();
        ui->pushButton_15->hide();
        ui->pushButton_16->hide();
        ui->pushButton_17->show();
        ui->pushButton_18->hide();
        ui->pushButton_19->show();

        ui->wczytajIlosc->hide();
        ui->label_3->hide();

    }
    else{
        ui->oknoText->setText("Nie masz srodkow na koncie");

    }
}
void MainWindow::WTrakciePrzelew(){
    ui->oknoText->setText("");

    QString pobranie;
    int pobranie_w;
    pobranie = ui->wczytajLiczby->toPlainText();
    if(pobranie != ""){
        pobranie_w = pobranie.toInt();
        if(pobranie_w <= il_kont){
            ui->oknoText->append("Konto na ktore chcesz zrealizowac przelew: \n");
            kontoDoPrzelewu = &karty[pobranie_w-1];
            ui->oknoText->append(kontoDoPrzelewu->WypiszDaneQT());
            ui->oknoText->append("\nTwoje saldo aktualnie wynosi: " + QString::number(wybraneKonto->ZwrocSALDO()));
            ui->oknoText->append("\nPodaj kwote przlewu: ");
            ui->pushButton->hide();
            ui->pushButton_2->hide();
            ui->pushButton_5->hide();
            ui->pushButton_7->hide();
            ui->pushButton_8->hide();
            ui->pushButton_9->hide();
            ui->pushButton_10->hide();
            ui->pushButton_11->hide();
            ui->pushButton_12->hide();
            ui->pushButton_13->hide();
            ui->pushButton_14->hide();
            ui->pushButton_15->hide();
            ui->pushButton_16->hide();
            ui->pushButton_17->hide();
            ui->pushButton_18->show();
            ui->pushButton_19->show();
            ui->wczytajLiczby->setText("");

            ui->wczytajIlosc->hide();
            ui->label_3->hide();
        }
        else{
            ui->oknoText->append("Podaj poprawną liczbę!");
            ui->wczytajLiczby->setText("");}
    }
    else{
        ui->oknoText->append("Podaj poprawną liczbę!");
        ui->wczytajLiczby->setText("");}
}
void MainWindow::Przelew(){
    QString kwota_przelew;
    int kwota_przelew_w;
    kwota_przelew = ui->wczytajLiczby->toPlainText();
    kwota_przelew_w = kwota_przelew.toInt();
    if((kwota_przelew_w <= (wybraneKonto->ZwrocSALDO()))&& (kwota_przelew_w >0)){

        wybraneKonto->OdejmijPieniadze(kwota_przelew_w);
        kontoDoPrzelewu->DodajPieniadze(kwota_przelew_w);
        ui->oknoText->setText("");
        ui->oknoText->append("\nNadawca przelwu:");
        ui->oknoText->append(wybraneKonto->WypiszDaneQT());
        ui->oknoText->append("\nOdbiorca przelwu:");
        ui->oknoText->append(kontoDoPrzelewu->WypiszDaneQT());
        ui->wczytajLiczby->setText("");
        ui->pushButton->hide();
        ui->pushButton_2->hide();
        ui->pushButton_5->hide();
        ui->pushButton_7->hide();
        ui->pushButton_8->hide();
        ui->pushButton_9->hide();
        ui->pushButton_10->hide();
        ui->pushButton_11->hide();
        ui->pushButton_12->hide();
        ui->pushButton_13->hide();
        ui->pushButton_14->hide();
        ui->pushButton_15->hide();
        ui->pushButton_16->hide();
        ui->pushButton_17->hide();
        ui->pushButton_18->hide();
        ui->pushButton_19->show();

        ui->wczytajIlosc->hide();
        ui->label_3->hide();

    }
    else{
        ui->oknoText->append("Nie masz wystarczających środków na koncie, lub wprowadziłeś błędne dane!");
    }

}
void MainWindow::Wyloguj(){
    //wylogowuje calkowicie
    ui->oknoText->setText("");
    ui->wczytajIlosc->setText("");
    ui->wczytajLiczby->setText("");

    ui->pushButton->show();
    ui->pushButton_2->show();


    ui->pushButton_5->hide();

    ui->pushButton_7->show();
    ui->pushButton_8->show();
    ui->pushButton_9->hide();
    ui->pushButton_10->hide();
    ui->pushButton_11->hide();
    ui->pushButton_12->hide();
    ui->pushButton_13->hide();
    ui->pushButton_14->hide();
    ui->pushButton_15->hide();
    ui->pushButton_16->hide();
    ui->pushButton_17->hide();
    ui->pushButton_18->hide();
    ui->pushButton_19->hide();
    ui->wczytajIlosc->hide();
    ui->label_3->hide();


    Loguj();
}
void MainWindow::Powrot(){
    //wraca do menu opcji
    ui->oknoText->setText("");
    ui->wczytajIlosc->setText("");
    ui->wczytajLiczby->setText("");
    ui->wczytajIlosc->hide();
    ui->label_3->hide();

    ZalogowanoPoprawnie();
}

MainWindow::~MainWindow()
{
    delete ui;
}

