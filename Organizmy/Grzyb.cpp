//
// Created by Paweł on 10.05.2024.
//

#include "Grzyb.h"

Grzyb::Grzyb() :
        Organizm(GeneratorLosowy::
                 losujPomiedzy(UST.grzybZycieMin, UST.grzybZycieMax),
                 UST.grzybLimitPosilkow, UST.grzybKosztPotomka),
        Mieszkaniec(UST.znakGrzyb) {}

RodzajMieszkanca Grzyb::kimJestes() {
    return zywy() > 0 ? GRZYB : TRUP;
}

Mieszkaniec *Grzyb::dajPotomka() {
    Mieszkaniec *m = nullptr;
    if (potomek()) m = new Grzyb();
    return m;
}

void Grzyb::przyjmijZdobycz(Mieszkaniec *mieszkaniec) {
    if (mieszkaniec != nullptr) {
        if (mieszkaniec->kimJestes() == TRUP) posilek();
        delete mieszkaniec;
    }
}

ZamiarMieszkanca Grzyb::wybierzAkcje(Sasiedztwo sasiedztwo) {
    krokSymulacji();

    if (zywy() && paczkujacy() && sasiedztwo.ile(PUSTKA) > 0)
        return ZamiarMieszkanca(POTOMEK, sasiedztwo.losujSasiada(PUSTKA));

    if (zywy() && glodny() && sasiedztwo.ile(TRUP) > 0)
        return ZamiarMieszkanca(ROZKLAD, sasiedztwo.losujSasiada(TRUP));

    if (!zywy() && symbol != UST.znakTrup)
        symbol = UST.znakTrup;

    return ZamiarMieszkanca();
}
