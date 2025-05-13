#include <bits/stdc++.h>
using namespace std;
#define ALL(c) (c).begin(), (c).end()
#define int long long
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> items(n);
    for (auto &it : items) {
        cin >> it;
    }
    sort(ALL(items));
    int ans = 0;
    while (n > 2) {
        n -= 3;
        ans += items[n];
    }
    cout << ans << '\n';
    cout.flush();
    return 0;
}
