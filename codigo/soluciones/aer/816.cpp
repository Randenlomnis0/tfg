#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define ALL(c) (c).begin(), (c).end()
bool bfs(int s, int t, vector<unordered_map<int, int>> &AL, vector<int> &level, int n) {
    level.assign(n, -1);
    queue<int> q;
    level[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto &it : AL[u]) {
            if (it.second > 0 && level[it.first] == -1) {
                level[it.first] = level[u] + 1;
                q.push(it.first);
            }
        }
    }
    return level[t] != -1;
}
int dfs(int u, int t, int flow, vector<unordered_map<int, int>> &AL, const vector<int> &level, vector<int> &next) {
    if (u == t) return flow;
    auto it = AL[u].begin();
    advance(it, next[u]);
    for (; it != AL[u].end(); ++it, ++next[u]) {
        int v = it->first;
        if (it->second > 0 && level[v] == level[u] + 1) {
            int pushed = dfs(v, t, min(flow, it->second), AL, level, next);
            if (pushed > 0) {
                AL[u][v] -= pushed;
                AL[v][u] += pushed;
                return pushed;
            }
        }
    }
    return 0;
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int C, P;
    while (cin >> C >> P) {
        vector<int> problemas(C);
        for (auto &it : problemas) {
            cin >> it;
        }
        vector<vector<int>> categorias(P);
        for (auto &it : categorias) {
            int aux;
            while (cin >> aux, aux) {
                it.pb(aux - 1);
            }
        }
        vector<unordered_map<int, int>> AL(C + P + 2);
        int s = C + P, t = C + P + 1;
        FOR(i, 0, C) {
            AL[s][i] = problemas[i];
            AL[i][s] = 0;
        }
        FOR(i, 0, P) {
            AL[C + i][t] = 1;
            AL[t][C + i] = 0;
            for (auto &it : categorias[i]) {
                AL[it][C + i] = 1;
                AL[C + i][it] = 0;
            }
        }
        int ans = 0;
        vector<int> level(C + P + 2), next(C + P + 2);
        while (bfs(s, t, AL, level, C + P + 2)) {
            fill(ALL(next), 0);
            int flow;
            while (flow = dfs(s, t, INT_MAX, AL, level, next)) {
                ans += flow;
            }
        }
        cout << ans << '\n';
    }
    cout.flush();
    return 0;
}
