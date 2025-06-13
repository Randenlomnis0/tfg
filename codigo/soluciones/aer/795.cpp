#include <bits/stdc++.h>
using namespace std;
#define GL(s) getline(cin, s)
#define FOR(i,j,k) for (int i = j; i < k; ++i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int c, f;
    while (cin >> c >> f, c || f) {
        c += 2;
        f += 2;
        vector<string> grid(f);
        GL(grid[0]);
        for (auto &it : grid) {
            GL(it);
        }
        FOR(i, 0, f) {
            cout << '-';
        }
        cout << '\n';
        FOR(j, 1, c - 1) {
            cout << '|';
            FOR(i, 1, f - 1) {
                cout << grid[i][c - j - 1];
            }
            cout << '|' << '\n';
        }
        FOR(i, 0, f) {
            cout << '-';
        }
        cout << '\n';
    }
    cout.flush();
    return 0;
}
