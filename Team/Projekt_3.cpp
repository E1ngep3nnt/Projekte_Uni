#include "std_lib_inc.h"

// Fehlerklassen: werden als Exception-Typen verwendet
class BereichsFehler { };        // für Werte außerhalb des erlaubten Bereichs
class EingabeFehler { };        // für nicht-numerische bzw. fehlende Eingabe
class UnzulaessigeEingabe { };  // für ungültige Steuerungszeichen

// Einzelnes Schlangenglied (Segment)
class Schlangenglied {
public:
    int posX; // x-Koordinate im Spielfeld (1..breite)
    int posY; // y-Koordinate im Spielfeld (1..hoehe)
};

// Hilfsklasse für Koordinaten/Positionen
class Position {
public:
    int posX;
    int posY;
};

// Spielzustand: zentrale Datenstruktur, hält alles Relevante
class Spielzustand {
public:
    int spielbreite;                 // Spielfeldbreite
    int spielhoehe;                  // Spielfeldhöhe
    vector<Schlangenglied> schlange; // Liste der Segmente (kopf = index 0)
    Position futterPosition;         // aktuelle Futterposition
    int punktzahl;                   // aktuelle Punktzahl
    bool gameOver;                   // Spiel beendet?
    bool hatGeradeGefressen;         // Flag: Wachstums-Trigger nach Fressen
};

int main() {

}