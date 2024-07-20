//
// Created by Paweł on 10.05.2024.
//

#ifndef WIRTUALNY_EKOSYSTEM_NISZA_H
#define WIRTUALNY_EKOSYSTEM_NISZA_H

#include "Sasiedztwo.h"
#include "Mieszkaniec.h"
#include "Srodowisko.h"


class Nisza {

private:
    Mieszkaniec *lokator;

public:
    Nisza();

    Nisza(Nisza &innaNisza);

    ~Nisza();

    Nisza &operator=(Nisza &innaNisza);

    void przyjmijLokatora(Mieszkaniec *lokatorBezdomny);

    Mieszkaniec *oddajLokatora();

    bool zajeta() const { return lokator != nullptr; }

    RodzajMieszkanca ktoTuMieszka() {
        return zajeta() ? lokator->kimJestes() : PUSTKA;
    }

    bool lokatorZywy() const;

    char jakiSymbol() const;

    //friend class Srodowisko;

private:

    ZamiarMieszkanca aktywujLokatora(Sasiedztwo sasiedztwo){
        return lokator->wybierzAkcje(sasiedztwo);
    }

    Mieszkaniec *wypuscPotomka() {
        return lokator->dajPotomka();
    }

    void przyjmijZdobycz(Mieszkaniec *ofiara) {
        lokator->przyjmijZdobycz(ofiara);
    }

    friend class Srodowisko;

};


#endif //WIRTUALNY_EKOSYSTEM_NISZA_H
