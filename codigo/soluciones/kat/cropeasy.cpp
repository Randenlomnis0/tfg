#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define int long long
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    FOR(t, 0, T) {
        int n, A, B, C, D, x, y, M;
        cin >> n >> A >> B >> C >> D >> x >> y >> M;
        vector<pair<int, int>> trees(n);
        FOR(i, 0, n) {
            trees[i].first = x;
            trees[i].second = y;
            x = (A * x + B)%M;
            y = (C * y + D)%M;
        }
        int ans = 0;
        FOR(i, 0, n) {
            FOR(j, i + 1, n) {
                FOR(k, j + 1, n) {
                    if ((trees[i].first + trees[j].first + trees[k].first)%3 != 0 || (trees[i].second + trees[j].second + trees[k].second)%3 != 0) continue;
                    ++ans;
                }
            }
        }
        cout << "Case #" << t + 1 << ": " << ans << '\n';
    }
    cout.flush();
    return 0;
}
