#include "std_lib_inc.h"

vector<double> Mitternachtsformel(double a, double b, double c) {
    // Falls a == 0: Lineare Gleichung b*x + c = 0
    if (a == 0.0) {
        if (b == 0.0) {
            throw runtime_error("Unbestimmt oder keine Loesung: a == 0 und b == 0.");
        }
        return { -c / b }; // eine reelle Loesung
    }

    double zwischenWert = b*b - 4.0*a*c;
    if (zwischenWert < 0.0) {
        throw runtime_error("Keine reellen Loesungen (Diskriminante < 0).");
    } else if (zwischenWert == 0.0) {
        double x = -b / (2.0 * a);
        return { x }; // einfacher/doppelter Wurzel
    } else {
        double s = sqrt(zwischenWert);
        double x1 = (-b + s) / (2.0 * a);
        double x2 = (-b - s) / (2.0 * a);
        return { x1, x2 };
    }
}

int main() {
    double a, b, c;
    cout << "Gib Koeffizienten a b c ein: ";
    if (!(cin >> a >> b >> c)) {
        cerr << "Ungueltige Eingabe.\n";
        return 1;
    }

    try {
        vector<double> loesungen = Mitternachtsformel(a, b, c);
        if (loesungen.size() == 1) {
            cout << "Eine reelle Loesung: x = " << loesungen[0] << "\n";
        } else {
            cout << "Zwei reelle Loesungen: x1 = " << loesungen[0]
                 << ", x2 = " << loesungen[1] << "\n";
        }
    } catch (const runtime_error& e) {
        cout << "Fehler: " << e.what() << "\n";
    }
}
