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
int datenVergleichen() {
    int anzahlDaten = werte.size();
    if (fenster >= anzahlDaten) {
        simple_error("Programm wegen fehlender Zahlenfolge beendet.\n");
        return -1;
    }
    return anzahlDaten;
}

// Daten sortieren
int datenSortiren() {
    vector <int> daten = werteLesen();
    int n = datenVergleichen ();
    if (n==-1) return -1;

    for (int start = 0; start <= n - fenster; ++start) {
        vector<int> bins(10, 0);

        for (int i = start; i < start + fenster; ++i) {
            int binIndex = daten[i] / 10;
            ++bins[binIndex];
        }

        cout << "Fenster " << start << ": ";
        for (int b : bins) cout << b << " ";
        cout << "\n";
    }
}
    int main() {
    int werte1=0;
    while (cin>>werte1) {
        werte.push_back(werte1);
    }
    cout << datenSortiren() << endl;
}