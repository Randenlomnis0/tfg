#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a, b)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q, s;
    bool first = true;
    while (cin >> n >> m >> q >> s, n || m || q || s) {
        vector<vector<pair<int, int>>> AL(n);
        while (m--) {
            int u, v, w;
            cin >> u >> v >> w;
            AL[u].pb(mp(v, w));
        }
        priority_queue<pair<int, int>> pq;
        pq.push(mp(0, s));
        vector<int> dist(n, -1);
        while (!pq.empty()) {
            int u = pq.top().second;
            int c = -pq.top().first;
            pq.pop();
            if (dist[u] != -1) continue;
            dist[u] = c;
            for (auto &it : AL[u]) {
                int v = it.first;
                int w = it.second;
                if (dist[v] != -1) continue;
                pq.push(mp(-(dist[u] + w), v));
            }
        }
        if (!first) cout << '\n';
        else first = false;
        while (q--) {
            int v;
            cin >> v;
            if (dist[v] != -1) {
                cout << dist[v] << '\n';
            }else {
                cout << "Impossible\n";
            }
        }
    }
    cout.flush();
    return 0;
}
