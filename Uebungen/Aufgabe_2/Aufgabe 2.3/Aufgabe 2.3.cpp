//
// Created by Sebastian on 26.09.2025.
//Aufgabe 1.3

#include <windows.h>
#include "std_lib_inc.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    cout << "Bitte gib deinen Namen und dein Alter ein\n";
    string name; // Zeichenketten-Variable
    double alter = 0.0; // Ganzzahlige Variable
    cin >> name; // Lies Zeichenkette
    cin >> alter; // Lies ganze Zahl
    string c1 = std::to_string(alter * 12);
    if (!cin) {
        simple_error("Die Eingabe konnte nicht gelesen werden!");
    }
    cout << "Hallo " << name << " (Alter " << c1 << " Monate)\n";

    return 0;
}
