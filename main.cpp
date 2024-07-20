#include <fstream>
#include <iostream>
#include "windows.h"
#include "Funkcjonalności/Nisza.h"
#include "Organizmy/Bakteria.h"
#include "Organizmy/Glon.h"
#include "Organizmy/Grzyb.h"

using namespace std;

void Clear(){
    COORD topLeft  = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
            console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
            console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
            screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
}

int main() {
    Srodowisko ekoSystem=Srodowisko::czytajZPliku("start.txt");
     ofstream plikWynikowy("symulacja.txt");
     if(!plikWynikowy.is_open()) return 1;
     string stanSymulacji;


    unsigned long i = 0;
    while (i < 200 && !ekoSystem){
        Clear();
        //system("cls");
        cout << "Krok symulacji: " << i << endl;
        plikWynikowy << "Krok symulacji: " << i << endl;
        stanSymulacji = ekoSystem.doTekstu();

        cout << endl << stanSymulacji << endl;
        plikWynikowy << stanSymulacji << endl;

        cin.ignore(1);
        ekoSystem++;
        i++;

    }
    plikWynikowy.close();
    cout << endl;
    return 0;
}