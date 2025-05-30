#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
bool dfs(const int& i, const vector<pair<int, int>>& guards, vector<bool>& visited, const int& N, const int& W) {
    visited[i] = true;
    if (guards[i].first >= W - 10) return true;
    FOR(j, 0, N) {
        if (visited[j] || j == i) continue;
        int dx = guards[i].first - guards[j].first, dy = guards[i].second - guards[j].second;
        if (dx * dx + dy * dy > 20 * 20) continue;
        if (dfs(j, guards, visited, N, W)) {
            return true;
        }
    }
    return false;
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int W;
    while (cin >> W, W) {
        int H, N;
        cin >> H >> N;
        vector<pair<int, int>> guards(N);
        vector<bool> visited(N);
        FOR(i, 0, N) {
            cin >> guards[i].first >> guards[i].second;
        }
        bool ans = true;
        FOR(i, 0, N) {
            if (guards[i].first > 10) continue;
            if (dfs(i, guards, visited, N, W)) {
                ans = false;
                break;
            }
        }
        cout << (ans ? "SI" : "NO") << '\n';
    }
    cout.flush();
    return 0;
}
