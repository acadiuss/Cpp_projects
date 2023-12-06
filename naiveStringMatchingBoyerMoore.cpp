#include <iostream>
#include <string>

using namespace std;

Znajdywanie wzorca w tekscie




Zadanie 1:
Dla tekstu T i wzorca p proszę zaimplementować algorytm naiwny wyszukiwania wzorca w tekście. Algorytm należy zaimplementować w postaci funkcji: void naiveStringMatching(string T, string p) wświetlajacej pozycje w tekście, od których występuje wzorzec. Proszę przetestować poprawność działania algorytmu. Testy powinny być zaprezentowane w sposób czytelny i jednoznaczny.


Szablon rozwiązania:


//Zadanie 1
void naiveStringMatching(string T, string p){

}

main():
//Zadanie 1 - testy

string text="/*dowolny tekst*/";   
string pattern="/*wzorzec*/";       

//wywołanie naiveStringMatching() i wyświetlenie wyników (wszystkich pozycji, od których został znaleziony wzorzec)

Przykładowy tekst i wzorzec:

string text="gfrgfgigjmgfrrogirgfrgfrgfrgirhgrygfrgfygirmggfrgfgfrgffeutyitbhfuvwgfrgf";   
string pattern="gfrgf";

dopasowanie od: 0 18 21 34 45 50 68




void naiveStringMatching(const string& T, const string& p) {
    int n = T.size();
    int m = p.size();

    // Przechodzenie 
    for (int i = 0; i <= n - m; i++) {
        int j;

        // Porównywanie 
        for (j = 0; j < m; j++) {
            if (T[i + j] != p[j]) 
                break;
        }

        // Znaleziono
        if (j == m) {
            cout << "Znaleziono wzorzec na pozycji " << i << endl;
        }
    }
}

int main() {
    string text = "gfrgfgigjmgfrrogirgfrgfrgfrgirhgrygfrgfygirmggfrgfgfrgffeutyitbhfuvwgfrgf";   
    string pattern = "gfrgf";     

    // Wywołanie naiveStringMatching() i wyświetlenie wyników
    naiveStringMatching(text, pattern);

    return 0;
}




#include <iostream>
#include <string>
#include <vector>
using namespace std;

void BM(const string& T, const string& p) {
    int n = T.size();
    int m = p.size();

    // Inicjalizacja tablicy bad character
    int bc[127];
    for (int i = 0; i < 127; i++) {
        bc[i] = -1;
    }

    // Wypełnianie tablicy bad character
    for (int i = 0; i < m; i++) {
        bc[(int)p[i]] = i;
    }

    int s = 0;  // Pozycja przesunięcia wzorca względem tekstu

    while (s <= (n - m)) {
        int j = m - 1;

        // Znajdowanie pozycji ostatniego niepasującego znaku w wzorcu
        while (j >= 0 && p[j] == T[s + j]) {
            j--;
        }

        // Jeśli wzorzec pasuje w bieżącej pozycji
        if (j < 0) {
            cout << "Znaleziono wzorzec na pozycji " << s << endl;
            s += (s + m < n) ? m - bc[T[s + m]] : 1;
        } else {
            s += max(1, j - bc[T[s + j]]);
        }
    }
}


const int alfabetRozmiar =256;


void naiveStringMatching(const string& T, const string& p) {
    int n = T.size();
    int m = p.size();
    
// Przechodzenie 
for (int i = 0; i <= n - m; i++) 
{
    int j;

// Porównywanie 
for (j = 0; j < m; j++) 
{
    if (T[i + j] != p[j]) 
    break;
}

        // Znaleziono
if (j == m)
{
    cout << "Znaleziono wzorzec na pozycji " << i << endl;
}
}
}


void BoyerMoore(const string& T, const string& p) {
    int n = T.size();
    int m = p.size();
    vector<int> badChar(alfabetRozmiar, -1);

    // Tworzenie tabeli bad character
    for (int i = 0; i < m; ++i) {
        badChar[(int)p[i]] = i;
    }

    int s = 0;  // Pozycja przesunięcia wzorca względem tekstu

    while (s <= (n - m)) {
        int j = m - 1;

        // Znajdowanie pozycji ostatniego niepasującego znaku w wzorcu
        while (j >= 0 && p[j] == T[s + j]) {
            j--;
        }

        // Jeśli wzorzec pasuje w bieżącej pozycji
        if (j < 0) {
            cout << "Znaleziono wzorzec na pozycji " << s << endl;
            s += (s + m < n) ? m - badChar[T[s + m]] : 1;
        } else {
            s += max(1, j - badChar[T[s + j]]);
        }
    }
}


///wykadowca
int bc[127];

for (int i = 0; i<127 ;i++)
bc[i]=-1;
for(int i =0; i<m; i++)
bc[(int)p[i]]=i;


int main() {
    string text = "gfrgfgigjmgfrrogirgfrgfrgfrgirhgrygfrgfygirmggfrgfgfrgffeutyitbhfuvwgfrgf";   
    string pattern = "gfrgf";     

    // Wywołanie naiveStringMatching() i wyświetlenie wyników
    naiveStringMatching(text, pattern);
    BoyerMoore(text, pattern);
    
    BM(text, pattern);
    
    return 0;
}
