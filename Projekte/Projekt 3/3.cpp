//
// Created by Sebastian on 22.11.2025.
//

#include "std_lib_inc.h"

constexpr char kZahl = 'z';
constexpr char kAusgabe = ';';
constexpr char kEnde = 'q';
constexpr string kPrompt = "> ";
constexpr string kRueckgabe = "= ";

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
char bewegung;
cin >> bewegung;
    switch (bewegung) {
        case kAusgabe:
        case kEnde:
        case 'w':
        case 'a':
        case 's':
        case 'd':
            return Token{bewegung};
    }
}



// Fehlerklassen
class BereichsFehler{};
class EingabeFehler{};
class UnzulaessigeEingabe{};

// Schlangenklassen
class Schlangenglied{
public:
    int posX{};
    int posY{};
};

class Position {
public:
    int posX{};
    int posY{};
};

//Spielzustandsklassen
class Spielzustand{
public:
    int spielbreite{};
    int spielhoehe{};
    vector<Schlangenglied> schlange;
    Position futterPositi{};
    int punktzahl{};
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
void leseSpielfeldGroesse(Spielzustand &aktuellerSpielzustand) {
    aktuellerSpielzustand.spielbreite = pruefeEingabewert();
    aktuellerSpielzustand.spielhoehe = pruefeEingabewert();
}

// Ruft Positionsfunktion für de nachfolgende funktionen auf obwohl sie erst später deklariert wird
Position berechneFutterposition(const Spielzustand & aktuellerSpielzustand, const Position & kopfPosition);

// Spielfeld initialisieren
void initialisiereSpiel(Spielzustand & aktuellerSpielzustand) {
    aktuellerSpielzustand.punktzahl = 0;
    aktuellerSpielzustand.gameOver = false;
    aktuellerSpielzustand.hatGeradeGefressen = false;
    aktuellerSpielzustand.schlange.clear();
    int startKopfX=(aktuellerSpielzustand.spielbreite/2)+1;
    int startKopfY=(aktuellerSpielzustand.spielbreite/2)+1;
    Schlangenglied startKopf;
    startKopfX=startKopfX;
    startKopfY=startKopfY;
    aktuellerSpielzustand.schlange.push_back(startKopf);
    Position startkopfPosition{startKopfX, startKopfY};
    aktuellerSpielzustand.futterPosition = berechneFutterposition(aktuellerSpielzustand, startkopfPosition);
}

// Berechnet Futterposition basierend auf dem aktuellen Spielstand.
Position berechneFutterposition(const Spielzustand &aktuellerSpielzustand, const Position &kopfPosition) {
    Position futterPosition {
        ((17*kopfPosition.posX/aktuellerSpielzustand.spielbreite)+1)
        ((13*kopfPosition.posY/aktuellerSpielzustand.spielhoehe)+1)
        };
    int istPositionBelegt=(const Position& pruefePosition){
        for (const Schlangenglied &segment : aktuellerSpielzustand.schlange) {
            if (segment.posX == pruefePosition.posX && segment.posY == pruefePosition.posY)
                return true;
        }
        return false;
    };
    int schritt=1;
    while (istPositionBelegt (futterPosition)) {
     futterPosition.posX=((futterPosition.posX-schritt)%aktuellerSpielzustand.spielbreite)+1;
     futterPosition.posY=((futterPosition.posY-schritt)%aktuellerSpielzustand.spielhoehe)+1;
        ++schritt;
        if (schritt>aktuellerSpielzustand.spielbreite*aktuellerSpielzustand.spielhoehe)
            break;
    }return futterPosition;
}

// Druckt den aktuellen Spielzustand (liest nur Werte ein)
void druckeSpielfeld(const Spielzustand &aktuellerSpielzustand) {
    int feldBreite=aktuellerSpielzustand.spielbreite;
    int feldHoehe=aktuellerSpielzustand.spielhoehe;
    for (int reiheIndex=0,){}
}


int main() {
    cout <<'>'<< "";
    try {
        Spielzustand aktuellerSpielzustand = erstelleNeuenSpielstand();
        druckeSpielfeld(aktuellerSpielzustand);
        while (!aktuellerSpielzustand.gameOver) {
            try {
                cout <<'>'<< "";
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