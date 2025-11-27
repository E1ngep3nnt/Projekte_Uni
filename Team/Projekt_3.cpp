#include "std_lib_inc.h"

// Fehlerklassen: werden als Exception-Typen verwendet
class BereichsFehler {};       // für Werte außerhalb des erlaubten Bereichs
class EingabeFehler {};        // für nicht-numerische bzw. fehlende Eingabe
class UnzulaessigeEingabe {};  // für ungültige Steuerungszeichen

// Einzelnes Schlangenglied
class Schlangenglied {
public:
    int posX; // x-Koordinate im Spielfeld
    int posY; // y-Koordinate im Spielfeld
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
    Spielzustand();
    int spielbreite;                 // Spielfeldbreite
    int spielhoehe;                  // Spielfeldhöhe
    vector<Schlangenglied> schlange; // Liste der Segmente
    Position futterPosition;         // aktuelle Futterposition
    int punktzahl;                   // aktuelle Punktzahl
    bool gameOver;                   // Spiel beendet?
    bool hatGeradeGefressen;         // Wachstum nach Fressen
};

Spielzustand::Spielzustand() {
    spielbreite=0;
    spielhoehe=0;
    punktzahl=0;
    gameOver=false;
    hatGeradeGefressen=false;
    futterPosition=Position{1,1};
}

// Prüft die Eingabe und gibt die Werte fürs Spielfeld zurück
int pruefeEingabewert() {
}

// Liest die Spielfeldgröße ein
void leseSpielfeldGroesse(Spielzustand &initialSpielstand) {
}

// Vorwärtsdeklaration
Position berechneFutterposition(const Spielzustand &initialSpielstand, const Position &kopfPosition);

// Spielfeld initialisieren
void initialisiereSpiel(Spielzustand& initialSpielstand) {
}

// Erstellt einen neuen Spielstand
Spielzustand erstelleNeuenSpielstand() {
}

//Überprüfungsfunktion für die generierung des neuen Futters
bool pruefePosition(const Spielzustand & initialSpielstand, const Position& punkt) {
    for (const Schlangenglied& Teile: initialSpielstand.schlange) {
        if (Teile.posX==punkt.posX && Teile.posY==punkt.posY)
            return true;
    }
    return false;
}

// Berechnet Futterposition basierend auf dem aktuellen Spielstand.
Position berechneFutterposition(const Spielzustand &initialSpielstand, const Position &kopfPosition) {
    Position futterPosition{
        ((17 * kopfPosition.posX) % initialSpielstand.spielbreite) + 1,
        ((13 * kopfPosition.posY) % initialSpielstand.spielhoehe) + 1
    };
    // Sorgt dafür das nur innerhalb des Spielfeldes generiert wird
    if (futterPosition.posX < 1) futterPosition.posX = 1;
    if (futterPosition.posX > initialSpielstand.spielbreite) futterPosition.posX = initialSpielstand.spielbreite;
    if (futterPosition.posY < 1) futterPosition.posY = 1;
    if (futterPosition.posY > initialSpielstand.spielhoehe) futterPosition.posY = initialSpielstand.spielhoehe;

    // Falls die Position von der Schlange belegt ist, suche die nächste freie Zelle
    for (int schritthoehe = 0; schritthoehe < initialSpielstand.spielhoehe; ++schritthoehe) {
        for (int schrittbreite= 0; schrittbreite < initialSpielstand.spielbreite; ++schrittbreite) {
            int x = (futterPosition.posX - 1 + schrittbreite) % initialSpielstand.spielbreite + 1;
            int y = (futterPosition.posY - 1 + schritthoehe) % initialSpielstand.spielhoehe + 1;
            Position freierPunkt{ x, y };
            if (!pruefePosition(initialSpielstand, freierPunkt)) {
                return freierPunkt;
            }
        }
    }
    // Falls gesamtes Feld belegt gib die Startposition zurück
    return futterPosition;
}

// Druckt den aktuellen Spielzustand (liest nur Werte ein)
void druckeSpielfeld(const Spielzustand &initialSpielstand) {
    int feldBreite = initialSpielstand.spielbreite;
    int feldHoehe = initialSpielstand.spielhoehe;
    for (int reiheIndex = 0; reiheIndex < feldHoehe + 2; ++reiheIndex) {
        if (reiheIndex == 0 || reiheIndex == feldHoehe + 1) {
            cout << "|" << string(feldBreite, '-') << "|\n";
        } else {
            int zeilenKoordinate = reiheIndex;
            cout << "|";
            for (int spaltenIndex = 1; spaltenIndex <= feldBreite; ++spaltenIndex) {
                bool feldGedruckt = false;
                if (!initialSpielstand.schlange.empty()
                    && initialSpielstand.schlange.front().posX == spaltenIndex
                    && initialSpielstand.schlange.front().posY == zeilenKoordinate) {
                    cout << 'O';
                    feldGedruckt = true;
                } else if (!feldGedruckt && initialSpielstand.futterPosition.posX == spaltenIndex && initialSpielstand.futterPosition.posY == zeilenKoordinate) {
                    cout << '#';
                    feldGedruckt = true;
                } else {
                    for (size_t segmentIndex = 1; segmentIndex < initialSpielstand.schlange.size(); ++segmentIndex) {
                        if (initialSpielstand.schlange[segmentIndex].posX == spaltenIndex && initialSpielstand.schlange[segmentIndex].posY == zeilenKoordinate) {
                            cout << 'o';
                            feldGedruckt = true;
                            break;
                        }
                    }
                }
                if (!feldGedruckt) cout << ' ';
            }
            cout << "|\n";
        }
    }
    cout << "Punktzahl: " << initialSpielstand.punktzahl << "\n";
}

