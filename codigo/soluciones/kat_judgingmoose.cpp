#include <bits/stdc++.h>
using namespace std;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int l, r;
    cin >> l >> r;
    if (l + r == 0) {
        cout << "Not a moose\n";
    } else {
        cout << (l == r ? "Even" : "Odd") << " " << 2 * max(l, r) << "\n";
    }
    cout.flush();
    return 0;
}
