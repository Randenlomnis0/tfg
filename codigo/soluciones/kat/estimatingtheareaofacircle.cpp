#include <bits/stdc++.h>
using namespace std;

signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    double r;
    int m, c;
    while (cin >> r >> m >> c, r != 0.0 || m != 0 || c != 0) {
        double ans = acos(-1.0) * r * r;
        cout << fixed << setprecision(5) << ans << ' ' << fixed << setprecision(5) << ans * ( (c / (double)m) / (ans / (4 * r * r))) << '\n';
    }
    cout.flush();
    return 0;
}
