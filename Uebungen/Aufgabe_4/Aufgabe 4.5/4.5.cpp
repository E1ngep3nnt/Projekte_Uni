//
// Created by Sebastian on 10.11.2025.
//

#include "std_lib_inc.h"

string IntzuBinaer(int n) {
    if (n < 0) return "";
    if (n == 0) return "0";
    string bits= "";
    while (n>0) {
        bits.push_back(char('0'+(n%2)));
        n/=2;
    }
    reverse(bits.begin(), bits.end());
    return bits;
}

int main() {
    cout << "Gib eine ganze Zahl ein (q zum Beenden): \n";
    while (true) {
        if (!(cin >> ws)) break;
        if (cin.peek() == 'q') break;
        int x;
        if (!(cin >> x)) break;
        cout << x << " -> " << IntzuBinaer(x) << '\n';
        cout << "Noch eine Zahl (q zum Beenden): \n";
    }
    return 0;
}