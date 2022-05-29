#include <iostream>
#include "pytanie.h"
#include <string>
#include <windows.h>
using namespace std;

int ogolnie;
int ocena;
float suma = 0;
float procenty;
float start;
float koniec;
float czas;

int main()
{
    //ekran poczatkowy
    cout << "\n\n\t\t\t\tQUIZ"
        << endl;
    cout << "\nwcisnij enter by rozpoczac quiz... "
        << endl;

    // enter
    cin.get();

    //dane
    string imie;
    string nazwisko;

    // wpisywanie danych uczestnika
    cout << "Jak masz na imie?"
        << endl;
    cin >> imie;
    cout << endl;

    cout << "Jak masz na nazwisko?"
        << endl;
    cin >> nazwisko;
    cout << endl;

    //start quizu
    string odpowiedz;
    cout << "Jestes gotow rozpoczac quiz? " << "tak / nie"
        << endl;
    cin >> odpowiedz;

    if (odpowiedz == "tak") {
        cout << endl;
        cout << "Powodzenia!" << endl;
        start = GetTickCount();
    }
    else {
        cout << "Do zobaczenia!" << endl;
        return 0;
    }
    //element przeprowadzajacy quiz
    Pytanie p[5];
    for (int i = 0; i <= 4; i++)
    {
        p[i].nr_pytania = i + 1;
        p[i].wczytaj();
        p[i].zadaj();
        p[i].sprawdz();
        suma += p[i].punkt;
        ogolnie = ogolnie + 1;
    }
    koniec = GetTickCount();
    czas = (koniec - start)/1000;
    //ocenianie
    procenty = (suma / ogolnie)*100;
    if (procenty <= 40) {
        ocena = 1;
    }
    else if (procenty > 40 && procenty <=50) {
        ocena = 2;
    }
    else if (procenty > 50 && procenty <= 70) {
        ocena = 3;
    }
    else if (procenty > 70 && procenty <= 90) {
        ocena = 4;
    }
    else if (procenty > 90 && procenty <= 99) {
        ocena = 5;
    }
    else {
        ocena = 6;
    }

    //podsumowanie quizu
    cout << endl;
    cout << "KONIEC QUIZU!" << endl;
    cout << "Uczestnik: " << imie << " " << nazwisko << endl;
    cout << "Czas trwania quizu: " << czas << " sekund" << endl;
    cout << "Uzyskana liczba punktow: " << suma << endl;
    cout << "Maksymalna liczba punktow: " << ogolnie << endl;
    cout << "Zdobyta liczba procent: " << procenty << "%" <<  endl;
    cout << "Ocena: " << ocena << endl;
    return 0;
}
