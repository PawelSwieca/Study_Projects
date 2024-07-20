//
// Created by Paweł on 03.05.2024.
//

#ifndef WIRTUALNY_EKOSYSTEM_ORGANIZM_H
#define WIRTUALNY_EKOSYSTEM_ORGANIZM_H


#include "../Ogólne_ustawienia/UstawieniaSymulacji.h"
#include "../Funkcjonalności/GeneratorLosowy.h"
#include "../Funkcjonalności/Sasiedztwo.h"

class Organizm {
public:
    const unsigned short limitPosilkow;
    const unsigned short kosztPotomka;

private:
    unsigned short licznikZycia;
    unsigned short licznikPosilkow;

public:
    Organizm(unsigned short dlugoscZycia, unsigned short limitPosilkow, unsigned short kosztPotomka);

    bool zywy() const { return licznikZycia > 0; }

    bool glodny() const { return zywy() && licznikPosilkow < limitPosilkow; }

    bool paczkujacy() const { return zywy() && licznikPosilkow > kosztPotomka; }

    unsigned short stanLicznikaZycia() const { return licznikZycia; }

    unsigned short stanLicznikaPosilkow() const { return licznikPosilkow; }

    bool posilek();

    bool potomek();

    void krokSymulacji();

};
static const UstawieniaSymulacji & UST = UstawieniaSymulacji::pobierzUstawienia();

#endif //WIRTUALNY_EKOSYSTEM_ORGANIZM_H

//void drukujOrganizm(const Organizm o) {
//    cout << "licznikZycia: "
//         << o.stanLicznikaZycia()
//         << " licznikPosilkow: "
//         << o.stanLicznikaPosilkow() << endl
//         << "limitPosilkow: "
//         << o.limitPosilkow
//         << " kosztPotomka: "
//         << o.kosztPotomka << endl
//         << "glodny: " << o.glodny()
//         << " paczkujacy: "
//         << o.paczkujacy() << endl << endl;
//}


//Organizm organizm1(8, 3, 2);
//Organizm organizm2 = organizm1;
//Organizm organizm3(organizm1);
//
//cout << "Wynik testu kreacji obiektow:"
//<< endl << endl;
//cout << "Organizm1:" << endl;
//drukujOrganizm(organizm1);
//cout << "Organizm2" << endl;
//drukujOrganizm(organizm1);
//cout << "Organizm3" << endl;
//drukujOrganizm(organizm2);
//
////2. Test niezależności obiektów
//organizm1.posilek();
//organizm1.posilek();
//organizm2.posilek();
//organizm3.krokSymulacji();
//
//cout << "Wynik testu niezalezności obiektow:"
//<< endl << endl;
//cout << "Organizm1:" << endl;
//drukujOrganizm(organizm1);