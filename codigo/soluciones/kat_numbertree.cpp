#include <bits/stdc++.h>
using namespace std;
#define LEN(s) ((int)(s).length())
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int H;
    string path;
    cin >> H >> path;
    int ans = 1;
    for (auto &it : path) {
        if (it == 'L') {
            ans = (ans<<1);
        }else {
            ans = (ans<<1) + 1;
        }
    }
    cout << (1<<(H + 1)) - ans << '\n';
    cout.flush();
    return 0;
}
