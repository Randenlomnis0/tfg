#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> V(5);
    for (auto &it : V) {
        cin >> it;
    }
    int i = 3;
    while (true) {
        bool cambios = false;
        i = (i + 1)%4;
        if (V[i] > V[i + 1]) {
            swap(V[i], V[i + 1]);
            cambios = true;
        }
        if (!cambios) continue;
        bool first = true;
        for (auto &it : V) {
            if (!first) cout << ' ';
            else first = false;
            cout << it;
        }
        cout << '\n';
        if (V[0] == 1 && V[1] == 2 && V[2] == 3 && V[3] == 4 && V[4] == 5) break;
    }
    cout.flush();
    return 0;
}
