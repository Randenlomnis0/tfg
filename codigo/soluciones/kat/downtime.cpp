#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define MAX(a,b) a = max(a, b)
#define SZ(c) ((int)(c).size())
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    queue<int> q;
    int ans = 0;
    FOR(i, 0, n) {
        int t;
        cin >> t;
        q.push(t);
        while (!q.empty() && t - q.front() >= 1000) {
            q.pop();
        }
        MAX(ans, SZ(q));
    }
    cout << ans / k + (ans % k != 0) << '\n';
    cout.flush();
    return 0;
}
