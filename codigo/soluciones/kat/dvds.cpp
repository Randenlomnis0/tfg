#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin >> k;
    while (k--) {
        int n;
        cin >> n;
        int goal = 1;
        FOR(i, 0, n) {
            int id;
            cin >> id;
            if (id == goal) {
                ++goal;
            }
        }
        cout << n - goal + 1 << '\n';
    }
    cout.flush();
    return 0;
}
