cmake_minimum_required(VERSION 3.28)
project(Wirtualny_ekosystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(Wirtualny_ekosystem main.cpp
        Organizmy/Organizm.cpp
        Organizmy/Organizm.h
        Ogólne_ustawienia/UstawieniaSymulacji.cpp
        Ogólne_ustawienia/UstawieniaSymulacji.h
        Funkcjonalności/Sasiedztwo.cpp
        Funkcjonalności/Sasiedztwo.h
        Ogólne_ustawienia/Ustawienia.h
        Funkcjonalności/GeneratorLosowy.cpp
        Funkcjonalności/GeneratorLosowy.h
        Funkcjonalności/Mieszkaniec.cpp
        Funkcjonalności/Mieszkaniec.h
        Organizmy/Glon.cpp
        Organizmy/Glon.h
        Organizmy/Grzyb.cpp
        Organizmy/Grzyb.h
        Organizmy/Bakteria.cpp
        Organizmy/Bakteria.h
        Funkcjonalności/Nisza.cpp
        Funkcjonalności/Nisza.h
        Funkcjonalności/Srodowisko.cpp
        Funkcjonalności/Srodowisko.h)
