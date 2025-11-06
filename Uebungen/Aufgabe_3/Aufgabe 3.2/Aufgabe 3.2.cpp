//
// Created by Sebastian on 29.09.2025.
// Aufgabe 2.2

#include <windows.h>
#include "std_lib_inc.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Teil a

    //cout << "Gib zwei Zahlen ein (oder ein Zeichen zum Beenden):\n";
    //int zahl1, zahl2;

    //while (true) {
    //    cout << "> ";  // Eingabeaufforderung

    //    if (cin >> zahl1 >> zahl2) {
    //        cout << "Eingabe: " << zahl1 << " " << zahl2 << "\n";
    //    } else {
    //        cout << "Beendet, da keine Zahl mehr eingegeben wurde.\n";
    //        break;  // raus aus der while
    //    }
    //}
    //return 0;

    //Teil b
    //cout << "Gib eine Zahl ein (oder ein Zeichen zum Beenden):\n";
    //int zahl1 = 0, zahl2 = 0;

    // Teil d
    //double zahl1 = 0.0, zahl2 = 0.0;

    //while (cin >> zahl1 >> zahl2) {

    // Teil d
    //  if (fabs(zahl1-zahl2)<0.01) {
    //      cout << "Die Zahlen sind fast gleich!\n";
    //  } //Teil c
    //  else if (zahl1 == zahl2){
    //      cout << "Die Zahlen sind gleich!\n";
    //  }
    //  else if (zahl1 > zahl2){
    //      cout << "Die kleinere Zahl ist: " << zahl2 << "\n";
    //  } else {
    //     cout << "Die kleinere Zahl ist: " << zahl1 << "\n";
    // }
    //}
    //Teil f
    //double eingabe = 0.0;
    //double kleinsteZahl = 0.0;
    //double groessteZahl = 0.0;

    //if (cin >> eingabe) {
    //    kleinsteZahl = eingabe;
    //    groessteZahl = eingabe;
    //    cout << eingabe << " ist die kleinste und größte Zahl bisher.\n";
    //} else {
    //    return 0;
    //}
    //while (cin >> eingabe) {
    //    cout << "Eingegeben: " << eingabe << "\n";

    //    if (eingabe < kleinsteZahl) {
    //        kleinsteZahl = eingabe;
    //        cout << "Die kleinste Zahl bis jetzt.\n";
    //    } else if (eingabe > groessteZahl) {
    //        groessteZahl = eingabe;
    //        cout << "Die größte Zahl bis jetzt.\n";
    //    }
    //}

    //cout << "Eingabe beendet.\n";

    //Teil g
    vector<string> einheiten = {"cm", "in", "ft", "m"};
    double kleinste = 0.0;
    double groesste  = 0.0;
    double summe     = 0.0;
    int anzahl       = 0;
    bool ersteEingabe = true;
    double cmprom = 100.0;
    double cmproin = 2.54;
    double inproft = 12.0;
    double zahl;
    string einheit;

    cout << "Gib Zahl und Einheit ein (z.B. 10 cm).\n";

    while (cin >> zahl >> einheit) {
        bool valide = false;
        for (const string &e: einheiten) {
            if (einheit == e) {
                valide = true;
                break;
            }
        }

        if (!valide) {
            cout << "Diese Einheit kenne ich nicht.\n";
            continue;
        }

        double wertInMeter = 0.0;
        if (einheit == "cm") {
            double wertInCm = zahl;
            wertInMeter = wertInCm / cmprom;
        } else if (einheit == "in") {
            double wertInCm = zahl * cmproin;
            wertInMeter = wertInCm / cmprom;
        } else if (einheit == "ft") {
            double wertInCm = zahl * inproft * cmproin;
            wertInMeter = wertInCm / cmprom;
        } else {
            wertInMeter = zahl;
        }


        if (ersteEingabe) {
            kleinste = groesste = wertInMeter;
            ersteEingabe = false;
        } else {
            if (wertInMeter < kleinste) kleinste = wertInMeter;
            if (wertInMeter > groesste)  groesste = wertInMeter;
        }

        summe += wertInMeter;
        ++anzahl;
    }
    if (anzahl > 0) {
        cout << "Statistik (Längen in Metern):\n";
        cout << "Anzahl eingegebener Längen: " << anzahl << "\n";
        cout << "Summe: " << summe << " in Meter \n";
        cout << "Kleinste: " << kleinste << " in Meter\n";
        cout << "Größte: " << groesste << " in Meter\n";
    } else {
        cout << "Keine gültigen Längen eingegeben.\n";
    }

    return 0;
}