//
// Created by Sebastian on 24.10.2025.
//

#include <windows.h>
#include "std_lib_inc.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int a=0;
        while (true) {
            a = a + 7;
            if (a > 1000) break;
            cout << a << "\n";
        }
    }
