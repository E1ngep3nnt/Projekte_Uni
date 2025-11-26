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

Token TokenStream::get() {
    if (voll) {
        voll = false;
        return puffer;
    }

    char eingabe;
    cin >> eingabe;

    // überspringe '>'-Zeichen falls es gelesen werden sollte
    while (eingabe == '>') {
        if (!(cin >> eingabe))
            throw EingabeFehler{};
    }

    if (static_cast<unsigned char>(eingabe)) {
        cin.putback(eingabe);
        int wert;
        if (!(cin >> wert)) // Lesefehler abfangen
            throw EingabeFehler{};
        return Token{kZahl, wert};
    }

    // Danach die Steuerzeichen behandeln
    switch (eingabe) {
        case kEnde:
        case 'w':
        case 'a':
        case 's':
        case 'd':
            return Token{eingabe};
        default:
            throw EingabeFehler{};
    }
}

// TokenStream-Objekt, mit dem wir arbeiten werden. Das ist eine globale Variable und daher sehr ungünstig.
// Mit den zu diesem Zeitpunkt zur Verfügung stehenden Mitteln können wir es nicht besser designen.
TokenStream token_stream;

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

// Prüft die Eingabe und gibt die Werte fürs Spielfeld zurück
int pruefeEingabeWert() {
    Token eingabeWert = token_stream.get();

    if (eingabeWert.art == kZahl) {
        if (eingabeWert.wert < 3 || eingabeWert.wert > 25) {
            throw BereichsFehler{};
        }
        return eingabeWert.wert; // gültiger Wert
    }
    if (eingabeWert.art == kEnde) {
        // optional: besondere Behandlung für 'q'
        throw UnzulaessigeEingabe{};
    }
    else {
        // andere Steuerzeichen (w,a,s,d) sind hier nicht erlaubt
        throw UnzulaessigeEingabe{};
    }
}



// Liest die Spielfeldgröße ein
void leseSpielfeldGroesse(){
}

// Ruft Positionsfunktion für de nachfolgende funktionen auf obwohl sie erst später deklariert wird
Position berechneFutterposition();

// Spielfeld initialisieren
void initialisiereSpiel(){
}

// Berechnet Futterposition basierend auf dem aktuellen Spielstand.
Position berechneFutterposition() {
}

// Druckt den aktuellen Spielzustand (liest nur Werte ein)
void druckeSpielfeld(){
}

int main() {
    cout <<'>'<< "";
    try {
        pruefeEingabeWert();
        return 0;
    }
    catch (const BereichsFehler&) {
        cout << "Eingabe ausserhalb des zulaessigen Bereiches.\n";
        return 1;
    } catch (const EingabeFehler&) {
        cout << "Programm wegen fehlender Spielfeldeingabe beendet.\n";
        return 1;
    }
}
