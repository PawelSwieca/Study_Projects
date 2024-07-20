//
// Created by Paweł on 10.05.2024.
//

#ifndef WIRTUALNY_EKOSYSTEM_BAKTERIA_H
#define WIRTUALNY_EKOSYSTEM_BAKTERIA_H

#include "Organizm.h"
#include "../Funkcjonalności/Mieszkaniec.h"


class Bakteria : protected Organizm, public Mieszkaniec{
public:
    Bakteria();

    virtual RodzajMieszkanca kimJestes() final;

    virtual ZamiarMieszkanca wybierzAkcje(Sasiedztwo sasiedztwo);

    virtual Mieszkaniec *dajPotomka();

    virtual void przyjmijZdobycz(Mieszkaniec *mieszkaniec);

};


#endif //WIRTUALNY_EKOSYSTEM_BAKTERIA_H
