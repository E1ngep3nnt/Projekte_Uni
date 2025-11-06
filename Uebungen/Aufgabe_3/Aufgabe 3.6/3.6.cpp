//
// Created by Sebastian on 24.10.2025.
//


#include <windows.h>
#include "std_lib_inc.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    cout << "Schreiben sie einen Satz/Text! \n";
    string eingabe;
    vector <string> wörter = {};
    vector <string> unzulässig = {"Brokkoli","Bratwurst","Champignons"};
    getline(cin, eingabe);
    istringstream iss(eingabe);
    string wort;

    while (iss >> wort) {
        if (find(unzulässig.begin(), unzulässig.end(), wort) != unzulässig.end()) {
            wort = " BEEP ";
        }
        wörter.push_back(wort);
    }

    cout << "\nÜberprüfter Text:\n";
    for (auto& w : wörter) {
        cout << w << " ";
    }
    cout << "\n";
}