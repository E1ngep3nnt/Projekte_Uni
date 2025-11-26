#include "std_lib_inc.h"

constexpr char kZahl = 'z';
constexpr char kEnde = 'q';

// Fehlerklassen: werden als Exception-Typen verwendet
class BereichsFehler {};       // für Werte außerhalb des erlaubten Bereichs
class EingabeFehler {};        // für nicht-numerische bzw. fehlende Eingabe
class UnzulaessigeEingabe {};  // für ungültige Steuerungszeichen

// Token Klassen
class Token {
public:
    char art{};
    int wert{};
};

// Tokenstream
class TokenStream {
public:
    TokenStream();
    Token get();
    void putback(Token token);
    void ignore_until(char input_character);

private:
    Token puffer;
    bool voll;
};

TokenStream::TokenStream() {
    voll=false;
}

void TokenStream::putback(Token token) {
    assert(!voll, "putback() in einen vollen Puffer");
    puffer = token;
    voll=true;
}

Token TokenStream::get() {
    if (voll){
        voll=false;
        return puffer;
    }
    char eingabe;
    cin >>eingabe;

    switch (eingabe) {
        case kEnde:
        case 'w':
        case 'a':
        case 's':
        case 'd':
            return Token{eingabe};
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            cin.putback (eingabe);
            int wert;
            cin >> wert;
            return Token{kZahl, wert};
        default:
            throw EingabeFehler{};
    }
}

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

// Eingabe Funktion
void pruefeEingabeWert (int eingabe) {
}

// Prüft die Eingabe und gibt die Werte fürs Spielfeld zurück
int pruefeEingabewert() {
}


// Liest die Spielfeldgröße ein
void leseSpielfeldGroesse(Spielzustand &) {
}

// Ruft Positionsfunktion für de nachfolgende funktionen auf obwohl sie erst später deklariert wird
Position berechneFutterposition(const Spielzustand & aktuellerSpielzustand, const Position & kopfPosition);

// Spielfeld initialisieren
void initialisiereSpiel(Spielzustand &) {
}

// Berechnet Futterposition basierend auf dem aktuellen Spielstand.
Position berechneFutterposition(const Spielzustand &, const Position &) {
}

// Druckt den aktuellen Spielzustand (liest nur Werte ein)
void druckeSpielfeld(const Spielzustand &) {
}

int main() {
    cout <<'>'<< "";
    try {
        Spielzustand aktuellerSpielzustand;
        druckeSpielfeld(aktuellerSpielzustand);
        while (!aktuellerSpielzustand.gameOver) {
            try {
                cout <<'>'<< "";
                char steuerungsCode;
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