//
// Erstellt von Sebastian am 08.11.2025
//

#include "std_lib_inc.h"

// Globale Variablen
vector<int> werte={};
constexpr int fenster=10;
constexpr int binZaehler=10;

// Einzelwert prüfen
bool wertPruefen(int n) {
    if (n < 0 || n > 99) {
        simple_error("Eingabe ausserhalb des zulaessigen Bereiches.\n");
    }
    return true;
}

// Werte einlesen
vector<int> werteEinlesen() {
    vector<int> werte;
    int n;
    if (!(cin >> n)) {
        simple_error("Programm wegen fehlender Zahlenfolge beendet.\n");
    }

    // Werte prüfen
    wertPruefen(n);
    werte.push_back(n);
    while (cin >> n) {
        wertPruefen(n);
        werte.push_back(n);
    }
    return werte;
}

//Daten Vergleichen
int datenVergleichen() {
    int anzahlDaten = werte.size();
    if (anzahlDaten < 1) {
        simple_error("Programm wegen fehlender Zahlenfolge beendet.\n");
    }
    return anzahlDaten;
}

// Bins errechnen
vector<int> berechneBins() {
    vector<int> bins(binZaehler, 0);
    for (int x:werte) {
        int index = x / fenster;
        if (0 <= index && index < binZaehler) ++bins[index];
    }
    return bins;
}

// Minimum Bin finden
int findeMinBin(const vector<int>& bins) {
    int minBin = 0;
    while (minBin < binZaehler && bins[minBin] == 0) ++minBin;
    return minBin;
}

// Maximum Bin finden
int findeMaxBin(const vector<int>& bins) {
    int maxBin = binZaehler - 1;
    while (maxBin >= 0 && bins[maxBin] == 0) --maxBin;
    return maxBin;
}

// Maximale Höhe finden
int findeMaxHoehe(const vector<int>& bins, int minBin, int maxBin) {
    int maxHoehe = 0;
    for (int i = minBin; i <= maxBin; ++i) {
        if (bins[i] > maxHoehe) maxHoehe = bins[i];
    }
    return maxHoehe;
}

// Balken drucken
void druckeBalken(const vector<int>& bins, int minBin, int maxBin, int maxHoehe) {
    for (int level = maxHoehe; level >= 1; --level) {
        cout << "  ";
        for (int i = minBin; i <= maxBin; ++i) {
            if (bins[i] >= level) cout << 'x';
            else cout << ' ';
            cout << "      ";
        }
        cout << '\n';
    }
}

// Zahl mit führender Null formatieren
string formatZahlMitNull(int n) {
    if (n < 10) return string("0") + to_string(n);
    return to_string(n);
}

// Achsenbeschriftung drucken
void druckeLabels(int minBin, int maxBin) {
    for (int i = minBin; i <= maxBin; ++i) {
        int niedrig = i * fenster;
        int hoch = niedrig + fenster - 1;
        string formatLow = formatZahlMitNull(niedrig);
        string formatHigh = formatZahlMitNull(hoch);
        cout << formatLow << '-' << formatHigh << "  ";
    }
    cout << '\n';
}

// Daten sortieren
void datenSortieren() {
    datenVergleichen();
    vector<int> bins = berechneBins();

    int minBin = findeMinBin(bins);
    int maxBin = findeMaxBin(bins);
    if (minBin > maxBin) return;

    int maxHoehe = findeMaxHoehe(bins, minBin, maxBin);
    druckeBalken(bins, minBin, maxBin, maxHoehe);
    druckeLabels(minBin, maxBin);
}

int main() {
    werte = werteEinlesen();
    datenSortieren();
    return 0;
}
