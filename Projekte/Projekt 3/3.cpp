#include "std_lib_inc.h"

class BereichsFehler{};
class EingabeFehler{};
class UnzulaessigeEingabe{};

class Schlangenglied{
public:
    int posX{0};
    int posY{0};
};

struct Position {
    int posX{0};
    int posY{0};
};

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

int pruefeEingabewert() {
    int eingabewert;
    if (!(cin >> eingabewert)) throw EingabeFehler{};
    if (eingabewert < 3 || eingabewert > 25) throw BereichsFehler{};
    return eingabewert;
}

void leseSpielfeldGroesse(Spielzustand &spielzustand) {
    spielzustand.spielbreite = pruefeEingabewert();
    spielzustand.spielhoehe = pruefeEingabewert();
}

Position berechneFutterposition(const Spielzustand &spielzustand, const Position &kopfPosition) {
    Position futterPosition{
        ((17 * kopfPosition.posX) % spielzustand.spielbreite) + 1,
        ((13 * kopfPosition.posY) % spielzustand.spielhoehe) + 1
    };
    auto istPositionBelegt = [&](const Position& pruefPosition) {
        for (const auto &segment : spielzustand.schlange) {
            if (segment.posX == pruefPosition.posX && segment.posY == pruefPosition.posY) return true;
        }
        return false;
    };
    int schritt = 1;
    while (istPositionBelegt(futterPosition)) {
        futterPosition.posX = ((futterPosition.posX + schritt - 1) % spielzustand.spielbreite) + 1;
        futterPosition.posY = ((futterPosition.posY + schritt - 1) % spielzustand.spielhoehe) + 1;
        ++schritt;
        if (schritt > spielzustand.spielbreite * spielzustand.spielhoehe) break;
    }
    return futterPosition;
}

