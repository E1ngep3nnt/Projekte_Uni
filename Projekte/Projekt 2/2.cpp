#include "std_lib_inc.h"

// Globale Variablen
vector<int> werte={};
constexpr int fenster=10;
constexpr int binZaehler=10;

// Einzelwert prüfen
void pruefeEingabewert(int n) {
    if (n < 0 || n > 99) {
        simple_error("Eingabe ausserhalb des zulaessigen Bereiches.\n");
    }
}

// Werte einlesen
vector<int> eingabewerteEinlesen() {
    vector<int> werte;
    int n;
    if (!(cin >> n)) {
        simple_error("Programm wegen fehlender Zahlenfolge beendet.\n");
    }

    // Werte prüfen
    pruefeEingabewert(n);
    werte.push_back(n);
    while (cin >> n) {
        pruefeEingabewert(n);
        werte.push_back(n);
    }
    return werte;
}

//Daten Vergleichen
int validiereEingabeliste() {
    int anzahlDaten = werte.size();
    if (anzahlDaten < 1) {
        simple_error("Programm wegen fehlender Zahlenfolge beendet.\n");
    }
    return anzahlDaten;
}

// Bins errechnen
vector<int> zaehleWerteProBin() {
    vector<int> bins(binZaehler, 0);
    for (int x:werte) {
        int index = x / fenster;
        if (0 <= index && index < binZaehler) ++bins[index];
    }
    return bins;
}

// Minimum Bin finden
int findeErstesNichtLeeresBin(const vector<int>& bins) {
    int minBin = 0;
    while (minBin < binZaehler && bins[minBin] == 0) ++minBin;
    return minBin;
}

// Maximum Bin finden
int findeLetztesNichtLeeresBin(const vector<int>& bins) {
    int maxBin = binZaehler - 1;
    while (maxBin >= 0 && bins[maxBin] == 0) --maxBin;
    return maxBin;
}

// Maximale Höhe finden
int findeMaxHistogrammHoehe (const vector<int>& bins, int minBin, int maxBin) {
    int maxHoehe = 0;
    for (int i = minBin; i <= maxBin; ++i) {
        if (bins[i] > maxHoehe) maxHoehe = bins[i];
    }
    return maxHoehe;
}

// Balken drucken
void druckeHistogrammZeilen(const vector<int>& bins, int minBin, int maxBin, int maxHoehe) {
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
void druckeHistogrammLabels(int minBin, int maxBin) {
    for (int i = minBin; i <= maxBin; ++i) {
        int niedrig = i * fenster;
        int hoch = niedrig + fenster - 1;
        string formatLow = formatZahlMitNull(niedrig);
        string formatHigh = formatZahlMitNull(hoch);
        cout << formatLow << '-' << formatHigh << "  ";
    }
    cout << '\n';
}

// Histogramm erstellen und Ausgeben
void erstelleHistogramm() {
    validiereEingabeliste();
    vector<int> bins = zaehleWerteProBin();

    int minBin = findeErstesNichtLeeresBin(bins);
    int maxBin = findeLetztesNichtLeeresBin(bins);
    if (minBin > maxBin) return;

    int maxHoehe = findeMaxHistogrammHoehe(bins, minBin, maxBin);
    druckeHistogrammZeilen(bins, minBin, maxBin, maxHoehe);
    druckeHistogrammLabels(minBin, maxBin);
}

int main() {
    werte = eingabewerteEinlesen();
    erstelleHistogramm();
    return 0;
}