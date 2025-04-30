#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v(n - 1);
    FOR(i, 2, n + 1) {
        int j;
        cin >> j;
        v[j] = i;
    }
    cout << '1';
    for (auto &it : v) {
        cout << ' ' << it;
    }
    cout << '\n';
    cout.flush();
    return 0;
}
