#include <bits/stdc++.h>
using namespace std;
#define SZ(c) ((int)(c).size())
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define pb(x) push_back(x)
bool constant(const vector<int> &v) {
    if (SZ(v) == 1) return true;
    FOR(i, 1, SZ(v)) {
        if (v[i] - v[i - 1] != 0) {
            return false;
        }
    }
    return true;
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> v(1, vector<int>(n));
    for (auto &it : v[0]) {
        cin >> it;
    }
    int i = 0;
    while (!constant(v[i])) {
        v.pb(vector<int>(SZ(v[i]) - 1));
        ++i;
        FOR(j, 1, SZ(v[i - 1])) {
            v[i][j - 1] = v[i - 1][j] - v[i - 1][j - 1];
        }
    }
    cout << i << ' ';
    while (i > 0) {
        v[i - 1].pb(v[i - 1][SZ(v[i - 1]) - 1] + v[i][SZ(v[i]) - 1]);
        --i;
    }
    cout << v[0][SZ(v[0]) - 1] << '\n';
    cout.flush();
    return 0;
}
