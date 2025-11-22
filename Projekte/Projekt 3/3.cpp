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
    int spielbreite{};
    int spielhoehe{};
    vector<Schlangenglied> python;
    int punktzahl{};
    bool gameOver{};
    bool gegessen{};
    Point2d futter{};
    // ...
};

// Fehlerklassen
class BereichsFehler{};
class EingabeFehler{};
class UnzulaessigeEingabe{};

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
        int breite = eingabe;
        int hoehe = breite;
        if (!(cin >> breite)) throw EingabeFehler{};
        if (!(cin >> hoehe)) throw EingabeFehler{};
        if (breite < 3 || breite > 25 || hoehe < 3 || hoehe > 25) throw BereichsFehler{};
    }
}

// Werte einlesen und zurückgeben
vector<int> eingabewerteEinlesen() {
    int eingabe;
    // erste Zahl
    if (!(cin >> eingabe)) {
        throw EingabeFehler{};
    }
    pruefeEingabewert(eingabe);
    werte.push_back(eingabe);
    Spielzustand breite;
    breite.spielbreite=werte.at(0);

    // zweite Zahl
    if (!(cin >> eingabe)) {
        throw EingabeFehler{};
    }
    pruefeEingabewert(eingabe);
    werte.push_back(eingabe);
    Spielzustand hoehe;
    hoehe.spielhoehe=werte.at(0);
    return werte;
}

// Spielfeld genereieren
void druckeSpielfeld(const Spielzustand & aktuell) {
    int breite=aktuell.spielbreite;
    int hoehe=aktuell.spielhoehe;
    for (int reihe = 0; reihe < hoehe+2; ++reihe) {
        if (reihe == 0 || reihe == hoehe+1) {
            // erste oder letzte Zeile: "|" gefolgt von Strichen im Abstand Spielbreite
            cout << "|" <<string(breite, '-') << "|"<< '\n';
        }
        else {
            int Zeilenkoordinate=reihe;
            cout << "|";
            for (int x=1; x<=breite; ++x) {
                bool gedruckt=false;
                if (!aktuell.python.empty()&&aktuell.python.front().x==x && aktuell.python.front().y==Zeilenkoordinate) {
                    cout << 'o';
                    gedruckt=true;
                }
                else if (!gedruckt && aktuell.futter.px==x &&aktuell.futter.py==Zeilenkoordinate) {
                    cout << '#';
                    gedruckt=true;
                }
                else {
                    for (size_t i=1; i<aktuell.python.size(); ++i) {
                        cout << 'o';
                        gedruckt = true;
                        break;
                    }
                }
                if (!gedruckt) cout << ' ';
            }
            cout << "|\n";
        }
    }
    cout << "Punktzahl: " << aktuell.punktzahl << "\n";
}

//Futter erzeugung
Point2d berechneFutter(int kopfX, int kopfY, int breite, int hoehe) {
    Point2d futter;
    futter.px = ((17*kopfX)%breite)+1;
    futter.py = ((17*kopfY)%hoehe)+1;
    return futter;
}

// Initialisiert Spielzustand: Kopfposition, Punktzahl, Futter, etc.
void Spielfeldinitialisierung(Spielzustand &initial) {
    initial.punktzahl=0;
    initial.gameOver=false;
    initial.gegessen=false;
    int kopfX=(initial.spielbreite/2)+1;
    int kopfY=(initial.spielhoehe/2)+1;
    initial.python.clear();
    Schlangenglied kopf{kopfX,kopfY};
    initial.python.push_back(kopf);
    initial.futter=berechneFutter(kopfX,kopfY,initial.spielbreite,initial.spielhoehe);
}

int main() {
    try {
        werte = eingabewerteEinlesen();
        if (werte.size() < 2) throw EingabeFehler{};
        Spielzustand initial;
        initial.spielbreite = werte.at(0);
        initial.spielhoehe  = werte.at(1);
        Spielfeldinitialisierung(initial);
        druckeSpielfeld(initial);

    } catch (const BereichsFehler&) {
        cout << "Eingabe ausserhalb des zulaessigen Bereiches.\n";
        return 1;
    } catch (const EingabeFehler&) {
        cout << "Programm wegen fehlender Spielfeldeingabe beendet.\n";
        return 1;
    } catch (const UnzulaessigeEingabe&) {
        cout << "Unzulaessige Eingabe! Nutze w, a, s, d zum Bewegen oder q zum Beenden.\n";
        return 1;
    } catch (...) {
        cout << "Unbekannter Fehler\n";
        return 1;
    }
}