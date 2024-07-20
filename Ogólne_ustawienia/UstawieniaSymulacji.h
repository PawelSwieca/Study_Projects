//
// Created by Paweł on 03.05.2024.
//

#ifndef WIRTUALNY_EKOSYSTEM_USTAWIENIASYMULACJI_H
#define WIRTUALNY_EKOSYSTEM_USTAWIENIASYMULACJI_H


class UstawieniaSymulacji {
public:

    const char
            znakGlon = '*',
            znakGrzyb = '#',
            znakBakteria = '@',
            znakTrup = '+',
            znakNieokreslony = '?',
            znakPustaNisza = '_',
            znakSeparator = ' ';

    unsigned short
            glonZycieMin = 5,
            glonZycieMax = 10,
            glonKosztPotomka = 2,
            glonLimitPosilkow = 6,
            grzybZycieMin = 40,
            grzybZycieMax = 60,
            grzybKosztPotomka = 3,
            grzybLimitPosilkow = 30,
            bakteriaZycieMin = 25,
            bakteriaZycieMax = 40,
            bakteriaKosztPotomka = 3,
            bakteriaLimitPosilkow = 10;

    bool poprawnyZnakNiszy(char znak) const;

    bool poprawnySeparator(char znak) const;

private:
    UstawieniaSymulacji() {}

    //UstawieniaSymulacji(UstawieniaSymulacji &);

public:
    static UstawieniaSymulacji & pobierzUstawienia();

    void wyswietl(UstawieniaSymulacji &U);

};


#endif //WIRTUALNY_EKOSYSTEM_USTAWIENIASYMULACJI_H

//UstawieniaSymulacji U1 = UstawieniaSymulacji::pobierzUstawienia();
//UstawieniaSymulacji U2 = UstawieniaSymulacji::pobierzUstawienia();
//UstawieniaSymulacji U3 = UstawieniaSymulacji::pobierzUstawienia();
//
//cout << "Pobranie ustawien 3x" << endl;
//cout << "UST1: "; U1.wyswietl(U1);
//cout << "UST2: "; U2.wyswietl(U2);
//cout << "UST3: "; U3.wyswietl(U3);
//
//cout << endl << "Zmiana wartosci tylko 1x" << endl;
//U2.glonZycieMax = 100;
//cout << "UST1: "; U1.wyswietl(U1);
//cout << "UST2: "; U2.wyswietl(U2);
//cout << "UST3: "; U3.wyswietl(U3);

