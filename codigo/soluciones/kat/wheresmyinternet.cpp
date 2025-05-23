#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define FOR(i,j,k) for (int i = j; i < k; ++i)
int dfs(const int& i, const vector<vector<int>>& AL, vector<bool>& visited) {
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
    int N, M;
    cin >> N >> M;
    vector<vector<int>> AL(N);
    while (M--) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        AL[a].pb(b);
        AL[b].pb(a);
    }
    vector<bool> visited(N);
    int ans = dfs(0, AL, visited);
    if (ans == N) {
        cout << "Connected\n";
    }else {
        FOR(i, 0, N) {
            if (visited[i]) continue;
            cout << i + 1 << '\n';
        }
    }
    cout.flush();
    return 0;
}
