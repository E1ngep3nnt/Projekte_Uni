//
// Created by sebib on 21.11.2025.
//

#include "std_lib_inc.h"

class negativerInput{};
class ueberlauf{};

int zahl =1;
int zahl2 = 1;
int temporaereZahl = 1;
int zaehler = 2;
int eingabe=0;

int Fibbonacci() {
    if (eingabe>=0 && eingabe<32768) {
        while(zaehler<eingabe) {
            temporaereZahl = zahl + zahl2;
            zahl = zahl2;
            zahl2 = temporaereZahl;
            ++zaehler;
        }
        cout << "Die " << zaehler << "-te Fibonacci-Zahl ist: " << zahl2 <<"\n";
    }
    else if (eingabe>=32768) {
        throw ueberlauf{};
    }
    else if (eingabe<=0) {
        throw negativerInput {};
    }
}


int main() {
    cin>>eingabe;
    try {
        Fibbonacci();
    }
    catch (negativerInput&) {
        cout << "Negativer Input\n";
    }
    catch (ueberlauf&) {
     cout << "Ueberlauf bei zu grossen Input\n";
    }
}