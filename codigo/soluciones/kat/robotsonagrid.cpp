#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define int long long
const int MOD = INT_MAX;
bool dfs(const int& i, const int& j, vector<string>& grid, const int& n) {
    if (i == n - 1 && j == n - 1) return true;
    if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == '#') return false;
    grid[i][j] = '#';
    for (int d = -1; d <= 1; d += 2) {
        if (dfs(i + d, j, grid, n)) return true;
        if (dfs(i, j + d, grid, n)) return true;
    }
    return false;
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<string> grid(n);
    for (auto &it : grid) {
        cin >> it;
    }
    vector<vector<int>> ans(n, vector<int>(n));
    ans[0][0] = 1;
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            if (grid[i][j] == '#') continue;
            if (i > 0) {
                ans[i][j] += ans[i - 1][j];
                ans[i][j] %= MOD;
            }
            if (j > 0) {
                ans[i][j] += ans[i][j - 1];
                ans[i][j] %= MOD;
            }
        }
    }
    if (ans[n - 1][n - 1] != 0) {
        cout << ans[n - 1][n - 1] << '\n';
    }else {
        cout << (dfs(0, 0, grid, n) ? "THE GAME IS A LIE" : "INCONCEIVABLE") << '\n';
    }
    cout.flush();
    return 0;
}
