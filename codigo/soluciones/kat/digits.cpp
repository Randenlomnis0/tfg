#include <bits/stdc++.h>
using namespace std;
#define LEN(s) ((int)(s).length())
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    while (cin >> s, s != "END") {
        int ans = 1;
        while (s != to_string(LEN(s))) {
            s = to_string(LEN(s));
            ++ans;
        }
        cout << ans << '\n';
    }
    cout.flush();
    return 0;
}
