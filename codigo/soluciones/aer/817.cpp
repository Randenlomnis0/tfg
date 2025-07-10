#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n, n) {
        int ans = 0;
        while (n--) {
            int k;
            cin >> k;
            vector<int> x(k), y(k);
            FOR(i, 0, k) {
                cin >> x[i] >> y[i];
            }
            int aux = 0;
            FOR(i, 0, k) {
                aux += x[i] * y[(i + 1)%k] - x[(i + 1)%k] * y[i];
            }
            ans += abs(aux);
        }
        cout << ans / 2;
        if (ans%2) {
            cout << ".5";
        }
        cout << '\n';
    }
    cout.flush();
    return 0;
}
