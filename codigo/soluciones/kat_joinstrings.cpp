#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<string> s(N);
    for (auto &it : s) {
        cin >> it;
    }
    vector<int> adj(N, -1), last(N);
    FOR(i, 0, N) {
        last[i] = i;
    }
    int idx = 0;
    while (--N) {
        int i, j;
        cin >> i >> j;
        --i;
        --j;
        idx = i;
        adj[last[i]] = j;
        last[i] = last[j];
    }
    while (idx != -1) {
        cout << s[idx];
        idx = adj[idx];
    }
    cout << '\n';
    cout.flush();
    return 0;
}
