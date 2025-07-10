#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define ALL(c) (c).begin(), (c).end()
#define pb push_back
#define RFOR(i,j,k) for (int i = j - 1; i >= k; --i)
#define SZ(c) ((int)(c).size())
#define MAX(a,b) a = max(a, b)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n, n) {
        vector<int> v(n);
        for (auto &it : v) {
            cin >> it;
        }
        vector<int> LIS, LDS;
        RFOR(i, n, 0) {
            auto it1 = lower_bound(ALL(LIS), v[i]);
            if (it1 == LIS.end()) {
                LIS.pb(v[i]);
            }else {
                *it1 = v[i];
            }
            auto it2 = lower_bound(ALL(LDS), v[i], greater<int>());
            if (it2 == LDS.end()) {
                LDS.pb(v[i]);
            }else {
                *it2 = v[i];
            }
        }
        int ans = 0;
        FOR(i, 0, SZ(LDS)) {
            int pos = lower_bound(ALL(LIS), LDS[i]) - LIS.begin();
            MAX(ans, i + 1 + pos);
        }
        cout << ans << '\n';
    }
    cout.flush();
    return 0;
}