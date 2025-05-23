#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
void dfs(const int& i, const int& j, const vector<string>& m, vector<vector<int>>& ids, const int& r, const int& c, const int& id) {
    ids[i][j] = id;
    for (int d = -1; d <= 1; d += 2) {
        if (i + d < 0 || i + d >= r || m[i + d][j] != m[i][j] || ids[i + d][j] != 0) continue;
        dfs(i + d, j, m, ids, r, c, id);
    }
    for (int d = -1; d <= 1; d += 2) {
        if (j + d < 0 || j + d >= c || m[i][j + d] != m[i][j] || ids[i][j + d] != 0) continue;
        dfs(i, j + d, m, ids, r, c, id);
    }
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int r, c;
    cin >> r >> c;
    vector<string> m(r);
    for (auto &it : m) {
        cin >> it;
    }
    vector<vector<int>> ids(r, vector<int>(c));
    int id = 0;
    FOR(i, 0, r) {
        FOR(j, 0, c) {
            if (ids[i][j] != 0) continue;
            dfs(i, j, m, ids, r, c, ++id);
        }
    }
    int n;
    cin >> n;
    while (n--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        --r1;
        --c1;
        --r2;
        --c2;
        if (ids[r1][c1] == ids[r2][c2]) {
            cout << (m[r1][c1] == '0' ? "binary" : "decimal") << '\n';
        }else {
            cout << "neither\n";
        }
    }
    cout.flush();
    return 0;
}
