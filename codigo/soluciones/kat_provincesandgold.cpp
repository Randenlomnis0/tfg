#include <bits/stdc++.h>
using namespace std;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int G, S, C;
    cin >> G >> S >> C;
    int valor = 3 * G + 2 * S + C;
    if (valor < 2) {
        cout << "Copper\n";
    }else {
        if (valor >= 8) {
            cout << "Province or ";
        }else if (valor >= 5) {
            cout << "Duchy or ";
        }else {
            cout << "Estate or ";
        }
        
        if (valor >= 6) {
            cout << "Gold\n";
        }else if (valor >= 3) {
            cout << "Silver\n";
        }else {
            cout << "Copper\n";
        }
    }
    cout.flush();
    return 0;
}
