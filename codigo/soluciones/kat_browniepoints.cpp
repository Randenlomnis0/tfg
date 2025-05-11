#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
typedef long long ll;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n, n) {
        vector<ll> x(n), y(n);
        FOR(i, 0, n) {
            cin >> x[i] >> y[i];
        }
        int p = x[n / 2], q = y[n / 2];
        int a = 0, b = 0;
        FOR(i, 0, n) {
            a += (x[i] - p) * (y[i] - q) > 0;
            b += (x[i] - p) * (y[i] - q) < 0;
        }
        cout << a << ' ' << b << '\n';
    }
    cout.flush();
    return 0;
}
