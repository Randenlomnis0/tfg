#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a, b)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    set<pair<int, int>> points;
    int ans = 0;
    while (n--) {
        int x, y;
        cin >> x >> y;
        for (int i = -2018; i <= 2018; i += 2018 * 2) {
            ans += points.count(mp(x + i, y));
            ans += points.count(mp(x, y + i));
        }
        for (int i = -1118; i <= 1118; i += 1118 * 2) {
            for (int j = -1680; j <= 1680; j += 1680 * 2) {
                ans += points.count(mp(x + i, y + j));
                ans += points.count(mp(x + j, y + i));
            }
        }
        points.insert(mp(x, y));
    }
    cout << ans << '\n';
    cout.flush();
    return 0;
}
