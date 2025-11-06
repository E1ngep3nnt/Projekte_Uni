//
// Created by Sebastian on 28.09.2025.
//Aufgabe 1.5


#include <windows.h>
#include "std_lib_inc.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    cout << "Geben sie zwei beliebige Zahlen ein! \n";
    double zahl1 =0.0;
    double zahl2 =0.0;
    cin >> zahl1;
    cin >> zahl2;
    if (zahl1 > zahl2) {
        cout << "Die " <<zahl1 << " ist größer als " <<zahl2<< "\n";
    }
    else {
        cout<< "Die " <<zahl1 << " ist kleiner als " <<zahl2<< "\n";
    }

    double summe =zahl1 +zahl2;
    cout << "Die Summe der Zahlen ist " <<summe <<".\n";

    double differenz =zahl1 -zahl2;
    cout << "Die Differenz der Zahlen ist " <<differenz <<".\n";

    double product =zahl1 * zahl2;
    cout << "Das Produkt der Zahlen ist " <<product <<".\n";

    double quotient = zahl1 / zahl2;
    cout << "Der Quotient der Zahlen ist " <<quotient <<".\n";


    return 0;
}
