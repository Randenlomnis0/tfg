#include <bits/stdc++.h>
using namespace std;

signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int l1, b1, l2, b2, l3, b3;
        cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
        int sideLen = floor(sqrt(l1 * b1 + l2 * b2 + l3 * b3));
        if (sideLen * sideLen != l1 * b1 + l2 * b2 + l3 * b3) {
            cout << "NO\n";
            continue;
        }
        if (l1 == l2 + l3 && b2 == b3 && b1 + b2 == l1) {
            cout << "YES\n";
            continue;
        }
        if (l1 == l2 && l1 == l3 && b1 + b2 + b3 == l1) {
            cout << "YES\n";
            continue;
        }
        if (b1 == b2 + b3 && l2 == l3 && l1 + l2 == b1) {
            cout << "YES\n";
            continue;
        }
        if (b1 == b2 && b1 == b3 && l1 + l2 + l3 == b1) {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
    cout.flush();
    return 0;
}
