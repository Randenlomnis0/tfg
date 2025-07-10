#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define RFOR(i,j,k) for (int i = j - 1; i >= k; --i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), mn(n), mx(n);
        for (auto &it : a) {
            cin >> it;
        }
        mn[0] = a[0];
        FOR(i, 1, n) {
            mn[i] = min(mn[i - 1], a[i]);
        }
        mx[n - 1] = a[n - 1];
        RFOR(i, n - 1, 0) {
            mx[i] = max(mx[i + 1], a[i]);
        }
        string ans = string(n, '0');
        FOR(i, 0, n) {
            if (mn[i] < a[i] && mx[i] > a[i]) continue;
            ans[i] = '1';
        }
        cout << ans << '\n';
    }
    cout.flush();
    return 0;
}
