#include <bits/stdc++.h>
using namespace std;
#define ALL(c) (c).begin(), (c).end()
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    priority_queue<int> crooms;
    while (k--) {
        crooms.push(0);
    }
    vector<pair<int, int>> activities(n);
    for (auto &it : activities) {
        cin >> it.first >> it.second;
    }
    sort(ALL(activities));
    int ans = n;
    for (auto &it : activities) {
        if (it.first <= -crooms.top()) {
            --ans;
        }else {
            crooms.pop();
            crooms.push(-it.second);
        }
    }
    cout << ans << '\n';
    cout.flush();
    return 0;
}
