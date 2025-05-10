#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int r, n;
    cin >> r >> n;
    vector<bool> booked(r);
    while (n--) {
        int aux;
        cin >> aux;
        --aux;
        booked[aux] = true;
    }
    bool ans = false;
    FOR(i, 0, r) {
        if (booked[i]) continue;
        cout << i + 1 << '\n';
        ans = true;
        break;
    }
    if (!ans) {
        cout << "too late\n";
    }
    cout.flush();
    return 0;
}
