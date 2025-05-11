#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, s, m, n;
    while (cin >> a >> b >> s >> m >> n, a || b || s || m || n) {
        ll x = m * a, y = n * b;
        double delta = atan2(y, x);
        cout << fixed << setprecision(2) << 180 * delta / acos(-1.0) << ' ' << fixed << setprecision(2) << sqrt(x * x + y * y) / s << '\n';
    }
    cout.flush();
    return 0;
}
