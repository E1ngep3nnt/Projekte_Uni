//
// Created by Sebastian on 09.11.2025.
//

#include "std_lib_inc.h"

class Eintrag {
public:
    string name;
    int punkte;
};

int main() {
    vector<Eintrag> scoreBoard;
    string eingabe_name = "x";
    int eingabe_punkte = 0;

    cout << "Gib Name-Punkte Paare an um einen Eintrag ins Score-Board hinzuzufügen\n";
    cout << "Verwende 'x' zum Beenden der Eingabe.\n";
    while(cin) {
        cin >> eingabe_name >> eingabe_punkte;

        if(!cin) {
            simple_error("Fehler bei der Eingabe!");
        }
        else if(eingabe_name == "x") {
            break;
        }

        Eintrag temp{eingabe_name, eingabe_punkte};
        scoreBoard.push_back(temp);
    }

    for(int i = 0; i < scoreBoard.size(); ++i) {
        for(int j = 0; j < scoreBoard.size(); ++j) {
            if(i != j) {
                if(scoreBoard[i].name == scoreBoard[j].name) {
                    simple_error("Jeder Name darf nur ein Mal vorkommen!");
                }
            }
        }
    }

    cout << "Gib einen Namen aus dem Score-Board an um seine Punkte zu erfahren:\n";
    cout << "Verwende 'x' zum Beenden der Eingabe.\n";
    while(cin) {
        cin >> eingabe_name;

        if(!cin) {
            simple_error("Fehler bei der Eingabe!");
        }
        else if (eingabe_name == "x") {
            break;
        }

        for(Eintrag e : scoreBoard) {
            if(e.name == eingabe_name) {
                cout << eingabe_name << " hat " << e.punkte << " erreicht.\n";
            }
        }
    }
}