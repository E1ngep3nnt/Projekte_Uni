//
// Created by Sebastian on 28.09.2025.
//Aufgabe 1.6


#include <windows.h>
#include "std_lib_inc.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    map<string, int> Zahlenwort = {
        {"eins", 1},
        {"zwei", 2},
        {"drei", 3},
        {"vier", 4},
        {"fünf", 5}
    };
cout << "Bitte gibt ein Zahlenwort ein\n";
    string zahlenwort_eingabe;
    cin >> zahlenwort_eingabe;

if (Zahlenwort.find(zahlenwort_eingabe) == Zahlenwort.end()) {
    cout << "Diese Zahl kenne ich nicht!\n";
}
    else{
    cout<<"Die Zahl ist " <<Zahlenwort[zahlenwort_eingabe]<<".\n";
}

    return 0;
}