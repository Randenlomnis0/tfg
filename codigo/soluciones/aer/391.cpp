#include <bits/stdc++.h>
using namespace std;
#define MIN(a,b) a = min(a, b)
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define mp(a, b) make_pair(a, b)
#define ALL(x) (x).begin(), (x).end()
vector<int> dijkstra(const vector<unordered_map<int, int>> &AL, int start, const int &np) {
    vector<int> dist(np, INT_MAX);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(mp(0, start));
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto &it : AL[u]) {
            int v = it.first;
            int w = it.second;
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push(mp(dist[v], v));
            }
        }
    }
    return dist;
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int np, nc;
    while (cin >> np >> nc) {
        vector<unordered_map<int, int>> AL(np);
        while (nc--) {
            int u, v, w;
            cin >> u >> v >> w;
            --u;
            --v;
            if (!AL[u].count(v)) {
                AL[u][v] = INT_MAX;
            }
            MIN(AL[u][v], w);
            if (!AL[v].count(u)) {
                AL[v][u] = INT_MAX;
            }
            MIN(AL[v][u], w);
        }
        int c;
        cin >> c;
        vector<bool> esColegio(np);
        while (c--) {
            int n;
            cin >> n;
            vector<int> colegios(n);
            for (auto &it : colegios) {
                cin >> it;
                --it;
                esColegio[it] = true;
            }
            vector<vector<int>> dists(n, vector<int>(np, INT_MAX));
            FOR(i, 0, n) {
                dists[i] = dijkstra(AL, colegios[i], np);
            }
            vector<int> perm(n);
            iota(ALL(perm), 0);
            int ans = INT_MAX, ansi = -1;
            do {
                int aux = 0;
                bool valid = true;
                FOR(i, 1, n) {
                    if (dists[perm[i - 1]][colegios[perm[i]]] == INT_MAX) {
                        valid = false;
                        break;
                    }
                    aux += dists[perm[i - 1]][colegios[perm[i]]];
                }
                if (!valid) continue;
                FOR(i, 0, np) {
                    if (esColegio[i] || dists[perm[0]][i] == INT_MAX || dists[perm[n - 1]][i] == INT_MAX) continue;
                    if (aux + dists[perm[0]][i] + dists[perm[n - 1]][i] < ans) {
                        ans = aux + dists[perm[0]][i] + dists[perm[n - 1]][i];
                        ansi = i;
                    }else if (aux + dists[perm[0]][i] + dists[perm[n - 1]][i] == ans) {
                        MIN(ansi, i);
                    }
                }
                
            } while (next_permutation(ALL(perm)));
            for (auto &it : colegios) {
                esColegio[it] = false;
            }
            cout << ansi + 1 << ' ' << ans << '\n';
        }
        cout << "---\n";
    }
    cout.flush();
    return 0;
}
