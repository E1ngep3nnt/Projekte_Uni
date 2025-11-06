//
// Created by Sebastian on 24.10.2025.
//

#include <windows.h>
#include "std_lib_inc.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int a=0;
    int b=0;
    int c=0;
    int temp=0;
    cout << "Bitte gib drei Zahlen ein:\n";
    cin >> a >> b >> c;

    if (!cin) {
        simple_error("Die Eingabe ist falsch!");
    }

    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }

    if (b > c) {
        temp = b;
        b = c;
        c = temp;
    }

    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }
    cout << a << ", " << b << ", " << c << '\n';
}