#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define pb push_back
#define mp make_pair
#define SZ(c) ((int)(c).size())
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int mx = INT_MIN;
        vector<pair<int, int>> idxs;
        vector<vector<int>> matrix(n, vector<int>(m));
        FOR(i, 0, n) {
            FOR(j, 0, m) {
                cin >> matrix[i][j];
                if (matrix[i][j] > mx) {
                    idxs.clear();
                    mx = matrix[i][j];
                }
                if (matrix[i][j] == mx) {
                    idxs.pb({i, j});
                }
            }
        }
        vector<int> rows(n), cols(m);
        for (auto &it : idxs) {
            ++rows[it.first];
            ++cols[it.second];
        }
        bool ans = false;
        FOR(i, 0, n) {
            FOR(j, 0, m) {
                if (rows[i] + cols[j] - (matrix[i][j] == mx) == SZ(idxs)) {
                    ans = true;
                    break;
                }
            }
            if (ans) break;
        }
        cout << (ans ? mx - 1 : mx) << '\n';
    }
    cout.flush();
    return 0;
}
