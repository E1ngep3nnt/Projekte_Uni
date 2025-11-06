//
// Created by Sebastian on 28.09.2025.
//Aufgabe 1.6


#include <windows.h>
#include "std_lib_inc.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

        vector<string> wörter = {"eins", "zwei", "drei", "vier", "fünf"};
        string zahl;
        cout << "Geben sie eine Zahl als Wort ein:\n";
        cin >> zahl;

        int i = 1;
        bool gefunden = false;
        for (const string& wort: wörter) {
            if (zahl == wort) {
                cout << i;
                gefunden = true;
            }
            ++i;
        }
        if (!gefunden) { cout << "Diese Zahl kenne ich nicht\n"; }
        return 0;
    }
