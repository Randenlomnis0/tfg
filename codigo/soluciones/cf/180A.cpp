#include <bits/stdc++.h>
using namespace std;

signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int a, x, y;
        cin >> a >> x >> y;
        if (x > y) {
            swap(x, y);
        }
        if (x < a && a < y) {
            cout << "NO\n";
        }else {
            cout << "YES\n";
        }
    }
    cout.flush();
    return 0;
}
