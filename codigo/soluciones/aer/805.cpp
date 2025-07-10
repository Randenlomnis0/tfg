#include <bits/stdc++.h>
using namespace std;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n, n) {
        int prev, cnt = 0, ans = 1;
        cin >> prev;
        while (--n) {
            int curr;
            cin >> curr;
            if (cnt + prev < curr) {
                cnt += prev;
                ++ans;
            }
            prev = curr;
        }
        cout << ans << '\n';
    }
    cout.flush();
    return 0;
}
