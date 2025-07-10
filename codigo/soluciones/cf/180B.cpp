#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &it : a) {
            cin >> it;
        }
        bool ans = false, creciente = true, decreciente = true;
        FOR(i, 1, n) {
            if (abs(a[i] - a[i - 1]) <= 1) {
                ans = true;
            }
            if (a[i] < a[i - 1]) {
                creciente = false;
            }
            if (a[i] > a[i - 1]) {
                decreciente = false;
            }
        }
        if (ans) {
            cout << "0\n";
            continue;
        }
        if (creciente || decreciente) {
            cout << "-1\n";
            continue;
        }
        cout << "1\n";
    }
    cout.flush();
    return 0;
}
