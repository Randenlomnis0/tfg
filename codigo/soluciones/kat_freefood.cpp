#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> cdf(365 + 1 + 1);
    while (N--) {
        int s, t;
        cin >> s >> t;
        ++cdf[s];
        --cdf[t + 1];
    }
    int ans = 0;
    FOR(i, 1, 365 + 1 + 1) {
        cdf[i] += cdf[i - 1];
        ans += cdf[i] > 0;
    }
    cout << ans << '\n';
    cout.flush();
    return 0;
}
