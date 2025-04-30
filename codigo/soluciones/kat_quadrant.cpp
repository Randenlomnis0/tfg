#include <bits/stdc++.h>
using namespace std;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int x, y;
    cin >> x >> y;
    if (y > 0) {
        if (x > 0) {
            cout << "1\n";
        }else {
            cout << "2\n";
        }
    }else {
        if (x > 0) {
            cout << "4\n";
        }else {
            cout << "3\n";
        }
    }
    cout.flush();
    return 0;
}
