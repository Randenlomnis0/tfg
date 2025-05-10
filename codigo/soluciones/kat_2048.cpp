#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define RFOR(i,j,k) for (int i = j - 1; i >= k; --i)
#define pb(x) push_back(x)
#define SZ(c) ((int)(c).size())
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> grid(4, vector<int>(4));
    for (auto &it : grid) {
        for (auto &iit : it) {
            cin >> iit;
        }
    }
    int mov;
    cin >> mov;
    vector<vector<int>> ans(4, vector<int>(4));
    if (mov == 0 || mov == 2) {
        FOR(i, 0, 4) {
            vector<int> rowNoZeros;
            if (mov == 0) {
                FOR(j, 0, 4) {
                    if (grid[i][j]) rowNoZeros.pb(grid[i][j]);
                }
            }else {
                RFOR(j, 4, 0) {
                    if (grid[i][j]) rowNoZeros.pb(grid[i][j]);
                }
            }
            vector<int> row;
            FOR(j, 0, SZ(rowNoZeros)) {
                if (j < SZ(rowNoZeros) - 1 && rowNoZeros[j] == rowNoZeros[j + 1]) {
                    row.pb(2 * rowNoZeros[j++]);
                }else {
                    row.pb(rowNoZeros[j]);
                }
            }
            if (mov == 0) {
                FOR(j, 0, SZ(row)) {
                    ans[i][j] = row[j];
                }
            }else {
                FOR(j, 0, SZ(row)) {
                    ans[i][3 - j] = row[j];
                }
            }
        }
    }else {
        FOR(j, 0, 4) {
            vector<int> colNoZeros;
            if (mov == 1) {
                FOR(i, 0, 4) {
                    if (grid[i][j]) colNoZeros.pb(grid[i][j]);
                }
            }else {
                RFOR(i, 4, 0) {
                    if (grid[i][j]) colNoZeros.pb(grid[i][j]);
                }
            }
            vector<int> col;
            FOR(i, 0, SZ(colNoZeros)) {
                if (i < SZ(colNoZeros) - 1 && colNoZeros[i] == colNoZeros[i + 1]) {
                    col.pb(2 * colNoZeros[i++]);
                }else {
                    col.pb(colNoZeros[i]);
                }
            }
            if (mov == 1) {
                FOR(i, 0, SZ(col)) {
                    ans[i][j] = col[i];
                }
            }else {
                FOR(i, 0, SZ(col)) {
                    ans[3 - i][j] = col[i];
                }
            }
        }
    }
    for (auto &it : ans) {
        bool first = true;
        for (auto &iit : it) {
            if (!first) cout << ' ';
            else first = false;
            cout << iit;
        }
        cout << '\n';
    }
    cout.flush();
    return 0;
}
