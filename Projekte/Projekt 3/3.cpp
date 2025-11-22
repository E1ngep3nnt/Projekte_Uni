#include "std_lib_inc.h"

class Schlangenglied{
public:
    int x, y;
};

class Point2d{
public:
    int px, py;
};


// Stellt den aktuellen Spielzustand dar
class Spielzustand{
public:
    int spielbreite;
    int spielhoehe;
    vector<Schlangenglied> python;
    int punktzahl;
    bool gameOver;
    bool gegessen;
    Point2d futter;
    // ...
};

// Fehlerklassen
class ungueltiger_Bereich{};
class fehlendeZahlen{};
class unzulaessig{};

//Globale Variablen
vector<int> werte;
char steuerung() {
  char w;
  char a;
  char s;
  char d;
  char q;
}

// Einzelwert prüfen
void pruefeEingabewert(int eingabe) {
    if (eingabe < 3 || eingabe > 25) {
        throw ungueltiger_Bereich{};
    }
}

// Werte einlesen und zurückgeben
vector<int> eingabewerteEinlesen() {
    int eingabe;
    // erste Zahl
    if (!(cin >> eingabe)) {
        throw fehlendeZahlen{};
    }
    pruefeEingabewert(eingabe);
    werte.push_back(eingabe);
    Spielzustand breite;
    breite.spielbreite=werte.at(0);

    // zweite Zahl
    if (!(cin >> eingabe)) {
        throw fehlendeZahlen{};
    }
    pruefeEingabewert(eingabe);
    werte.push_back(eingabe);
    Spielzustand hoehe;
    hoehe.spielhoehe=werte.at(0);
    return werte;
}


// Spielfeld genereieren
void druckeSpielfeld(Spielzustand) {
    for (int reihe = 0; reihe < spielbreite+2; ++reihe) {
        if (reihe == 0 || reihe == spielbreite+1) {
            // erste oder letzte Zeile: "|" gefolgt von eingabewertx Strichen
            cout << "|" <<string(spielhoehe, '-') << "|"<< '\n';
        } else {
            // mittlere Zeilen: nur "|"
            cout << "|" <<string(spielhoehe, ' ') << "|\n";
        }
    }
}

int main() {
    werte = eingabewerteEinlesen();
    druckeSpielfeld(Spielzustand);
}