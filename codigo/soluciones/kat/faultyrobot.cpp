#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define SZ(c) ((int)(c).size())
void dfs(const int& i, const vector<vector<int>>& AL, const vector<vector<int>>& AL_T, vector<vector<bool>>& visited, const bool& bug, vector<bool>& endpoint) {
    visited[i][bug] = true;
    int posibles_movimientos = 0;
    if (!bug) {
        for (auto &it : AL[i]) {
            if (visited[it][true]) continue;
            dfs(it, AL, AL_T, visited, true, endpoint);
        }
    }
    for (auto &it : AL_T[i]) {
        ++posibles_movimientos;
        if (visited[it][bug]) continue;
        dfs(it, AL, AL_T, visited, bug, endpoint);
    }
    if (posibles_movimientos == 0) {
        endpoint[i] = true;
    }
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> AL(n), AL_T(n);
    while (m--) {
        int a, b;
        cin >> a >> b;
        --b;
        if (a > 0) {
            --a;
            AL[a].pb(b);
        }else {
            ++a;
            AL_T[-a].pb(b);
        }
    }
    vector<vector<bool>> visited(n, vector<bool>(2));
    vector<bool> endpoint(n);
    dfs(0, AL, AL_T, visited, false, endpoint);
    int ans = 0;
    for (auto it : endpoint) {
        ans += it;
    }
    cout << ans << '\n';
    cout.flush();
    return 0;
}
