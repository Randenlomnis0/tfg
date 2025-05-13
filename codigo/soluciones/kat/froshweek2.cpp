#include <bits/stdc++.h>
using namespace std;
#define ALL(c) (c).begin(), (c).end()
#define FOR(i,j,k) for (int i = j; i < k; ++i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> tasks(n);
    for (auto &it : tasks) {
        cin >> it;
    }
    sort(ALL(tasks));
    vector<int> intervals(m);
    for (auto &it : intervals) {
        cin >> it;
    }
    sort(ALL(intervals));
    int ans = 0, j = 0;
    FOR(i, 0, n) {
        while (j < m && intervals[j] < tasks[i]) {
            ++j;
        }
        if (j < m) {
            ++ans;
            ++j;
        }
    }
    cout << ans << '\n';
    cout.flush();
    return 0;
}
