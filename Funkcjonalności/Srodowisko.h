//
// Created by Paweł on 30.05.2024.
//

#ifndef WIRTUALNY_EKOSYSTEM_SRODOWISKO_H
#define WIRTUALNY_EKOSYSTEM_SRODOWISKO_H

#include "Nisza.h"
#include "GeneratorLosowy.h"
#include "../Ogólne_ustawienia/Ustawienia.h"
#include <string>
#include <fstream>
#include <sstream>
#include "../Organizmy/Bakteria.h"
#include "../Organizmy/Grzyb.h"
#include "../Organizmy/Glon.h"

class Nisza;

class Mieszkaniec;

class Sasiedztwo;


class Srodowisko {

public:
    const unsigned int wiersze, kolumny;
    const unsigned long liczbaNisz;

private:
    friend class Nisza;

    Nisza **nisza;

public:
    Srodowisko(unsigned int _wiersze, unsigned int _kolumny);

    ~Srodowisko();

    void lokuj(Mieszkaniec *mieszkaniec, unsigned int wiersz, unsigned int kolumna);

    Sasiedztwo ustalSasiedztwo(unsigned int wiersz, unsigned int kolumna) const;

    unsigned long liczba(RodzajMieszkanca rodzaj) const;

    bool martwy();

    void wykonajSkok(unsigned int wiersz, unsigned int kolumna);

    void wykonajAkcje(unsigned int wiersz, unsigned int kolumna);

    void wykonajKrokSymulacji();

    std::string doTekstu() const;

    void operator++(int) { wykonajKrokSymulacji(); }

    bool operator!() { return !martwy(); }

    static Srodowisko czytajZPliku(std::string nazwaPliku);

};

std::ostream &operator<<(std::ostream &strumien, const Srodowisko &srodowisko);

#endif //WIRTUALNY_EKOSYSTEM_SRODOWISKO_H
