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

// Prüft die Eingabe und gibt die Werte fürs Spielfeld zurück
int pruefeEingabewert() {
    int eingabewert;
    if (!(cin >> eingabewert)) throw EingabeFehler{};
    if (eingabewert < 3 || eingabewert > 25) throw BereichsFehler{};
    return eingabewert;
}

// Liest die Spielfeldgröße ein
void leseSpielfeldGroesse(Spielzustand &aktuellerSpielzustand) {
    aktuellerSpielzustand.spielbreite = pruefeEingabewert();
    aktuellerSpielzustand.spielhoehe = pruefeEingabewert();
}

Position berechneFutterposition(const Spielzustand &aktuellerSpielzustand, const Position &kopfPosition);

void initialisiereSpiel(Spielzustand& aktuellerSpielzustand) {
    aktuellerSpielzustand.punktzahl = 0;
    aktuellerSpielzustand.gameOver = false;
    aktuellerSpielzustand.hatGeradeGefressen = false;
    aktuellerSpielzustand.schlange.clear();
    int startKopfX = (aktuellerSpielzustand.spielbreite / 2) + 1;
    int startKopfY = (aktuellerSpielzustand.spielhoehe / 2) + 1;
    Schlangenglied startKopf;
    startKopf.posX = startKopfX;
    startKopf.posY = startKopfY;
    aktuellerSpielzustand.schlange.push_back(startKopf);
    Position startKopfPosition{startKopfX, startKopfY};
    aktuellerSpielzustand.futterPosition = berechneFutterposition(aktuellerSpielzustand, startKopfPosition);
}

Spielzustand erstelleNeuenSpielstand() {
    Spielzustand neuerSpielzustand;
    leseSpielfeldGroesse(neuerSpielzustand);
    initialisiereSpiel(neuerSpielzustand);
    return neuerSpielzustand;
}

// Berechnet Futterposition basierend auf dem aktuellen Spielstand.
Position berechneFutterposition(const Spielzustand &aktuellerSpielzustand, const Position &kopfPosition) {
    Position futterPosition{
        ((17 * kopfPosition.posX) % aktuellerSpielzustand.spielbreite) + 1,
        ((13 * kopfPosition.posY) % aktuellerSpielzustand.spielhoehe) + 1
    };
    auto istPositionBelegt = [&](const Position& pruefPosition) {
        for (const auto &segment : aktuellerSpielzustand.schlange) {
            if (segment.posX == pruefPosition.posX && segment.posY == pruefPosition.posY) return true;
        }
        return false;
    };
    int schritt = 1;
    while (istPositionBelegt(futterPosition)) {
        futterPosition.posX = ((futterPosition.posX + schritt - 1) % aktuellerSpielzustand.spielbreite) + 1;
        futterPosition.posY = ((futterPosition.posY + schritt - 1) % aktuellerSpielzustand.spielhoehe) + 1;
        ++schritt;
        if (schritt > aktuellerSpielzustand.spielbreite * aktuellerSpielzustand.spielhoehe) break;
    }
    return futterPosition;
}

// Druckt den aktuellen Spielzustand (liest nur Werte ein)
void druckeSpielfeld(const Spielzustand &aktuellerSpielzustand) {
    int feldBreite = aktuellerSpielzustand.spielbreite;
    int feldHoehe = aktuellerSpielzustand.spielhoehe;
    for (int reiheIndex = 0; reiheIndex < feldHoehe + 2; ++reiheIndex) {
        if (reiheIndex == 0 || reiheIndex == feldHoehe + 1) {
            cout << "|" << string(feldBreite, '-') << "|\n";
        } else {
            int zeilenKoordinate = reiheIndex;
            cout << "|";
            for (int spaltenIndex = 1; spaltenIndex <= feldBreite; ++spaltenIndex) {
                bool feldGedruckt = false;
                if (!aktuellerSpielzustand.schlange.empty()
                    && aktuellerSpielzustand.schlange.front().posX == spaltenIndex
                    && aktuellerSpielzustand.schlange.front().posY == zeilenKoordinate) {
                    cout << 'O';
                    feldGedruckt = true;
                } else if (!feldGedruckt && aktuellerSpielzustand.futterPosition.posX == spaltenIndex && aktuellerSpielzustand.futterPosition.posY == zeilenKoordinate) {
                    cout << '#';
                    feldGedruckt = true;
                } else {
                    for (size_t segmentIndex = 1; segmentIndex < aktuellerSpielzustand.schlange.size(); ++segmentIndex) {
                        if (aktuellerSpielzustand.schlange[segmentIndex].posX == spaltenIndex && aktuellerSpielzustand.schlange[segmentIndex].posY == zeilenKoordinate) {
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
    cout << "Punktzahl: " << aktuellerSpielzustand.punktzahl << "\n";
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
void bewegeSchlange(Spielzustand& aktuellerSpielzustand, char steuerungsCode) {
    if (steuerungsCode == 'q') {
        aktuellerSpielzustand.gameOver = true;
        return;
    }
    Schlangenglied aktuellesKopfSegment = aktuellerSpielzustand.schlange.front();
    Position neueKopfPosition{aktuellesKopfSegment.posX, aktuellesKopfSegment.posY};
    if (steuerungsCode == 'w') neueKopfPosition.posY -= 1;
    else if (steuerungsCode == 's') neueKopfPosition.posY += 1;
    else if (steuerungsCode == 'a') neueKopfPosition.posX -= 1;
    else if (steuerungsCode == 'd') neueKopfPosition.posX += 1;
    if (neueKopfPosition.posX < 1 || neueKopfPosition.posX > aktuellerSpielzustand.spielbreite
        || neueKopfPosition.posY < 1 || neueKopfPosition.posY > aktuellerSpielzustand.spielhoehe) {
        aktuellerSpielzustand.gameOver = true;
        return;
    }
    bool tailBleibtBeiDieserBewegung = aktuellerSpielzustand.hatGeradeGefressen;
    for (size_t segmentIndex = 0; segmentIndex < aktuellerSpielzustand.schlange.size(); ++segmentIndex) {
        bool istSchwanzSegment = (segmentIndex == aktuellerSpielzustand.schlange.size() - 1);
        if (!tailBleibtBeiDieserBewegung && istSchwanzSegment) continue;
        const auto& segment = aktuellerSpielzustand.schlange[segmentIndex];
        if (neueKopfPosition.posX == segment.posX && neueKopfPosition.posY == segment.posY) {
            aktuellerSpielzustand.gameOver = true;
            return;
        }
    }
    Schlangenglied neuesKopfSegment;
    neuesKopfSegment.posX = neueKopfPosition.posX;
    neuesKopfSegment.posY = neueKopfPosition.posY;
    aktuellerSpielzustand.schlange.insert(aktuellerSpielzustand.schlange.begin(), neuesKopfSegment);
    bool hatGefressen = (neueKopfPosition.posX == aktuellerSpielzustand.futterPosition.posX && neueKopfPosition.posY == aktuellerSpielzustand.futterPosition.posY);
    if (hatGefressen) {
        aktuellerSpielzustand.punktzahl += 10;
        aktuellerSpielzustand.futterPosition = berechneFutterposition(aktuellerSpielzustand, neueKopfPosition);
        aktuellerSpielzustand.hatGeradeGefressen = true;
    } else {
        aktuellerSpielzustand.hatGeradeGefressen = false;
    }
    if (!tailBleibtBeiDieserBewegung) {
        if (!aktuellerSpielzustand.schlange.empty()) aktuellerSpielzustand.schlange.pop_back();
    }
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