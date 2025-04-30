#include <bits/stdc++.h>
using namespace std;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int x, y;
    while (cin >> x >> y, x || y) {
        if (x + y == 13) {
            cout << "Never speak again.\n";
        }else if (y > x) {
            cout << "Left beehind.\n";
        }else if (x > y) {
            cout << "To the convention.\n";
        }else {
            cout << "Undecided.\n";
        }
    }
    cout.flush();
    return 0;
}
