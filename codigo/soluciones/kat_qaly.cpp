#include <bits/stdc++.h>
using namespace std;

signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    double ans = 0.0;
    while (N--) {
        double q, y;
        cin >> q >> y;
        ans += q * y;
    }
    cout << fixed << setprecision(3) << ans << '\n';
    cout.flush();
    return 0;
}
