#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define SZ(c) ((int)(c).size())
#define mp make_pair
pair<int, int> dfs(int i, const vector<vector<int>> &AL, vector<bool> &visited) {
    visited[i] = true;
    pair<int, int> ans = mp(1, 0);
    for (auto &it : AL[i]) {
        ++ans.second;
        if (visited[it]) continue;
        pair<int, int> aux = dfs(it, AL, visited);
        ans.first += aux.first;
        ans.second += aux.second;
    }
    return ans;
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int nv, na;
    while (cin >> nv >> na) {
        vector<vector<int>> AL(nv);
        while (na--) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            AL[u].pb(v);
            AL[v].pb(u);
        }
        int solos = 0;
        FOR(i, 0, nv) {
            if (SZ(AL[i]) != 0) continue;
            ++solos;
        }
        int componentes = 0, arboles = 0;
        vector<bool> visited(nv);
        FOR(i, 0, nv) {
            if (visited[i]) continue;
            ++componentes;
            pair<int, int> aux = dfs(i, AL, visited);
            if (aux.first == aux.second / 2 + 1) {
                ++arboles;
            }
        }
        cout << solos << ' ' << arboles - solos << ' ' << componentes - arboles << '\n';
    }
    cout.flush();
    return 0;
}
