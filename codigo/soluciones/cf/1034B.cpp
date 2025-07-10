#include <bits/stdc++.h>
using namespace std;
#define MAX(a,b) a = max(a, b)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, j, k;
        cin >> n >> j >> k;
        --j;
        vector<int> a(n);
        int val, mx = INT_MIN;
        for (auto &it : a) {
            cin >>it;
            MAX(mx, it);
        }
        if (k == 1 && a[j] != mx) {
            cout << "NO\n";
        }else {
            cout << "YES\n";
        }
    }
    cout.flush();
    return 0;
}
