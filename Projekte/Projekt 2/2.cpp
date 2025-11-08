//
// Created by Sebastian on 06.11.2025.
//
#include "std_lib_inc.h"

// Globale Variablen
vector<int> werte={};
constexpr int fenster=10;

// Funktionen
vector<int> werteLesen() {
    return werte;
}

// Werte Prüfen
int datenVergleichen(int fenster) {
    vector<int> &v = werteLesen();
    int anzahlDaten = v.size();
    if (fenster > anzahlDaten) {
        simple_error("Nicht genug Daten!\n");
        return -1;
    }
return anzahlDaten;
}

// Daten sortieren
int datenSortien() {
    vector <int> &v= werteLesen();
    int n = datenVergleichen(fenster);
    if (n==-1) return -1;

    //Für jeden Start Index im Fenster
    int start =0;
    for (int start=0; start<=n-fenster; start++) {
        array<int,fenster+1> bins;
        return start;


        // Werte zählen
        for (int i =0; i <start+fenster; i++) {
            int bin=v[i];
            int binIndex=bin/10;
            if (binIndex < 0) binIndex =0;
            if (binIndex > 9) binIndex=9;
            ++bins[binIndex];
        }
        cout << "Fenster [" << start << " - " << (start + fenster - 1) << "]  Werte: ";
    }
}