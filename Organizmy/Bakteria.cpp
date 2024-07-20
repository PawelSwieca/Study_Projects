//
// Created by Paweł on 10.05.2024.
//

#include "Bakteria.h"

Bakteria::Bakteria() :
        Organizm(GeneratorLosowy::
                 losujPomiedzy(UST.bakteriaZycieMin, UST.bakteriaZycieMax),
                 UST.bakteriaLimitPosilkow, UST.bakteriaKosztPotomka),
        Mieszkaniec(UST.znakBakteria) {}

RodzajMieszkanca Bakteria::kimJestes() {
    return zywy() ? BAKTERIA : TRUP;
}

Mieszkaniec *Bakteria::dajPotomka() {
    Mieszkaniec *m = nullptr;
    if (potomek()) m = new Bakteria();
    return m;
}

void Bakteria::przyjmijZdobycz(Mieszkaniec *mieszkaniec) {
    if (mieszkaniec != nullptr) {
        RodzajMieszkanca r = mieszkaniec->kimJestes();
        if (r == GLON || r == GRZYB) posilek();
        delete mieszkaniec;
    }
}

ZamiarMieszkanca Bakteria::wybierzAkcje(Sasiedztwo sasiedztwo) {
    krokSymulacji();

    if (zywy() && paczkujacy() && sasiedztwo.ile(PUSTKA) > 0)
        return ZamiarMieszkanca(POTOMEK, sasiedztwo.losujSasiada(PUSTKA));

    if (zywy() && glodny() && sasiedztwo.ile(GLON) > 0)
        return ZamiarMieszkanca(POLOWANIE, sasiedztwo.losujSasiada(GLON));

    if (zywy() && glodny() && sasiedztwo.ile(BAKTERIA) > 0)
        return ZamiarMieszkanca(POLOWANIE, sasiedztwo.losujSasiada(BAKTERIA));

    if (!zywy() && symbol != UST.znakTrup)
        symbol = UST.znakTrup;

    return ZamiarMieszkanca();
}