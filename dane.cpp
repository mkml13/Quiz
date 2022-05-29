#include <iostream>
#include "dane.h"
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

void Dane::podaj()
{
    cout << "Jak masz na imie?" << endl;
    cin >> imie;
    cout << endl;
    cout << "Jak masz na nazwisko?" << endl;
    cin >> nazwisko;
    cout << endl;
}

