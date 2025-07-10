#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int c1 = 0;
        for (auto &it : s) {
            if (it == '0') continue;
            ++c1;
        }
        if (k >= c1) {
            cout << "Alice\n";
            continue;
        }
        cout << (2 * k > n ? "Alice" : "Bob") << '\n';
    }
    cout.flush();
    return 0;
}
