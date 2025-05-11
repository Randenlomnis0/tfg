#include <bits/stdc++.h>
using namespace std;

signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int r, h, s;
    while (cin >> r >> h >> s, r || h || s) {
        double ans = 2 * sqrt(h * h + r * r);
        double delta = 2 * acos(-1.0) - 2 * (acos(0.0) - acos((2 * h) / ans));
        ans += delta  * r;
        cout << fixed << setprecision(2) << (ans * (s + 100)) / 100 << '\n';
    }
    cout.flush();
    return 0;
}
