#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define LEN(s) ((int)(s).length())
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int C;
    cin >> C;
    FOR(i, 1, C + 1) {
        string S, T;
        cin >> S >> T;
        int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
        FOR(j, 0, LEN(S)) {
            if (S[j] == '0') {
                if (T[j] == '0') {
                    ++a;
                }else {
                    ++b;
                }
            }else if (S[j] == '1') {
                if (T[j] == '0') {
                    ++c;
                }else {
                    ++d;
                }
            }else {
                if (T[j] == '0') {
                    ++e;
                }else {
                    ++f;
                }
            }
        }
        int ans = min(b, c);
        b -= ans;
        c -= ans;
        if (b > 0) {
            ans += b + e + f;
        }else if (f < c) {
            ans = -1;
        }else {
            ans += c;
            e -= c;
            ans += c;
            ans += e + f;
        }
        cout << "Case " << i << ": " << ans << '\n';
    }
    cout.flush();
    return 0;
}
