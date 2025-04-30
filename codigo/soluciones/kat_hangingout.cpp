#include <bits/stdc++.h>
using namespace std;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int L, x, ans = 0, ppl = 0;
    cin >> L >> x;
    while (x--) {
        string s;
        int p;
        cin >> s >> p;
        if (s == "enter") {
            if (ppl + p > L) {
                ++ans;
                continue;
            }
            ppl += p;
        }else {
            ppl -= p;
        }
    }
    cout << ans << '\n';
    cout.flush();
    return 0;
}
