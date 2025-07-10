#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define pb push_back
#define MIN(a,b) a = min(a, b)
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
    int N;
    while (cin >> N && N) {
        vector<string> grid(N);
        for (auto &it : grid) {
            cin >> it;
        }
        vector<vector<int>> row(N, vector<int>(N, -1)), col(N, vector<int>(N, -1));
        int id = 0;
        FOR(i, 0, N) {
            FOR(j, 0, N) {
                if (grid[i][j] == 'X') {
                    ++id;
                    continue;
                }
                row[i][j] = id;
            }
            ++id;
        }
        FOR(j, 0, N) {
            FOR(i, 0, N) {
                if (grid[i][j] == 'X') {
                    ++id;
                    continue;
                }
                col[i][j] = id;
            }
            ++id;
        }
        vector<unordered_map<int, int>> AL(id + 2);
        int s = id, t = id + 1;
        FOR(i, 0, N) {
            FOR(j, 0, N) {
                if (grid[i][j] == 'X') continue;
                AL[s][row[i][j]] = 1;
                AL[row[i][j]][s] = 0;
                AL[row[i][j]][col[i][j]] = 1;
                AL[col[i][j]][row[i][j]] = 0;
                AL[col[i][j]][t] = 1;
                AL[t][col[i][j]] = 0;
            }
        }
        int ans = 0;
        vector<int> level(id + 2), next(id + 2);
        while (bfs(s, t, AL, level, id + 2)) {
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
