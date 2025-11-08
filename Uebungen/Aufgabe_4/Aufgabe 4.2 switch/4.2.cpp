//
// Created by Sebastian on 06.11.2025.
//
//
// Created by Sebastian on 06.11.2025.
//

#include "std_lib_inc.h"

int main() {
    double yenIneuro = 0.00578;
    double pfundIneuro = 1.147;
    double dollarIneuro = 0.860;
    double kronenIneuro = 0.0907;
    double zahl;
    string waehrungwort;

    cout << "Gib einen Wert ein: \n";
    cin >> zahl;
    cout << "Gib die Waehrung ein (y, k, p, d): \n";
    char geld;
    cin >> geld;
    int waehrung;

    double wertIneuro = 0.0;
    switch (waehrung) {
        case 'y':{
            wertIneuro = zahl * yenIneuro;
            waehrungwort = "Yen";
            break;

        }
        case 'k': {
            wertIneuro = zahl * kronenIneuro;
            waehrungwort = "Kronen";
            break;
        }
        case 'p': {
            wertIneuro = zahl * pfundIneuro;
            waehrungwort = "Pfund";
            break;
        }
        case 'd': {
            wertIneuro = zahl * dollarIneuro;
            waehrungwort = "Dollar";
            break;
        }
        default:cout << "Unbekannte Waehrung.\n";
            return 1;
    }

    switch (geld) {
        case 'y':{
            cout << zahl << " " << waehrungwort  << " = " << wertIneuro << " Euro\n";
            break;
        }
        case 'k':{
            cout << zahl << " " << waehrungwort  << " = " << wertIneuro << " Euro\n";
            break;
        }
        case 'p':{
            cout << zahl << " " << waehrung  << " = " << wertIneuro << " Euro\n";
            break;
        }
        case 'd': {
            cout << zahl << " " << waehrung  << " = " << wertIneuro << " Euro\n";
            break;
        }
        default: {
            cout << "Unbekannte Waehrung.\n";
            return 1;
        }
    }
}