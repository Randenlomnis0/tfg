#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define RFOR(i,j,k) for (int i = j - 1; i >= k; --i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &it : v) {
        cin >> it;
    }
    int aux = v[0];
    vector<bool> ans(n, true);
    FOR(i, 1, n) {
        if (aux > v[i]) {
            ans[i] = false;
        }else {
            aux = v[i];
        }
    }
    aux = v[n - 1];
    RFOR(i, n - 1, 0) {
        if (v[i] > aux) {
            ans[i] = false;
        }else {
            aux = v[i];
        }
    }
    aux = 0;
    for (auto it : ans) {
        aux += it;
    }
    cout << aux << '\n';
    cout.flush();
    return 0;
}
