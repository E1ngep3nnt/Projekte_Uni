//
// Created by Sebastian on 24.11.2025.
//

#include "std_lib_inc.h"

class Token {
    public:
    char art;
    double wert;
};

//Globale Variablen
double links_wert=0.0;
char oper='?';
double rechts_wert=0.0;
double ergebniss_wert=0.0;

//Liest Token von cin ein
Token liesToken() {
    cin >> links_wert >> oper >> rechts_wert;
};

//Kümmert sich um Ausdrücke, also + &- // Benutzt Selber liesToken und term()
double ausdruck() {
    if (oper=='+') {
        ergebniss_wert = links_wert + rechts_wert;
    } else if (oper=='-') {
        ergebniss_wert = links_wert - rechts_wert;
    }
    cout << ergebniss_wert;
};

//Kümmert sich um Terme * & / . Benutzt liesToken und zahl()
double term() {
    if (oper=='*') {
        ergebniss_wert = links_wert * rechts_wert;
    } else if (oper=='/') {
        ergebniss_wert = links_wert / rechts_wert;
    }
};

//Kümmert sich um das einlesen von Zahlen und nutzt liesToken
double zahl() {
    liesToken();
};


int main() {
    vector<Token> token_liste;

    while (cin) {
        Token token=liesToken();
        token_liste.push_back(token);
    }
    ausdruck();
    term();
}