#include <bits/stdc++.h>
using namespace std;

signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int A, B;
    cin >> A >> B;
    string palabra = "aaaaaaaaaaaa";
    cout << palabra;
    while (--B) {
        int i = 0;
        while (palabra[i] == 'z') {
            palabra[i] = 'a';
            ++i;
        }
        palabra[i] = palabra[i] + 1;
        cout << ' ' << palabra;
    }
    cout << '\n';
    cout.flush();
    return 0;
}
