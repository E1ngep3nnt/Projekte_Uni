//
// Created by Sebastian on 24.10.2025.
//

#include <windows.h>
#include "std_lib_inc.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    char op=' ';
    double zahl1=0.0, zahl2=0.0;
    cin >>zahl1 >>op>>zahl2;

    if (op == '+') {
        cout << "Die Summe aus " <<zahl1<< " und " << +zahl2<< " ist " << zahl1+zahl2 <<"\n";
    }
    if (op=='-') {
        cout << "Die Differrenz aus " <<zahl1<< " und " << zahl2<< " ist " << zahl1-zahl2 <<"\n";
    }
    if (op=='*') {
        cout << "Die Produkt aus " <<zahl1<< " und " << +zahl2<< " ist " << zahl1*zahl2 <<"\n";
    }
    if (op == '/') {
        if (zahl2 == 0 || zahl1 == 0) {
            cout << "Division durch 0 ist nicht erlaubt!\n";
        } else {
            cout << "Der Quotient aus " << zahl1 << " und " << zahl2 << " ist " << (zahl1 / zahl2) << "\n";
        }
    }
}