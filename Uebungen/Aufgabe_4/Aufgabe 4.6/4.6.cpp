//
// Created by sebib on 20.11.2025.
//
#include "std_lib_inc.h"

void aufteilen(int summe, vector<int> unterteilung, string bezeichnung);

int main() {
    int cents = 0;

    cout << "Gebe einen Geldbetrag in Cent ein" << '\n';
    cin >> cents;

    if (!cin) {
        simple_error("Keine richtige Eingabe");
    }

    cout << "Der Centbetrag kann in folgende Werte gewechselt werden: " << '\n';

    vector<int> unterteilung = {50, 20, 10, 5, 2, 1};

    // Euros aufteilen
    aufteilen(cents / 100, unterteilung, "Euro");

    // Cents aufteilen
    cents %= 100;
    aufteilen(cents, unterteilung, "Cents");
}

void aufteilen(int summe, vector<int> unterteilung, string bezeichnung) {
    for(int u : unterteilung) {
        if(summe / u > 0) {
            cout << summe / u << " mal " << u << ' ' << bezeichnung << '\n';
            summe %= u;
        }
    }
}