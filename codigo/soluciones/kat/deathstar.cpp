#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> ans(N);
    FOR(i, 0, N) {
        FOR(j, 0, N) {
            int aux;
            cin >> aux;
            ans[i] |= aux;
            ans[j] |= aux;
        }
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
