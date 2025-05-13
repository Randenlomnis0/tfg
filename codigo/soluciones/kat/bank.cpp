#include <bits/stdc++.h>
using namespace std;
#define ALL(c) (c).begin(), (c).end()
#define SZ(c) ((int)(c).size())
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N, T;
    cin >> N >> T;
    vector<pair<int, int>> q(N);
    for (auto &it : q) {
        int c, t;
        cin >> c >> t;
        it.first = t;
        it.second = c;
    }
    sort(ALL(q));
    priority_queue<int> pq;
    for (auto &it : q) {
        int c = it.second, t = it.first;
        if (SZ(pq) < t + 1) {
            pq.push(-c);
        }else if (-pq.top() < c) {
            pq.pop();
            pq.push(-c);
        }
    }
    int ans = 0;
    while (!pq.empty()) {
        ans -= pq.top();
        pq.pop();
    }
    cout << ans << '\n';
    cout.flush();
    return 0;
}
