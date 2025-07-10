#include <bits/stdc++.h>
using namespace std;

signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        int ans = 0;
        while (n--) {
            int dx, dy, x, y;
            cin >> dx >> dy >> x >> y;
            if (dx == -1) {
                if (dy == -1) {
                    if (x == y) ++ans;
                }else {
                    if (x + y == s) ++ans;
                }
            }else {
                if (dy == -1) {
                    if (x + y == s) ++ans;
                }else {
                    if (x == y) ++ans;
                }
            }
        }
        cout << ans << '\n';
    }
    cout.flush();
    return 0;
}
