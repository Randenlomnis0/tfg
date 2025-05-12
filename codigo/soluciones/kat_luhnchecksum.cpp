#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define LEN(s) ((int)(s).length())
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int ans = 0;
        FOR(i, 0, LEN(s)) {
            if (i%2) {
                int aux = 2 * (s[LEN(s) - i - 1] - '0');
                if (aux > 9) aux = aux / 10 + aux%10;
                s[LEN(s) - i - 1] = aux + '0';
            }
            ans += s[LEN(s) - i - 1] - '0';
        }
        cout << (ans%10 ? "FAIL" : "PASS") << '\n';
    }
    cout.flush();
    return 0;
}
