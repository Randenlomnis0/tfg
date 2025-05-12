#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (n--) {
        int g;
        cin >> g;
        int prev;
        cin >> prev;
        bool found = false;
        FOR(i, 2, g + 1) {
            int aux;
            cin >> aux;
            if (aux != prev + 1 && !found) {
                cout << i << '\n';
                found = true;
            }
            prev = aux;
        }
    }
    cout.flush();
    return 0;
}
