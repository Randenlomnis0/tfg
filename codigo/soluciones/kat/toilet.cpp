#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define LEN(s) ((int)(s).length())
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int ans = 0;
    char state = s[0];
    FOR(i, 1, LEN(s)) {
        if (state != s[i]) {
            ++ans;
            state = s[i];
        }
        if (state != 'U') {
            ++ans;
            state = 'U';
        }
    }
    cout << ans << '\n';
    ans = 0;
    state = s[0];
    FOR(i, 1, LEN(s)) {
        if (state != s[i]) {
            ++ans;
            state = s[i];
        }
        if (state != 'D') {
            ++ans;
            state = 'D';
        }
    }
    cout << ans << '\n';
    ans = 0;
    state = s[0];
    FOR(i, 1, LEN(s)) {
        if (state != s[i]) {
            ++ans;
            state = s[i];
        }
    }
    cout << ans << '\n';
    cout.flush();
    return 0;
}
