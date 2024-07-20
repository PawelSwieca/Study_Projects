//
// Created by Paweł on 03.05.2024.
//

#ifndef WIRTUALNY_EKOSYSTEM_SASIEDZTWO_H
#define WIRTUALNY_EKOSYSTEM_SASIEDZTWO_H

#include "../Ogólne_ustawienia/Ustawienia.h"
#include "GeneratorLosowy.h"
#include "Sasiedztwo.h"
#include <string>

class Sasiedztwo {
private:
    RodzajMieszkanca sasiad[3][3];

    RodzajMieszkanca *elementWewnetrzny(Polozenie polozenie);

    static Polozenie losujPolozenie();

public:
    Sasiedztwo(RodzajMieszkanca rodzaj = NIEZNANE);

    void okreslSasiada(Polozenie polozenie, RodzajMieszkanca rodzaj);

    RodzajMieszkanca ktoJestSasiadem(Polozenie polozenie);

    unsigned short ile(RodzajMieszkanca rodzaj) const;

    Polozenie losujSasiada(RodzajMieszkanca rodzaj);

    static void zmienIdeksyWgPolozenia(Polozenie polozenie, long &wiersz, long &kolumna);

    static void zmienIdeksyWgPolozenia(Polozenie polozenie, unsigned int &wiersz, unsigned int &kolumna);


};
//Sasiedztwo sasiedztwo;
//
//sasiedztwo.okreslSasiada(P, GLON);
//sasiedztwo.okreslSasiada(PG, GRZYB);
//sasiedztwo.okreslSasiada(G, GRZYB);
//sasiedztwo.okreslSasiada(LG, GLON);
//sasiedztwo.okreslSasiada(L, BAKTERIA);
//sasiedztwo.okreslSasiada(LD, BAKTERIA);
//sasiedztwo.okreslSasiada(D, GLON);
//sasiedztwo.okreslSasiada(PD, PUSTKA);
//
//cout << "Przeglad sasiedztwa:" << endl;
//
//for (int i = 0; i < 8; i++) {
//Polozenie p = static_cast<Polozenie>(i);
//
//RodzajMieszkanca r = sasiedztwo.ktoJestSasiadem(p);
//
//cout << "polozenie = " << p << " rodzaj = "<< nazwaRodzaju(r) << endl;
//}
//
//cout << endl << "Policzenie sasiadow " << "okreslonego rodzaju:" << endl << " glony=" << sasiedztwo.
//ile(GLON)
//<< endl
//<< " grzyby=" << sasiedztwo.
//ile(GRZYB)
//<< endl
//<< " trupy=" << sasiedztwo.
//ile(TRUP)<<endl
//<< " bakterie="<<sasiedztwo.ile(BAKTERIA)<<endl;
//
//cout << endl << "Wylosowanie sasiada:" << endl << " glon -> " << sasiedztwo.
//losujSasiada(GLON)
//<< endl
//<< " pustka -> "
//<< sasiedztwo.
//losujSasiada(PUSTKA)
//<< endl
//<< " trup -> "
//<< sasiedztwo.
//losujSasiada(TRUP)
//<<
//endl;
//long wiersz, kolumna;
//cout << endl
//<< "Zmiana indeksow [5][7] "
//<< "wg polozenia:" <<
//endl;
//for (int i = 0; i < 8; i++) {
//Polozenie p = static_cast<Polozenie>(i);
//wiersz = 5;
//kolumna = 7;
//Sasiedztwo::zmienIdeksyWgPolozenia(p, wiersz, kolumna);
//cout << " polozenie: " << p << " ->[" << wiersz << "][" << kolumna << "]" << endl;
//}
//do main:
//std::string nazwaRodzaju(RodzajMieszkanca rodzaj) {
//    switch (rodzaj) {
//        case GLON:
//            return "GLON";
//        case GRZYB:
//            return "GRZYB";
//        case BAKTERIA:
//            return "BAKTERIA";
//        case PUSTKA:
//            return "PUSTKA";
//        case SCIANA:
//            return "SCIANA";
//        case TRUP:
//            return "TRUP";
//        case NIEZNANE:
//            return "NIEZNANE";
//    }}
#endif //WIRTUALNY_EKOSYSTEM_SASIEDZTWO_H
