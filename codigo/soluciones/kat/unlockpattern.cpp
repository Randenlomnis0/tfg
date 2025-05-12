#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a, b)
#define ALL(c) (c).begin(), (c).end()
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    vector<pair<int, pair<int, int>>> V;
    FOR(i, 0, 3) {
        FOR(j, 0, 3) {
            int k;
            cin >> k;
            V.pb(mp(k, mp(i, j)));
        }
    }
    sort(ALL(V));
    double ans = 0.0;
    FOR(i, 1, 9) {
        ans += sqrt((V[i].second.first - V[i - 1].second.first) * (V[i].second.first - V[i - 1].second.first) + (V[i].second.second - V[i - 1].second.second) * (V[i].second.second - V[i - 1].second.second));
    }
    cout << fixed << setprecision(6) << ans << '\n';
    cout.flush();
    return 0;
}
