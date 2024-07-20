//
// Created by Paweł on 03.05.2024.
//
#include <iostream>
#include "UstawieniaSymulacji.h"

UstawieniaSymulacji & UstawieniaSymulacji::pobierzUstawienia() {
    static UstawieniaSymulacji ustawienia;
    return ustawienia;
}

void UstawieniaSymulacji::wyswietl(UstawieniaSymulacji &U) {
    std::cout << "Znak glon:" << U.znakGlon
              << " zycieMin=" << U.glonZycieMin
              << " zycieMax=" << U.glonZycieMax << "\n";
}

bool UstawieniaSymulacji::poprawnyZnakNiszy(char znak) const {
    return znak == znakGlon ||
           znak == znakGrzyb ||
           znak == znakBakteria ||
           znak == znakTrup ||
           znak == znakPustaNisza;

}

bool UstawieniaSymulacji::poprawnySeparator(char znak) const {
    return znak == znakSeparator;
}