void druckeSpielfeld(const Spielzustand &spielzustand) {
    int feldBreite = spielzustand.spielbreite;
    int feldHoehe = spielzustand.spielhoehe;
    for (int reiheIndex = 0; reiheIndex < feldHoehe + 2; ++reiheIndex) {
        if (reiheIndex == 0 || reiheIndex == feldHoehe + 1) {
            cout << "|" << string(feldBreite, '-') << "|\n";
        } else {
            int zeilenKoordinate = reiheIndex;
            cout << "|";
            for (int spaltenIndex = 1; spaltenIndex <= feldBreite; ++spaltenIndex) {
                bool feldGedruckt = false;
                if (!spielzustand.schlange.empty()
                    && spielzustand.schlange.front().posX == spaltenIndex
                    && spielzustand.schlange.front().posY == zeilenKoordinate) {
                    cout << 'O';
                    feldGedruckt = true;
                } else if (!feldGedruckt && spielzustand.futterPosition.posX == spaltenIndex && spielzustand.futterPosition.posY == zeilenKoordinate) {
                    cout << '#';
                    feldGedruckt = true;
                } else {
                    for (size_t segmentIndex = 1; segmentIndex < spielzustand.schlange.size(); ++segmentIndex) {
                        if (spielzustand.schlange[segmentIndex].posX == spaltenIndex && spielzustand.schlange[segmentIndex].posY == zeilenKoordinate) {
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
    cout << "Punktzahl: " << spielzustand.punktzahl << "\n";
}

void initialisiereSpiel(Spielzustand& spielzustand) {
    spielzustand.punktzahl = 0;
    spielzustand.gameOver = false;
    spielzustand.hatGeradeGefressen = false;
    spielzustand.schlange.clear();
    int startKopfX = (spielzustand.spielbreite / 2) + 1;
    int startKopfY = (spielzustand.spielhoehe / 2) + 1;
    Schlangenglied startKopf;
    startKopf.posX = startKopfX;
    startKopf.posY = startKopfY;
    spielzustand.schlange.push_back(startKopf);
    Position startKopfPosition{startKopfX, startKopfY};
    spielzustand.futterPosition = berechneFutterposition(spielzustand, startKopfPosition);
}

char leseSteuerung() {
    char steuerungsEingabe;
    if (!(cin >> steuerungsEingabe)) return 'q';
    if (steuerungsEingabe == 'w' || steuerungsEingabe == 'a' || steuerungsEingabe == 's' || steuerungsEingabe == 'd' || steuerungsEingabe == 'q') {
        return steuerungsEingabe;
    }
    throw UnzulaessigeEingabe{};
}

void bewegeSchlange(Spielzustand& spielzustand, char steuerungsCode) {
    if (steuerungsCode == 'q') {
        spielzustand.gameOver = true;
        return;
    }
    Schlangenglied aktuellesKopfSegment = spielzustand.schlange.front();
    Position neueKopfPosition{aktuellesKopfSegment.posX, aktuellesKopfSegment.posY};
    if (steuerungsCode == 'w') neueKopfPosition.posY -= 1;
    else if (steuerungsCode == 's') neueKopfPosition.posY += 1;
    else if (steuerungsCode == 'a') neueKopfPosition.posX -= 1;
    else if (steuerungsCode == 'd') neueKopfPosition.posX += 1;
    if (neueKopfPosition.posX < 1 || neueKopfPosition.posX > spielzustand.spielbreite
        || neueKopfPosition.posY < 1 || neueKopfPosition.posY > spielzustand.spielhoehe) {
        spielzustand.gameOver = true;
        return;
    }
    bool tailBleibtBeiDieserBewegung = spielzustand.hatGeradeGefressen;
    for (size_t segmentIndex = 0; segmentIndex < spielzustand.schlange.size(); ++segmentIndex) {
        bool istSchwanzSegment = (segmentIndex == spielzustand.schlange.size() - 1);
        if (!tailBleibtBeiDieserBewegung && istSchwanzSegment) continue;
        const auto& segment = spielzustand.schlange[segmentIndex];
        if (neueKopfPosition.posX == segment.posX && neueKopfPosition.posY == segment.posY) {
            spielzustand.gameOver = true;
            return;
        }
    }
    Schlangenglied neuesKopfSegment;
    neuesKopfSegment.posX = neueKopfPosition.posX;
    neuesKopfSegment.posY = neueKopfPosition.posY;
    spielzustand.schlange.insert(spielzustand.schlange.begin(), neuesKopfSegment);
    bool hatGefressen = (neueKopfPosition.posX == spielzustand.futterPosition.posX && neueKopfPosition.posY == spielzustand.futterPosition.posY);
    if (hatGefressen) {
        spielzustand.punktzahl += 10;
        spielzustand.futterPosition = berechneFutterposition(spielzustand, neueKopfPosition);
        spielzustand.hatGeradeGefressen = true;
    } else {
        spielzustand.hatGeradeGefressen = false;
    }
    if (!tailBleibtBeiDieserBewegung) {
        if (!spielzustand.schlange.empty()) spielzustand.schlange.pop_back();
    }
}

int main() {
    cout <<'>'<< " ";
    try {
        Spielzustand spielzustand;
        leseSpielfeldGroesse(spielzustand);
        initialisiereSpiel(spielzustand);
        druckeSpielfeld(spielzustand);
        while (!spielzustand.gameOver) {
            try {
                cout <<'>'<< " ";
                char steuerungsCode = leseSteuerung();
                bewegeSchlange(spielzustand, steuerungsCode);
                if (spielzustand.gameOver) break;
                druckeSpielfeld(spielzustand);
            } catch (const UnzulaessigeEingabe&) {
                cout << "Unzulaessige Eingabe! Nutze w, a, s, d zum Bewegen oder q zum Beenden.\n";
            }
        }
        cout << "Game Over! Gesamtpunktzahl: " << spielzustand.punktzahl << ".\n";
        return 0;
    } catch (const BereichsFehler&) {
        cout << "Eingabe ausserhalb des zulaessigen Bereiches.\n";
        return 1;
    } catch (const EingabeFehler&) {
        cout << "Programm wegen fehlender Spielfeldeingabe beendet.\n";
        return 1;
    }
}
