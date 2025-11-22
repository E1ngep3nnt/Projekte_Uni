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
void druckeSpielfeld(Spielzustand aktuell) {
    int breite=aktuell.spielbreite;
    int hoehe=aktuell.spielhoehe;
    for (int reihe = 0; reihe < hoehe+2; ++reihe) {
        if (reihe == 0 || reihe == hoehe+1) {
            // erste oder letzte Zeile: "|" gefolgt von Strichen im Abstand Spielbreite
            cout << "|" <<string(breite, '-') << "|"<< '\n';
        } else {
            // mittlere Zeilen: nur "|"
            cout << "|" <<string(breite, ' ') << "|\n";
        }
    }
}

int main() {
    try {
        werte = eingabewerteEinlesen();
        if (werte.size() < 2) throw fehlendeZahlen{};
        Spielzustand initial;
        initial.spielbreite = werte.at(0);
        initial.spielhoehe = werte.at(1);
        initial.punktzahl = 0;
        initial.gameOver = false;
        initial.gegessen = false;
        druckeSpielfeld(initial);
    } catch (const ungueltiger_Bereich&) {
        cout << "Eingabe ausserhalb des zulaessigen Bereiches.\n";
        return 1;
    } catch (const fehlendeZahlen&) {
        cout << "Programm wegen fehlender Spielfeldeingabe beendet.\n";
        return 1;
    } catch (const unzulaessig&) {
        cout << "Unzulaessige Eingabe! Nutze w, a, s, d zum Bewegen oder q zum Beenden.\n";
        return 1;
    } catch (...) {
        cout << "Unbekannter Fehler\n";
        return 1;
    }
}