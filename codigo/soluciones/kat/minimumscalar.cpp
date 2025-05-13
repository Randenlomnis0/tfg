#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define ALL(c) (c).begin(), (c).end()
#define int long long
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    FOR(k, 0, T) {
        int n;
        cin >> n;
        vector<int> x(n), y(n);
        for (auto &it : x) {
            cin >> it;
        }
        sort(ALL(x));
        for (auto &it : y) {
            cin >> it;
        }
        sort(ALL(y));
        int ans = 0;
        FOR(i, 0, n) {
            ans += x[i] * y[n - i - 1];
        }
        cout << "Case #" << k + 1 << ": " << ans << '\n';
    }
    cout.flush();
    return 0;
}
