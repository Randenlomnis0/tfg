#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
int dijkstra(int u, int v, int N, const vector<vector<pair<int, int>>> &AL) {
    vector<int> dist(N, 1e9);
    priority_queue<pair<int, int>> pq;
    pq.push(mp(0, u));
    while (!pq.empty()) {
        int t = -pq.top().first;
        u = pq.top().second;
        pq.pop();
        if (dist[u] != 1e9) continue;
        dist[u] = t;
        for (auto &it : AL[u]) {
            if (dist[it.first] <= dist[u] + it.second) continue;
            pq.push(mp(-(dist[u] + it.second), it.first));
        }
    }
    return dist[v];
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N, C;
    while (cin >> N >> C) {
        vector<vector<pair<int, int>>> AL(N);
        while (C--) {
            int u, v, t;
            cin >> u >> v >> t;
            --u;
            --v;
            AL[u].pb(mp(v, t));
            AL[v].pb(mp(u, t));
        }
        int K;
        cin >> K;
        while (K--) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            int ans = dijkstra(u, v, N, AL);
            if (ans == 1e9) {
                cout << "NO LLEGA\n";
            }else {
                cout << ans << '\n';
            }
        }
        cout << "---\n";
    }
    cout.flush();
    return 0;
}
