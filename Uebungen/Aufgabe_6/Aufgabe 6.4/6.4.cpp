//
// Created by Sebastian 24.11.2025.
//

#include "std_lib_inc.h"


int main() {
    activateAssertions();

    double doublE = 0;
    while(cin >> doublE) {
        int inT = doublE;
        char chaR = inT;
        int int2 = chaR;
        cout << "d == " << doublE
             << ", i == " << inT
             << ", i2 == " << int2
             << ", char(" << chaR << ")\n";
    }
}