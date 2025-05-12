#include <bits/stdc++.h>
using namespace std;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    while (cin >> a >> b, a || b) {
        int ans = 0;
        while (a && b) {
            if ((a%10) + (b%10) > 9) {
                ++ans;
                a += 10;
            }
            a /= 10;
            b /= 10;
        }
        if (ans == 0) {
            cout << "No";
        }else {
            cout << ans;
        }
        cout << " carry operation";
        if (ans > 1) {
            cout << 's';
        }
        cout << ".\n";
    }
    cout.flush();
    return 0;
}
