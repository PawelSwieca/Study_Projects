//
// Created by Paweł on 10.05.2024.
//

#include "Glon.h"

Glon::Glon() : Organizm(GeneratorLosowy::losujPomiedzy(UST.glonZycieMin, UST.glonZycieMax),
                        UST.glonLimitPosilkow, UST.glonKosztPotomka),
               Mieszkaniec(UST.znakGlon) {}

RodzajMieszkanca Glon::kimJestes() {
    return zywy() ? GLON : TRUP;
}

Mieszkaniec *Glon::dajPotomka() {
    Mieszkaniec *m = nullptr;
    if (potomek()) m = new Glon();
    return m;
}

void Glon::przyjmijZdobycz(Mieszkaniec *mieszkaniec) {
    if (mieszkaniec != nullptr) delete mieszkaniec;
}

ZamiarMieszkanca Glon::wybierzAkcje(Sasiedztwo sasiedztwo) {
    krokSymulacji();

    if (zywy() && paczkujacy() && sasiedztwo.ile(PUSTKA) > 0)
        return ZamiarMieszkanca(POTOMEK, sasiedztwo.losujSasiada(PUSTKA));

    if (zywy() && glodny()) posilek();

    if (!zywy() && symbol != UST.znakTrup)
        symbol = UST.znakTrup;

    return ZamiarMieszkanca();
}