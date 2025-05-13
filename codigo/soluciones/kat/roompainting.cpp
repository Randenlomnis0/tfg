#include <bits/stdc++.h>
using namespace std;
#define ALL(c) (c).begin(), (c).end()
#define int long long
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> sizes(n);
    for (auto &it : sizes) {
        cin >> it;
    }
    sort(ALL(sizes));
    int ans = 0;
    while (m--) {
        int sz;
        cin >> sz;
        ans += *lower_bound(ALL(sizes), sz) - sz;
    }
    cout << ans << '\n';
    cout.flush();
    return 0;
}
