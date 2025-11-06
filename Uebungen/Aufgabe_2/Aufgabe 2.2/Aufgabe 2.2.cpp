//
// Created by Sebastian on 24.09.2025.
// Aufgabe 1.2

#include <windows.h>
#include "std_lib_inc.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    //Teil a
    string name;
    cout << "Bitte gib deinen Namen ein (drücke danach 'enter'):\n";
    cin >> name;

    string adressat;
    cout << "Bitte gib den Namen des Adressaten ein.\n";
    cin >> adressat;
    cout << "Moin " << adressat << ",\n\t";

    //Teil b
    cout << "Wie geht es dir?\n";
    cout << "Es wäre schön wenn du dich mal melden könntest\n";

    //Teil c
    cout << "Gib den Namen eines anderen Freundes/einer anderen Freundin an.\n";
    string freund_name;
    cin >> freund_name;
    cout << "Hast du in letzter Zeit "<< freund_name << " mal gesehen?\n";

    // Teil d
    char freund_geschlecht = '0';
    cout << "Gib das Geschlechts des Freundes (m)/ der Freundin(w) an\n";
    cin >> freund_geschlecht;
    if (freund_geschlecht == 'm') {
        cout << "Wenn du " << freund_name << " siehst, sag ihm bitte, er soll mich anrufen.\n";
    }
    if (freund_geschlecht == 'w') {
        cout << "Wenn du " << freund_name << " siehst, sag ihr bitte, sie soll mich anrufen.\n";
    }
    if (freund_geschlecht != 'm' && freund_geschlecht != 'w') {
        simple_error("Das Geschlecht kann nur männlich (m) oder weiblich (w) sein.");
    }

    // Teil e
    int alter;
    cout << "Gib das Alter des/der Adressaten ein.\n";
    cin >> alter;
    if (!cin) {
        simple_error("Das Alter muss eine Zahl sein.");
    }
    if (alter <=0 || alter >=110) {
        simple_error("Das kann nicht sein!");
    }
    cout << "Ich höre,du hattest gerade Geburtstag und bist " <<alter<< " Jahre alt geworden\n";

    // Teil f
    if (alter <=12) {
        cout << "Nächstes Jahr bist du " <<alter+1<< " Jahre alt!";
    }
    if (alter ==17) {
        cout << "Nächstes Jahr darfst du wählen!";
    }
    if (alter >=70) {
    cout << "Ich hoffe dir bekommt die Rente!\n";
    }

    //Teil g
    cout << "Viele Grüße \n\n" << name;

    return 0;
}
