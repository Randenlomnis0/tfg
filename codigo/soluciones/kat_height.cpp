#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int P;
    cin >> P;
    while (P--) {
        int K;
        cin >> K;
        set<int> q;
        int ans = 0;
        FOR(j, 0, 20) {
            int h;
            cin >> h;
            ans += distance(q.upper_bound(h), q.end());
            q.insert(h);
        }
        cout << K << ' ' << ans << '\n';
    }
    cout.flush();
    return 0;
}
