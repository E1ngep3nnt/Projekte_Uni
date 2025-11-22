#include "std_lib_inc.h"

class Schlangenglied
{
public:
    int x, y;
};

class Point2d
{
public:
    int px, py;
};


// Stellt den aktuellen Spielzustand dar
class Spielzustand
{
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
char steuerung() {
  char w;
  char a;
  char s;
  char d;
  char q;
}

// Eingabe Funktion
void pruefeEingabeWert (int eingabe) {
    if (eingabe<3 || eingabe>25) {
        throw ungueltiger_Bereich{};
    }
    if (!(cin >> eingabe)) {
    throw fehlendeZahlen{};
    }
}

// Bewegungseingabe Validieren
void eingabeValidierung(char steuerung) {
  if (!(cin >> steuerung)) {
      throw unzulaessig{};
  }
}

// Spielfeld genereieren
void druckeSpielfeld(int eingabe) {

}

int main() {

    return 0;
}