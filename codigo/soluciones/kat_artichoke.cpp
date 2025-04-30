#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define MAX(a,b) a = max(a, b)
double f(const int& p, const int &a, const int& b, const int& c, const int& d, const int& k) {
    return p * (sin(a * k + b) + cos(c * k + d) + 2);
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int p, a, b, c, d, n;
    cin >> p >> a >> b >> c >> d >> n;
    double m, ans = 0.0;
    m = f(p, a, b, c, d, 1);
    FOR(i, 2, n + 1) {
        double aux = f(p, a, b, c, d, i);
        MAX(ans, m - aux);
        MAX(m, aux);
    }
    cout << fixed << setprecision(6) << ans << '\n';
    cout.flush();
    return 0;
}
