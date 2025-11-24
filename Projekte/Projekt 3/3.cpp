//
// Created by Sebastian on 22.11.2025.
//
#include "std_lib_inc.h"

// Fehlerklassen
class BereichsFehler{};
class EingabeFehler{};
class UnzulaessigeEingabe{};

// Schlangenklassen
class Schlangenglied{
public:
    int posX{0};
    int posY{0};
};

class Position {
public:
    int posX{0};
    int posY{0};
};

//Spielzustandsklassen
class Spielzustand{
public:
    int spielbreite{0};
    int spielhoehe{0};
    vector<Schlangenglied> schlange;
    Position futterPosition{0,0};
    int punktzahl{0};
    bool gameOver{false};
    bool hatGeradeGefressen{false};
};



// Eingabe Funktion
void pruefeEingabeWert (int eingabe) {
    if (eingabe<3 || eingabe>25) {
        throw UnzulaessigeEingabe{};
    }
    if (!(cin >> eingabe)) {
        throw BereichsFehler{};
    }
}

// Prüft die Eingabe und gibt die Werte fürs Spielfeld zurück
int pruefeEingabewert() {
    int eingabewert=0;
    if (!(cin >> eingabewert)) throw EingabeFehler{};
    return eingabewert;
}

// Liest die Spielfeldgröße ein
void leseSPielfeldGroesse (Spielzustand& aktuellerSpielzustand) {
    aktuellerSpielzustand.spielbreite = pruefeEingabeWert();
    aktuellerSpielzustand.spielhoehe = pruefeEingabeWert();
}


// Spielfeld genereieren
void druckeSpielfeld(int eingabe) {

}

int main() {
    cout <<'>'<< " ";
    try {
        Spielzustand aktuellerSpielzustand = erstelleNeuenSpielstand();
        druckeSpielfeld(aktuellerSpielzustand);
        while (!aktuellerSpielzustand.gameOver) {
            try {
                cout <<'>'<< " ";
                char steuerungsCode = leseSteuerung();
                bewegeSchlange(aktuellerSpielzustand, steuerungsCode);
                if (aktuellerSpielzustand.gameOver) break;
                druckeSpielfeld(aktuellerSpielzustand);
            } catch (const UnzulaessigeEingabe&) {
                cout << "Unzulaessige Eingabe! Nutze w, a, s, d zum Bewegen oder q zum Beenden.\n";
            }
        }
        cout << "Game Over! Gesamtpunktzahl: " << aktuellerSpielzustand.punktzahl << ".\n";
        return 0;
    } catch (const BereichsFehler&) {
        cout << "Eingabe ausserhalb des zulaessigen Bereiches.\n";
        return 1;
    } catch (const EingabeFehler&) {
        cout << "Programm wegen fehlender Spielfeldeingabe beendet.\n";
        return 1;
    }
}
