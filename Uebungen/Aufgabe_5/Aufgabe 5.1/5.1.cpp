//
// Created by Fritz Bökler
//

#include "std_lib_inc.h"

int main()
{
    try {
        // << Kopieren Sie den Code hier hin >>
        int i = 0; int j = 9; while(i < 10) ++i; if(j < i) cout << "Erfolg!\n";
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
cout << "Erfolg!\n"; Kompilierfehler Syntax
cout << "Erfolg!\n"; Kompilierfehler Syntax
cout << "Erfolg" << !"\n"; Kompilierfehler Syntax
cout << "Erfolg!" << '\n'; Kompilierfehler Syntax
int res = 7; vector<int> v(10); v[5] = res; cout << "Erfolg!\n"; Kompilierfehler Typ
vector<int> v(10); v[5] = 7; if (v[5] != 7) cout << "Erfolg!\n"; Kompilierfehler Typ
if(bed) cout << "Erfolg!\n"; else cout << "Misserfolg!\n";  Linkzeitfehler
bool c = false; if(c) cout << "Erfolg!\n"; else cout << "Misserfolg!\n"; Logikfehler
string s = "affe"; boo c = "elephant" < s; if(c) cout << "Erfolg!\n"; Typfehler
string s = "affe"; if(s == "elephant") cout << "Erfolg!\n"; Logikfehler
string s = "affe"; if(s == "elephant") cout < "Erfolg!\n"; Logik und Typ fehler
string s = "affe"; if(s + "elephant") cout < "Erfolg!\n"; Kompilier und logikfehler
vector<char> v(5); for(int i = 0; 0 < v.size(); ++i) ; cout << "Erfolg!\n"; Logikfehler
vector<char> v(5); for(int i = 0; i <= v.size(); ++i) ; cout << "Erfolg!\n"; logikfehler
vector<char> s = {'E', 'r', 'f', 'o', 'l', 'g', '!', '\n'}; for(int i = 0; i < 6; ++i) cout << s[i]; logikfehler
if(true) then cout << "Erfolg!\n"; else cout << "Misserfolg!\n"; Kompilierfehler
int x = 2000; char c = x; if (c == 2000) cout << "Erfolg!\n"; Logikfehler
vector<char> s = {'E', 'r', 'f', 'o', 'l', 'g', '!', '\n'}; for(int i = 0; i < 10; ++i) cout << s[i]; Laufzeitfehler
vector v(5); for(int i = 0; i <= v.size(); ++i) ; cout << "Erfolg!\n"; Linkzeit fehler
int i = 0; int j = 9; while(i < 10) ++j; if(j < i) cout << "Erfolg!\n"; Logikfehler
int x = 2; double d = 5 / (x - 2); if(d == 2 * x + 0.5) cout << "Erfolg!\n";
int i = 0; while(i < 10) ++j; if(j < i) cout << "Erfolg!\n";
int x = 4; double d = 5 / (x - 2); if (d = 2 * x + 0.25) cout << "Erfolg!\n";
cin << "Erfolg!\n";
*/