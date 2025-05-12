#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define MIN(a,b) a = min(a, b)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> prizes(n);
        vector<int> value(n);
        FOR(i, 0, n) {
            int k;
            cin >> k;
            prizes[i] = vector<int>(k);
            FOR(j, 0, k) {
                cin >> prizes[i][j];
                --prizes[i][j];
            }
            cin >> value[i];
        }
        vector<int> stickers(m);
        FOR(i, 0, m) {
            cin >> stickers[i];
        }
        int ans = 0;
        FOR(i, 0, n) {
            int aux = INT_MAX;
            for (auto &it : prizes[i]) {
                MIN(aux, stickers[it]);
            }
            ans += aux * value[i];
        }
        cout << ans << '\n';
    }
    cout.flush();
    return 0;
}
