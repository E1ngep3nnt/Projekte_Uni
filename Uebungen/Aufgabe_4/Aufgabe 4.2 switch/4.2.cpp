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
    cin >> waehrung;

    double wertIneuro = 0.0;

    switch (waehrung){
        case 'y':
        wertIneuro = zahl * yenIneuro;
        waehrung = "Yen";
    }
  case
        wertIneuro = zahl * kronenIneuro;
        waehrung = "Kronen";
    }
    else if (waehrung == "p") {
        wertIneuro = zahl * pfundIneuro;
        waehrung = "Pfund";
    }
    else if (waehrung == "d") {
        wertIneuro = zahl * dollarIneuro;
        waehrung = "Dollar";
    }
    else {
        cout << "Unbekannte Waehrung.\n";
        return 1;
    }

    cout << zahl << " " << waehrung  << " = " << wertIneuro << " Euro\n";
    return 0;
}