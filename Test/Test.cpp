#include "std_lib_inc.h"

// Fehlerklassen für Validierung und Steuerung
class BereichsFehler{};           // Eingabe ausserhalb des erlaubten Bereichs
class EingabeFehler{};            // Nicht-numerische Eingabe bei Spielfeldgroesse
class UnzulaessigeEingabe{};      // Falsches Steuerungszeichen

// 2D-Position auf dem Spielfeld
struct Position {
    int x{0};
    int y{0};
};

// Repräsentiert den kompletten Spielzustand
class Spielzustand {
public:
    int spielbreite{0};
    int spielhoehe{0};
    vector<Position> schlange; // erstes Element ist der Kopf
    Position futter{0,0};
    int punktzahl{0};
    bool beendet{false};
    bool hatGeradeGefressen{false};
};

/* Liest eine Ganzzahl und validiert den Bereich [3,25];
 * wirft Exceptions bei Fehlern (BereichsFehler, EingabeFehler). */
int leseDimension() {
    int wert;
    if (!(cin >> wert)) {
        throw EingabeFehler{};
    }
    if (wert < 3 || wert > 25) {
        throw BereichsFehler{};
    }
    return wert;
}

/* Liest Spielfeldbreite und -hoehe und speichert im Spielzustand. */
void leseSpielfeldGroesse(Spielzustand& s) {
    s.spielbreite = leseDimension();
    s.spielhoehe  = leseDimension();
}

/* Berechnet eine Futterposition basierend auf der Kopfposition;
 * Formel: x=((17*x_kopf)%breite)+1, y=((13*y_kopf)%hoehe)+1
 * vermeidet Kollision mit Schlange, bleibt deterministisch. */
Position berechneFutter(const Spielzustand& s, const Position& kopf) {
    Position f{ ((17 * kopf.x) % s.spielbreite) + 1, ((13 * kopf.y) % s.spielhoehe) + 1 };
    auto belegt = [&](const Position& p) {
        for (const auto& seg : s.schlange) if (seg.x == p.x && seg.y == p.y) return true;
        return false;
    };
    int step = 1;
    while (belegt(f)) {
        f.x = ((f.x + step - 1) % s.spielbreite) + 1;
        f.y = ((f.y + step - 1) % s.spielhoehe) + 1;
        ++step;
        if (step > s.spielbreite * s.spielhoehe) break;
    }
    return f;
}

/* Initialisiert Punktzahl, Schlange (nur Kopf) und Futter. */
void initialisiereSpiel(Spielzustand& s) {
    s.punktzahl = 0;
    s.beendet   = false;
    s.schlange.clear();
    Position kopf{ (s.spielbreite / 2) + 1, (s.spielhoehe / 2) + 1 };
    s.schlange.push_back(kopf);
    s.futter = berechneFutter(s, kopf);
}

/* Gibt das Spielfeld exakt im geforderten Format aus. */
void zeichneSpielfeld(const Spielzustand& s) {
    cout << "|" << string(s.spielbreite, '-') << "|\n";
    for (int y = 1; y <= s.spielhoehe; ++y) {
        cout << "|";
        for (int x = 1; x <= s.spielbreite; ++x) {
            bool gedruckt = false;
            if (!s.schlange.empty() && s.schlange.front().x == x && s.schlange.front().y == y) {
                cout << 'O';
                gedruckt = true;
            }
            if (!gedruckt && s.futter.x == x && s.futter.y == y) {
                cout << '#';
                gedruckt = true;
            }
            if (!gedruckt) {
                for (size_t i = 1; i < s.schlange.size(); ++i) {
                    if (s.schlange[i].x == x && s.schlange[i].y == y) {
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
    cout << "|" << string(s.spielbreite, '-') << "|\n";
    cout << "Punktzahl: " << s.punktzahl << "\n";
}

/* Liest eine Steuerungseingabe; erlaubt w,a,s,d,q; andere Zeichen werfen UnzulaessigeEingabe. */
char leseSteuerung() {
    char c;
    if (!(cin >> c)) {
        return 'q';
    }
    if (c == 'w' || c == 'a' || c == 's' || c == 'd' || c == 'q') return c;
    throw UnzulaessigeEingabe{};
}

/* Wendet eine Bewegung auf den Spielzustand an:
 * verschiebt Segmente, prüft Essen und Kollisionen. */
void bewegeSchlange(Spielzustand& s, char steuercode) {
    if (steuercode == 'q') { s.beendet = true; return; }

    Position kopf = s.schlange.front();
    Position neu = kopf;
    if (steuercode == 'w')      neu.y -= 1;
    else if (steuercode == 's') neu.y += 1;
    else if (steuercode == 'a') neu.x -= 1;
    else if (steuercode == 'd') neu.x += 1;

    if (neu.x < 1 || neu.x > s.spielbreite || neu.y < 1 || neu.y > s.spielhoehe) {
        s.beendet = true;
        return;
    }
    // Selbstkollision: Wenn der Schwanz in dieser Runde entfernt wird,
    // darf das bisherige Schwanzfeld betreten werden (kein Kollisionsende).
    bool skipTailRemovalThisMove = s.hatGeradeGefressen; // true -> Schwanz bleibt, Feld belegt
    for (size_t i = 0; i < s.schlange.size(); ++i) {
        bool istSchwanzSegment = (i == s.schlange.size() - 1);
        if (!skipTailRemovalThisMove && istSchwanzSegment) {
            continue; // Schwanz wird entfernt, Feld gilt nicht als belegt
        }
        const auto& seg = s.schlange[i];
        if (neu.x == seg.x && neu.y == seg.y) { s.beendet = true; return; }
    }

    s.schlange.insert(s.schlange.begin(), neu);

    bool hatGefressen = (neu.x == s.futter.x && neu.y == s.futter.y);
    if (hatGefressen) {
        s.punktzahl += 10;
        s.futter = berechneFutter(s, neu);
        s.hatGeradeGefressen = true; // Wachstum erst in der naechsten Bewegung sichtbar
    } else {
        s.hatGeradeGefressen = false;
    }
    if (!skipTailRemovalThisMove) {
        if (!s.schlange.empty()) s.schlange.pop_back();
    }
}

int main() {
    try {
        Spielzustand s;
        leseSpielfeldGroesse(s);
        initialisiereSpiel(s);
        zeichneSpielfeld(s);

        while (!s.beendet) {
            try {
                char cmd = leseSteuerung();
                bewegeSchlange(s, cmd);
                if (s.beendet) break;
                zeichneSpielfeld(s);
            } catch (const UnzulaessigeEingabe&) {
                cout << "Unzulaessige Eingabe! Nutze w, a, s, d zum Bewegen oder q zum Beenden.\n";
            }
        }
        cout << "Game Over! Gesamtpunktzahl: " << s.punktzahl << " .\n";
        return 0;
    } catch (const BereichsFehler&) {
        cout << "Eingabe ausserhalb des zulaessigen Bereiches.\n";
        return 1;
    } catch (const EingabeFehler&) {
        cout << "Programm wegen fehlender Spielfeldeingabe beendet.\n";
        return 1;
    }
}