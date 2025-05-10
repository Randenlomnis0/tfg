#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define MAX(a,b) a = max(a, b)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &it : v) {
        cin >> it;
    }
    vector<int> LIS(n, 0), LDS(n, 0);
    int kis = 0, kds = 0, ans = 0;
    FOR(i, 0, n) {
        int pos = lower_bound(LIS.begin(), LIS.begin() + kis, v[i]) - LIS.begin();
        LIS[pos] = v[i];
        if (pos == kis) {
            kis = pos + 1;
        }
        pos = lower_bound(LDS.begin(), LDS.begin() + kds, -v[i]) - LDS.begin();
        LDS[pos] = -v[i];
        if (pos == kds) {
            kds = pos + 1;
        }
        MAX(ans, kis + kds - 1);
    }
    cout << ans << '\n';
    cout.flush();
    return 0;
}
