#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define ALL(c) (c).begin(), (c).end()
#define int long long
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, a, c, x;
    cin >> n >> m >> a >> c >> x;
    vector<int> X(n);
    X[0] = (a * x + c)%m;
    FOR(i, 1, n) {
        X[i] = (a * X[i - 1] + c)%m;
    }
    int ans = 0;
    FOR(i, 0, n) {
        int lb = 0, hb = n - 1;
        bool found = false;
        while (lb <= hb) {
            int nb = (hb + lb) / 2;
            if (X[nb] == X[i]) {
                found = true;
                break;
            }else if (X[nb] < X[i]) {
                lb = nb + 1;
            }else {
                hb = nb - 1;
            }
        }
        ans += found;
    }
    cout << ans << '\n';
    cout.flush();
    return 0;
}
