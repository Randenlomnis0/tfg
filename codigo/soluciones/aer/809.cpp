#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define MIN(a,b) a = min(a, b)
#define MAX(a,b) a = max(a, b)
#define mp make_pair
pair<int, int> solve(const vector<int> &a, int lb, int hb, vector<vector<pair<int, int>>> &memo) {
    if (lb == hb) return mp(0, 0);
    if (memo[lb][hb] != mp(-1, -1)) return memo[lb][hb];
    int mn = INT_MAX, mx = INT_MIN;
    FOR(nb, lb, hb) {
        auto l = solve(a, lb, nb, memo), r = solve(a, nb + 1, hb, memo);
        MIN(mn, l.first + r.first + a[lb] * a[nb + 1] * a[hb + 1]);
        MAX(mx, l.second + r.second + a[lb] * a[nb + 1] * a[hb + 1]);
    }
    return memo[lb][hb] = mp(mn, mx);
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n) {
        vector<int> a(n + 1);
        for (auto &it : a) {
            cin >> it;
        }
        vector<vector<pair<int, int>>> memo(n, vector<pair<int, int>>(n, mp(-1, -1)));
        auto ans = solve(a, 0, n - 1, memo);
        cout << ans.first << ' ' << ans.second << '\n';
    }
    cout.flush();
    return 0;
}
