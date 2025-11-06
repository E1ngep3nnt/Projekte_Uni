//
// Created by Sebastian on 06.11.2025.
//
#include "std_lib_inc.h"

int main() {
    vector<double> daten;
    double werte = 0.0;
    double summe = 0.0;
    int fenster = 0;

    if (!(cin >> fenster)) {
        simple_error("Programm wegen nicht-numerischen Werts beendet.\n");
    }
    if (fenster < 1 || fenster > 10) {
        simple_error("Eingabe ausserhalb des zulaessigen Bereiches.\n");
    }

    while (cin >> werte) {
        if (werte < 0.0 || werte > 599.0) {
            simple_error("Eingabe ausserhalb des zulaessigen Bereiches.\n");
        }
        daten.push_back(werte);
    }
    int anzahl_daten = int (daten.size());
    if (anzahl_daten < 0 || fenster > anzahl_daten ) {
        simple_error("Ein Fehler ist passiert!\n");
    }

    for (int i = 0; i < fenster; ++i) {
        summe += daten[i];
    }
    cout << (summe / fenster) << "\n";

    for (int start = 1; start <= anzahl_daten - fenster; ++start) {
        summe -= daten[start - 1];
        summe += daten[start + fenster - 1];
        cout << (summe / fenster) << "\n";
    }
    cout << "Programm erfolgreich ausgefuehrt.\n";
}