//
// Created by Paweł on 10.05.2024.
//

#ifndef WIRTUALNY_EKOSYSTEM_GLON_H
#define WIRTUALNY_EKOSYSTEM_GLON_H


#include "Organizm.h"
#include "../Funkcjonalności/Mieszkaniec.h"

class Glon : protected Organizm, public Mieszkaniec {
public:
    Glon();

    virtual RodzajMieszkanca kimJestes() final;

    virtual ZamiarMieszkanca wybierzAkcje(Sasiedztwo sasiedztwo);


    virtual Mieszkaniec *dajPotomka();

    virtual void przyjmijZdobycz(Mieszkaniec *mieszkaniec);

};


#endif //WIRTUALNY_EKOSYSTEM_GLON_H
