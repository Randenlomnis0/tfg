#include <bits/stdc++.h>
using namespace std;
#define ALL(c) (c).begin(), (c).end()
#define pb(x) push_back(x)
#define FOR(i,j,k) for (int i = j; i < k; ++i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int l, d, n;
    cin >> l >> d >> n;
    vector<int> birds(n);
    for (auto &it : birds) {
        cin >> it;
    }
    birds.pb(6 - d);
    birds.pb(l - 6 + d);
    n += 2;
    sort(ALL(birds));
    int ans = 0;
    FOR(i, 1, n) {
        ans += max(0, (birds[i] - birds[i - 1]) / d - 1);
    }
    cout << ans << '\n';
    cout.flush();
    return 0;
}
