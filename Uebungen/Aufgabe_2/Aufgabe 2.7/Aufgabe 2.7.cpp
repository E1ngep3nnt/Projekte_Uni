//
// Created by sebib on 29.09.2025.
// Aufgabe 1.7

#include <windows.h>
#include "std_lib_inc.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    cout << "schreiben sie ein wort! \n";
    vector <string> unzulässig = {"Brokkoli","Bratwurst","Champignons"};
    string wort;

    while (getline (cin,wort )) {
        bool gefunden=false;
        for (const auto& element: unzulässig) {
            if (wort== element){
                gefunden = true;
                break;
            }
        }
        if (gefunden) {
            cout << "BEEP \n";
        }
        else {
            cout <<wort<< "\n";
        }
    }
}