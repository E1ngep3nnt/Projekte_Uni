//
// Created by Sebastian on 25.10.2025.
//

#include "std_lib_inc.h"
vector<double> abstaende = {};
double durchschnittBerechnen(vector<double>eingabe) {
    double summe=0.0;
    for (double abstand:abstaende) {
        summe += abstand;
    }return summe/ abstaende.size();
}

int main() {
    double temperatur = 0.0;
    cin >> temperatur;
    while(cin){
            abstaende.push_back(temperatur);
            cin >> temperatur;
        }
        cout << "Der Durchschnittabstand ist " << durchschnittBerechnen(abstaende) << '\n';
        return 0;
    }
