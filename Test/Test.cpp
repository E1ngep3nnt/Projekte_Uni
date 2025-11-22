//
// Created by Sebastian on 22.11.2025.
//

#include "std_lib_inc.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Schlangenglied {
public:
    int x, y;
};

class Point2d {
public:
    int px, py;
};

class Spielzustand {
public:
    int spielbreite{};
    int spielhoehe{};
    vector<Schlangenglied> python;
    int punktzahl{};
    bool gameOver{};
    bool gegessen{}; // Wachstum wartet (wird bei der nächsten Bewegung umgesetzt)
    Point2d futter{};
};

class EingabeFehler {};
class BereichsFehler {};
class UnzulaessigeEingabe {};

// Liest die Spielfeldgröße (zwei ints) ein und validiert den Bereich [3,25]
void leseSpielfeldgroesse(Spielzustand &sz) {
    int b, h;
    if (!(cin >> b)) throw EingabeFehler{};
    if (!(cin >> h)) throw EingabeFehler{};
    if (b < 3 || b > 25 || h < 3 || h > 25) throw BereichsFehler{};
    sz.spielbreite = b;
    sz.spielhoehe = h;
}

// Erzeugt Futter basierend auf der gegebenen Kopfposition und Spielfeldgröße
Point2d berechneFutter(int kopfX, int kopfY, int width, int height) {
    Point2d p;
    p.px = ((17 * kopfX) % width) + 1;
    p.py = ((13 * kopfY) % height) + 1;
    return p;
}

// Initialisiert Spielzustand: Kopfposition, Punktzahl, Futter, etc.
void initialisiereSpiel(Spielzustand &sz) {
    sz.punktzahl = 0;
    sz.gameOver = false;
    sz.gegessen = false;
    int headX = (sz.spielbreite / 2) + 1;
    int headY = (sz.spielhoehe / 2) + 1;
    sz.python.clear();
    Schlangenglied head{headX, headY};
    sz.python.push_back(head);
    sz.futter = berechneFutter(headX, headY, sz.spielbreite, sz.spielhoehe);
}

// Gibt das Spielfeld mit Priorisierung (Kopf O, Futter #, Körper o) aus
void druckeSpielfeld(const Spielzustand &sz) {
    int width = sz.spielbreite;
    int height = sz.spielhoehe;

    for (int row = 0; row < height + 2; ++row) {
        if (row == 0 || row == height + 1) {
            cout << "|" << string(width, '-') << "|\n";
        } else {
            int y = row; // y von 1..height
            cout << "|";
            for (int x = 1; x <= width; ++x) {
                bool gedruckt = false;
                if (!sz.python.empty() && sz.python.front().x == x && sz.python.front().y == y) {
                    cout << 'O';
                    gedruckt = true;
                } else if (!gedruckt && sz.futter.px == x && sz.futter.py == y) {
                    cout << '#';
                    gedruckt = true;
                } else {
                    // Körper prüfen (ohne Kopf)
                    for (size_t i = 1; i < sz.python.size(); ++i) {
                        if (sz.python[i].x == x && sz.python[i].y == y) {
                            cout << 'o';
                            gedruckt = true;
                            break;
                        }
                    }
                }
                if (!gedruckt) cout << ' ';
            }
            cout << "|\n";
        }
    }
    cout << "Punktzahl: " << sz.punktzahl << "\n";
}

// Liest eine einzelne Bewegungs-Eingabe (eine Zeile). Akzeptiert w/a/s/d/q, wirft bei anderen Zeichen.
char leseBewegung() {
    string line;
    if (!std::getline(cin, line)) throw EingabeFehler{};
    if (line.empty()) throw UnzulaessigeEingabe{};
    char c = line[0];
    if (c == 'w' || c == 'a' || c == 's' || c == 'd' || c == 'q') return c;
    throw UnzulaessigeEingabe{};
}

// Aktualisiert den Spielzustand anhand der Eingabe
void aktualisiereSpiel(Spielzustand &sz, char move) {
    bool pendingGrowth = sz.gegessen; // Wachstum aus vorherigem Happen
    Schlangenglied oldHead = sz.python.front();
    Schlangenglied newHead = oldHead;

    if (move == 'w') newHead.y -= 1;
    else if (move == 's') newHead.y += 1;
    else if (move == 'a') newHead.x -= 1;
    else if (move == 'd') newHead.x += 1;

    bool willEat = (newHead.x == sz.futter.px && newHead.y == sz.futter.py);
    if (willEat) {
        sz.punktzahl += 10;
        sz.gegessen = true; // Wachstum wird bei der nächsten Bewegung umgesetzt
        sz.futter = berechneFutter(newHead.x, newHead.y, sz.spielbreite, sz.spielhoehe);
    } else {
        // kein neues Futter -> sz.gegessen bleibt wie es ist (nur pendingGrowth steuert Pop)
    }

    // 2. Spielende prüfen: außerhalb oder Kollisionsprüfung mit Körper
    if (newHead.x < 1 || newHead.x > sz.spielbreite || newHead.y < 1 || newHead.y > sz.spielhoehe) {
        sz.gameOver = true;
        return;
    }

    bool tailWillMove = !pendingGrowth;
    size_t bodySize = sz.python.size();
    for (size_t i = 0; i < bodySize; ++i) {
        if (tailWillMove && i == bodySize - 1) continue; // letzter Teil wird wegbewegt -> darf überlaufen werden
        if (sz.python[i].x == newHead.x && sz.python[i].y == newHead.y) {
            sz.gameOver = true;
            return;
        }
    }

    // Segmente verschieben
    sz.python.insert(sz.python.begin(), newHead);
    if (!pendingGrowth) {
        if (!sz.python.empty()) sz.python.pop_back();
    } else {
        // Wachstum wurde jetzt umgesetzt; zukünftige Schritte nicht mehr "pending"
        sz.gegessen = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    try {
        Spielzustand s;
        leseSpielfeldgroesse(s);
        initialisiereSpiel(s);
        druckeSpielfeld(s);

        while (true) {
            char mv;
            try {
                mv = leseBewegung();
            } catch (const UnzulaessigeEingabe &) {
                cout << "Unzulaessige Eingabe! Nutze w, a, s, d zum Bewegen oder q zum Beenden.\n";
                continue;
            } catch (const EingabeFehler &) {
                cout << "Programm wegen fehlender Spielfeldeingabe beendet.\n";
                return 1;
            }

            if (mv == 'q') {
                cout << "Game Over! Gesamtpunktzahl: " << s.punktzahl << ".\n";
                return 0;
            }

            aktualisiereSpiel(s, mv);
            if (s.gameOver) {
                cout << "Game Over! Gesamtpunktzahl: " << s.punktzahl << ".\n";
                return 0;
            }
            druckeSpielfeld(s);
        }
    } catch (const BereichsFehler &) {
        cout << "Eingabe ausserhalb des zulaessigen Bereiches.\n";
        return 1;
    } catch (const EingabeFehler &) {
        cout << "Programm wegen fehlender Spielfeldeingabe beendet.\n";
        return 1;
    } catch (...) {
        cout << "Programm wegen unbekanntem Fehler beendet.\n";
        return 1;
    }
}
