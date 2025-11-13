//
// Created by Fritz Bökler
//

#include "std_lib_inc.h"

int main()
{
    try {
        // << Kopieren Sie den Code hier hin >>
        keep_window_open();     // Für Windows-NutzerInnen
        return 0;
    }
    catch(exception& e)
    {
        cout << "Fehler: " << e.what() << '\n';
        keep_window_open();     // Für Windows-NutzerInnen
        return 1;
    }
    catch(...) {
        cout << "Ups: Unbekannter Fehler!\n";
        keep_window_open();     // Für Windows-NutzerInnen
        return 2;
    }
}

/*
 * (1) Cout << "Erfolg!\n";
 * (2) cout << "Erfolg!\n";
 * (3) cout << "Erfolg" << !\n"
 * (4) cout << erfolg << '\n';
 * (5) string res = 7; vector<int> v(10); v[5] = res; cout << "Erfolg!\n";
 * (6) vector<int> v(10); v(5) = 7; if (v(5) != 7) cout << "Erfolg!\n";
 * (7) if(bed) cout << "Erfolg!\n"; else cout << "Misserfolg!\n";
 * (8) bool c = false; if(c) cout << "Erfolg!\n"; else cout << "Misserfolg!\n";
 * (9) string s = "affe"; boo c = "elephant" < s; if(c) cout << "Erfolg!\n";
 * (10) string s = "affe"; if(s == "elephant") cout << "Erfolg!\n";
 * (11) string s = "affe"; if(s == "elephant") cout < "Erfolg!\n";
 * (12) string s = "affe"; if(s + "elephant") cout < "Erfolg!\n";
 * (13) vector<char> v(5); for(int i = 0; 0 < v.size(); ++i) ; cout << "Erfolg!\n";
 * (14) vector<char> v(5); for(int i = 0; i <= v.size(); ++i) ; cout << "Erfolg!\n";
 * (15) vector<char> s = {'E', 'r', 'f', 'o', 'l', 'g', '!', '\n'}; for(int i = 0; i < 6; ++i) cout << s[i];
 * (16) if(true) then cout << "Erfolg!\n"; else cout << "Misserfolg!\n";
 * (17) int x = 2000; char c = x; if (c == 2000) cout << "Erfolg!\n";
 * (18) vector<char> s = {'E', 'r', 'f', 'o', 'l', 'g', '!', '\n'}; for(int i = 0; i < 10; ++i) cout << s[i];
 * (19) vector v(5); for(int i = 0; i <= v.size(); ++i) ; cout << "Erfolg!\n";
 * (20) int i = 0; int j = 9; while(i < 10) ++j; if(j < i) cout << "Erfolg!\n";
 * (21) int x = 2; double d = 5 / (x - 2); if(d == 2 * x + 0.5) cout << "Erfolg!\n";
 * (22) int i = 0; while(i < 10) ++j; if(j < i) cout << "Erfolg!\n";
 * (23) int x = 4; double d = 5 / (x - 2); if (d = 2 * x + 0.25) cout << "Erfolg!\n";
 * (24) cin << "Erfolg!\n";
 */