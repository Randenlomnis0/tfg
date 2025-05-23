#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a, b)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int V, E;
    cin >> V >> E;
    vector<vector<pair<int, int>>> AL(V);
    while (E--) {
        int u, v, w;
        cin >> u >> v >> w;
        AL[u].pb(mp(v, w));
    }
    int s, t;
    cin >> s >> t;
    priority_queue<pair<int, int>> pq;
    pq.push(mp(0, s));
    vector<int> dist(V, INT_MAX), cnt(V);
    dist[s] = 0;
    cnt[s] = 1;
    while (!pq.empty()) {
        int u = pq.top().second;
        int c = -pq.top().first;
        pq.pop();
        for (auto &it : AL[u]) {
            if (dist[it.first] > dist[u] + it.second) {
                dist[it.first] = dist[u] + it.second;
                cnt[it.first] = cnt[u];
                pq.push(mp(-dist[it.first], it.first));
            }else if (dist[it.first] == dist[u] + it.second) {
                cnt[it.first] += cnt[u];
            }
        }
    }
    cout << cnt[t] << '\n';
    cout.flush();
    return 0;
}
