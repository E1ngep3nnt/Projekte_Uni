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
    string waehrung;

    cout << "Gib einen Wert ein: \n";
    cin >> zahl;
    cout << "Gib die Waehrung ein (y, k, p, d): \n";
    char geld;
    cin >> geld;

    double wertIneuro = 0.0;

    switch (geld) {
        case 'y':{
            wertIneuro = zahl * yenIneuro;
            waehrung = "Yen";
            cout << zahl << " " << waehrung  << " = " << wertIneuro << " Euro\n";
            break;
        }

        case 'k':{
            wertIneuro = zahl * kronenIneuro;
            waehrung = "Kronen";
            cout << zahl << " " << waehrung  << " = " << wertIneuro << " Euro\n";
            break;
        }
        case 'p':{
            wertIneuro = zahl * pfundIneuro;
            waehrung = "Pfund";
            cout << zahl << " " << waehrung  << " = " << wertIneuro << " Euro\n";
            break;
        }
        case 'd': {
            wertIneuro = zahl * dollarIneuro;
            waehrung = "Dollar";
            cout << zahl << " " << waehrung  << " = " << wertIneuro << " Euro\n";
            break;
        }
        default: {
            cout << "Unbekannte Waehrung.\n";
            return 1;
        }
    }
}