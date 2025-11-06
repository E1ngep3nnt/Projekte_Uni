//
// Created by Sebastian on 26.09.2025.
// Aufgabe 1.4


#include <windows.h>
#include "std_lib_inc.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    cout << "Geben Sie eine beliebige Zahl ein. \n";
    int n = 0;
    cin >> n;

    if (!cin) {
        simple_error("Die Eingabe muss eine Zahl sein");
    }
    if (n % 2==0){
        cout << "Die Zahl " <<n<< " ist eine gerade Zahl";
    }
    else  {
        cout << "Die Zahl " <<n<< " ist eine ungerade Zahl";
    }
    return 0;
}