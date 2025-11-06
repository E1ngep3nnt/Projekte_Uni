//
// Created by Sebastian on 06.11.2025.
//

#include "std_lib_inc.h"

// Berechnet die Summe der Abstände // Teil c
vector<double> abstaende = {};
double summeBerechnen(vector<double> i) {
    double summe=0.0;
    for (double abstand:abstaende) {
        summe += abstand;
    } return summe;
}

// Berechnet den Durschnitt der Abstände // Teil b
double durchschnittBerechnen(vector<double>eingabe) {
    double summe = summeBerechnen(eingabe);
    return summe / eingabe.size();
}

// Gibt den kleinsten Abstand aus // Teil d
double kleinste(vector<double> eingabe) {
    double klein = eingabe[0];
    for (double abstand : eingabe) {
        if (abstand < klein) {
            klein = abstand;
        }
    }
    return klein;
}

// Gibt den groessten Abstand aus // Teil d
double groessten( vector<double> eingabe) {
    double gross = eingabe[0];
    for (double abstand : eingabe) {
        if (abstand > gross) {
            gross = abstand;
        }
    }
    return gross;
}

int main() {
    // Teil e
    cout << "Geben Sie die Abstaende in Meter ein.(nur die Werte ohne Einheit.)\n";
    double abstand = 0.0;
    cin >> abstand;
    // Teil f
    if (!cin) {
        simple_error("Programm wegen nicht-numerischen Werts beendet.\n");
    }
    while(cin){
            abstaende.push_back(abstand);
            cin >> abstand;
        }
    cout << "Der Durchschnittabstand ist " << durchschnittBerechnen(abstaende) << " Meter, und die Summe der Abstaende ist " << summeBerechnen(abstaende) << " Meter. \n";
    cout << "Der kleinste Abstand ist " << kleinste(abstaende)<< " Meter.\n";
    cout << "Der groesste Abstand ist " << groessten(abstaende)<< " Meter.\n";
        return 0;
}
