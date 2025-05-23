#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define MIN(a,b) a = min(a, b)
const int INF = 1000000000;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q;
    bool first = true;
    while (cin >> n >> m >> q, n || m || q) {
        vector<vector<int>> AM(n, vector<int>(n, INF));
        FOR(k, 0, n) {
            AM[k][k] = 0;
        }
        while (m--) {
            int u, v, w;
            cin >> u >> v >> w;
            MIN(AM[u][v], w);
        }
        FOR(k, 0, n) {
            FOR(i, 0, n) {
                FOR(j, 0, n) {
                    MIN(AM[i][j], AM[i][k] + AM[k][j]);
                }
            }
        }
        if (!first) cout << '\n';
        else first = false;
        while (q--) {
            int u, v;
            cin >> u >> v;
            if (AM[u][v] == INF) {
                cout << "Impossible\n";
            }else if (AM[u][v] + AM[v][u] < 0) {
                cout << "-Infinity\n";
            }else {
                cout << AM[u][v] << '\n';
            }
        }
    }
    cout.flush();
    return 0;
}
