#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a, b)
#define FOR(i,j,k) for (int i = j; i < k; ++i)
int dfs(const int& i, const vector<unordered_set<int>>& AL, vector<bool>& visited) {
    visited[i] = true;
    int ans = 1;
    for (auto &it : AL[i]) {
        if (visited[it]) continue;
        ans += dfs(it, AL, visited);
    }
    return ans;
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int p, c;
    while (cin >> p >> c, p || c) {
        vector<unordered_set<int>> AL(p);
        vector<pair<int, int>> EL(c);
        for (auto &it : EL) {
            int a, b;
            cin >> a >> b;
            AL[a].insert(b);
            AL[b].insert(a);
            it = mp(a, b);
        }
        bool ans = true;
        for (auto &it : EL) {
            AL[it.first].erase(it.second);
            AL[it.second].erase(it.first);
            vector<bool> visited(p);
            if (dfs(0, AL, visited) != p) {
                ans = false;
                break;
            }
            AL[it.first].insert(it.second);
            AL[it.second].insert(it.first);
        }
        cout << (ans ? "No" : "Yes") << '\n';
    }
    cout.flush();
    return 0;
}
