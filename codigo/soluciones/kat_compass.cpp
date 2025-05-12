#include <bits/stdc++.h>
using namespace std;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n1, n2, dir = 1;
    cin >> n1 >> n2;
    if (n1 > n2) {
        swap(n1, n2);
        dir *= -1;
    }
    int ans = (n2 - n1)%360;
    if (ans > 180) {
        ans = 360 - ans;
        dir *= -1;
    }else if (ans == 180 && dir == -1) {
        dir *= -1;
    }
    cout << ans * dir << '\n';
    cout.flush();
    return 0;
}
