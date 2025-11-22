//
// Created by sebib on 21.11.2025.
//

#include "std_lib_inc.h"

int main() {
    activateAssertions();
    int n=0;
    int zahl = 1;
    int zahl2 = 1;
    int temporaereZahl = 1;
    int zeahler = 2;
    cin>> n;


    while(zahl <= numeric_limits<int>::max() - zahl2) {
        temporaereZahl = zahl + zahl2;
        zahl = zahl2;
        zahl2 = temporaereZahl;
        ++zeahler;
    }

    cout << "Die groesste Fibonacci-Zahl, die noch in 'int' passt ist: " << zahl2 << '\n';
    cout << "Dies ist die " << zeahler << "-te Fibonacci-Zahl.\n";
}