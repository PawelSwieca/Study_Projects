//
// Created by Paweł on 03.05.2024.
//

#include "Organizm.h"


Organizm::Organizm(unsigned short dlugoscZycia, unsigned short limitPosilkow, unsigned short kosztPotomka)
        : licznikPosilkow(0), licznikZycia(dlugoscZycia), kosztPotomka(kosztPotomka), limitPosilkow(limitPosilkow) {}

bool Organizm::posilek() {
    if (glodny()) {
        licznikPosilkow++;
        return true;
    } else return false;
}

bool Organizm::potomek() {
    if (paczkujacy()) {
        licznikPosilkow -= kosztPotomka;
        return true;
    } else return false;
}

void Organizm::krokSymulacji() {
    if(zywy())
        licznikZycia--;
}