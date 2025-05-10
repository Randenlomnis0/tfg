#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define MAX(a,b) a = max(a, b)
#define pb(x) push_back(x)
#define SZ(c) ((int)(c).size())
signed main() {
    int C, n;
    while (cin >> C >> n) {
        vector<pair<int, int>> v(n);
        for (auto &it : v) {
            cin >> it.first >> it.second;
        }
        vector<vector<int>> dp(2, vector<int>(C + 1, -1));
        int cur = 0;
        dp[1 - cur][0] = 0;
        for (auto &it : v) {
            int v = it.first, w = it.second;
            FOR(i, 0, C + 1) {
                dp[cur][i] = dp[1 - cur][i];
                if (i < w || dp[1 - cur][i - w] == -1) continue;
                dp[cur][i] = dp[1 - cur][i - w] + v;
            }
            cur = 1 - cur;
        }
        int aux = 0;
        FOR(i, 0, C + 1) {
            if (dp[1 - cur][i] == -1 || dp[1 - cur][aux] >= dp[1 - cur][i]) continue;
            aux = i;
        }
        vector<int> ans;
        while (aux) {
            FOR(i, 0, n) {
                if (v[i].first == INT_MAX) continue;
                if (dp[1 - cur][aux] - v[i].first != dp[1 - cur][aux - v[i].second]) continue;
                v[i].first = INT_MAX;
                ans.pb(i);
                aux -= v[i].second;
                break;
            }
        }
        cout << SZ(ans) << '\n';
        bool first = true;
        for (auto &it : ans) {
            if (!first) cout << ' ';
            else first = false;
            cout << it;
        }
        cout << '\n';
    }
    return 0;
}