// Liest die Steuerung ein und validiert sie
char leseSteuerung() {
    char steuerungsEingabe;
    if (!(cin >> steuerungsEingabe)) return 'q';
    if (steuerungsEingabe == 'w' || steuerungsEingabe == 'a' || steuerungsEingabe == 's' || steuerungsEingabe == 'd' || steuerungsEingabe == 'q') {
        return steuerungsEingabe;
    }
    throw UnzulaessigeEingabe{};
}

// Bewegt die Schlange im aktuellen Zustand
void bewegeSchlange(Spielzustand& initialSpielstand, char steuerungsCode) {
    if (steuerungsCode == 'q') {
        initialSpielstand.gameOver = true;
        return;
    }
    Schlangenglied aktuellesKopfSegment = initialSpielstand.schlange.front();
    Position neueKopfPosition{aktuellesKopfSegment.posX, aktuellesKopfSegment.posY};
    if (steuerungsCode == 'w') neueKopfPosition.posY -= 1;
    else if (steuerungsCode == 's') neueKopfPosition.posY += 1;
    else if (steuerungsCode == 'a') neueKopfPosition.posX -= 1;
    else if (steuerungsCode == 'd') neueKopfPosition.posX += 1;
    if (neueKopfPosition.posX < 1 || neueKopfPosition.posX > initialSpielstand.spielbreite
        || neueKopfPosition.posY < 1 || neueKopfPosition.posY > initialSpielstand.spielhoehe) {
        initialSpielstand.gameOver = true;
        return;
    }
    bool schwanzBleibtBeiDieserBewegung = initialSpielstand.hatGeradeGefressen;
    for (int SchlangenTeilIndex = 0; SchlangenTeilIndex< initialSpielstand.schlange.size(); ++SchlangenTeilIndex) {
        bool istSchwanzTeil = (SchlangenTeilIndex == initialSpielstand.schlange.size() - 1);
        if (!schwanzBleibtBeiDieserBewegung && istSchwanzTeil) continue;
        const auto& segment = initialSpielstand.schlange[SchlangenTeilIndex];
        if (neueKopfPosition.posX == segment.posX && neueKopfPosition.posY == segment.posY) {
            initialSpielstand.gameOver = true;
            return;
        }
    }
    Schlangenglied neuesKopfSegment;
    neuesKopfSegment.posX = neueKopfPosition.posX;
    neuesKopfSegment.posY = neueKopfPosition.posY;
    initialSpielstand.schlange.insert(initialSpielstand.schlange.begin(), neuesKopfSegment);
    bool hatGefressen = (neueKopfPosition.posX == initialSpielstand.futterPosition.posX && neueKopfPosition.posY == initialSpielstand.futterPosition.posY);
    if (hatGefressen) {
        initialSpielstand.punktzahl += 10;
        initialSpielstand.futterPosition = berechneFutterposition(initialSpielstand, neueKopfPosition);
        initialSpielstand.hatGeradeGefressen = true;
    } else {
        initialSpielstand.hatGeradeGefressen = false;
    }
    if (!schwanzBleibtBeiDieserBewegung) {
        if (!initialSpielstand.schlange.empty()) initialSpielstand.schlange.pop_back();
    }
}

int main() {
    cout << ">";
    try {
        Spielzustand initialSpielzustand = erstelleNeuenSpielstand();
        druckeSpielfeld(initialSpielzustand);
        while (!initialSpielzustand.gameOver) {
            try {
                cout << ">";
                char steuerungsCode = leseSteuerung();
                bewegeSchlange(initialSpielzustand, steuerungsCode);
                if (initialSpielzustand.gameOver) {
                    break;
                }
                druckeSpielfeld(initialSpielzustand);
            }
            catch (const UnzulaessigeEingabe&) {
                cout << "Unzulaessige Eingabe! Nutze w, a, s, d zum Bewegen oder q zum Beenden.\n";
            }
        } // Ende while
        cout << "Game Over! Gesamtpunktzahl: " << initialSpielzustand.punktzahl << ".\n";
        return 0;
    }
    catch (const BereichsFehler&) {
        cout << "Eingabe ausserhalb des zulaessigen Bereiches.\n";
        return 1;
    }
    catch (const EingabeFehler&) {
        cout << "Programm wegen fehlender Spielfeldeingabe beendet.\n";
        return 1;
    }catch (...) {
        // optionaler fallback
        cout << "Unerwarteter Fehler.\n";
        return 1;
    }
}