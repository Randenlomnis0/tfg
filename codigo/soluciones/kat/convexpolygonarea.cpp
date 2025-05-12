#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define FOR(i,j,k) for (int i = j; i < k; ++i)
struct Point {
    double x, y;
};
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (n--) {
        int m;
        cin >> m;
        vector<Point> P(m);
        for (auto &it : P) {
            cin >> it.x >> it.y;
        }
        P.pb(P[0]);
        double ans = 0.0;
        FOR(i, 0, m) {
            ans += P[i].x * P[i + 1].y - P[i + 1].x * P[i].y;
        }
        cout << fabs(ans) / 2.0 << '\n';
    }
    cout.flush();
    return 0;
}
