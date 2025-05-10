#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define mp(a,b) make_pair(a, b)
#define SZ(c) ((int)(c).size())
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (auto &it : grid) {
        cin >> it;
    }
    vector<vector<int>> ans(n, vector<int>(m, -1));
    queue<pair<int, int>> qu;
    FOR(i, 0, n) {
        qu.push(mp(i, -1));
        qu.push(mp(i, m));
    }
    FOR(j, 0, m) {
        qu.push(mp(-1, j));
        qu.push(mp(n, j));
    }
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            if (grid[i][j] != '.') continue;
            qu.push(mp(i, j));
            ans[i][j] = 0;
        }
    }
    qu.push(mp(-1, -1));
    int aux = 1;
    while (SZ(qu) != 1) {
        int i = qu.front().first;
        int j = qu.front().second;
        qu.pop();
        if (i == -1 && j == -1) {
            qu.push(mp(-1, -1));
            ++aux;
            continue;
        }
        for (int p = -1; p <= 1; p += 2) {
            if (i + p < 0 || i + p >= n || j < 0 || j >= m || ans[i + p][j] != -1) continue;
            qu.push(mp(i + p, j));
            ans[i + p][j] = aux;
        }
        for (int q = -1; q <= 1; q += 2) {
            if (i < 0 || i >= n || j + q < 0 || j + q >= m || ans[i][j + q] != -1) continue;
            qu.push(mp(i, j + q));
            ans[i][j + q] = aux;
        }
    }
    int padding = 2 + (aux >= 10);
    for (auto &it : ans) {
        for (auto &iit : it) {
            cout << '.';
            if (padding == 3 && iit < 10) {
                cout << '.';
            }
            if (iit) {
                cout << iit;
            }else {
                cout << '.';
            }
        }
        cout << '\n';
    }
    cout.flush();
    return 0;
}
