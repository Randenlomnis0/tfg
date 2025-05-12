#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define mp(a,b) make_pair(a, b)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> P(N, vector<int>(M));
    for (auto &it : P) {
        for (auto &iit : it) {
            cin >> iit;
        }
    }
    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq;
    FOR(i, 0, N) {
        pq.push(mp(mp(0, i), 0));
    }
    vector<int> ans(N);
    vector<int> ready(M);
    while (!pq.empty()) {
        int t = pq.top().first.first;
        int i = pq.top().first.second;
        int s = pq.top().second;
        pq.pop();
        if (s == M) {
            ans[i] = t;
            continue;
        }
        ready[s] = max(ready[s], t) + P[i][s];
        pq.push(mp(mp(ready[s], i), s + 1));
    }
    bool first = true;
    for (auto &it : ans) {
        if (!first) cout << ' ';
        else first = false;
        cout << it;
    }
    cout << '\n';
    cout.flush();
    return 0;
}
