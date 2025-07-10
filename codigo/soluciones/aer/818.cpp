#include <bits/stdc++.h>
using namespace std;
#define int long long
#define x first
#define y second
#define ALL(c) (c).begin(), (c).end()
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define SZ(c) ((int)(c).size())
#define pb push_back
#define mp make_pair
#define RFOR(i,j,k) for (int i = j - 1; i >= k; --i)
int cross(const pair<int, int> &u, const pair<int, int> &v) {
    return u.x * v.y - u.y * v.x;
}
bool ccw(const pair<int, int> &a, const pair<int, int> &b, const pair<int, int> &c) {
    return cross(mp(b.x - a.x, b.y - a.y), mp(c.x - a.x, c.y - a.y)) > 0;
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n, n) {
        vector<pair<int, int>> a(n);
        for (auto &it : a) {
            cin >> it.x >> it.y;
        }
        sort(ALL(a));
        pair<int, int> A = a.front(), B = a.back();
        vector<pair<int, int>> hull;
        FOR(i, 0, n) {
            while (SZ(hull) >= 2 && !ccw(hull[SZ(hull) - 2], hull[SZ(hull) - 1], a[i])) {
                hull.pop_back();
            }
            hull.pb(a[i]);
        }
        int aux = SZ(hull);
        RFOR(i, n - 1, 0) {
            while (SZ(hull) > aux && !ccw(hull[SZ(hull) - 2], hull[SZ(hull) - 1], a[i])) {
                hull.pop_back();
            }
            hull.pb(a[i]);
        }
        hull.pop_back();
        int ans = 0;
        FOR(i, 0, SZ(hull)) {
            ans += hull[i].x * hull[(i + 1)%SZ(hull)].y - hull[i].y * hull[(i + 1)%SZ(hull)].x;
        }
        ans = abs(ans);
        cout << ans / 2;
        if (ans%2 != 0) {
            cout << ".5";
        }
        cout << '\n';
    }
    cout.flush();
    return 0;
}
