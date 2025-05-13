#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n, n) {
        vector<vector<int>> AL(n);
        vector<int> M(n);
        FOR(i, 0, n) {
            int v, m, d;
            cin >> v >> m >> d;
            --v;
            AL[v] = vector<int>(d);
            for (auto &it : AL[v]) {
                cin >> it;
                --it;
            }
            M[v] = m;
        }
    }
    cout.flush();
    return 0;
}
