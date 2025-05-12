#include <bits/stdc++.h>
using namespace std;
#define MAX(a,b) a = max(a, b)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> H(N);
    int mx = 0;
    for (auto &it : H) {
        cin >> it;
        MAX(mx, it);
    }
    vector<int> arrow(mx + 1);
    int ans = 0;
    for (auto &it : H) {
        if (!arrow[it]) {
            ++ans;
        }else {
            --arrow[it];
        }
        ++arrow[it - 1];
    }
    cout << ans << '\n';
    cout.flush();
    return 0;
}
