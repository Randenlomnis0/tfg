#include <bits/stdc++.h>
using namespace std;
#define ALL(c) (c).begin(), (c).end()
#define FOR(i,j,k) for (int i = j; i < k; ++i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> P(3 * N);
        for (auto &it : P) {
            cin >> it;
        }
        sort(ALL(P));
        int ans = 0;
        FOR(i, 0, N) {
            ans += P[3 * N - 2 * i - 2];
        }
        cout << ans << '\n';
    }
    cout.flush();
    return 0;
}
