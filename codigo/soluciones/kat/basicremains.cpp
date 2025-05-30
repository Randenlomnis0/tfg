#include <bits/stdc++.h>
using namespace std;
#define LEN(s) ((int)(s).length())
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int b;
    while (cin >> b, b) {
        string p, m;
        cin >> p >> m;
        string p10 = "", m10 = "";
        int base = 1, i = 0;
        while (i < LEN(p)) {
            p10 += (base * (p[LEN(p) - 1 - i] - '0')) + '0';
            base *= b;
            ++i;
        }
        base = 1;
        i = 0;
        while (i < LEN(m)) {
            m10 += base * (m[LEN(m) - 1 - i] - '0');
            base *= b;
            ++i;
        }
        cout << p10 << ' ' << m10 << '\n';
    }
    cout.flush();
    return 0;
}
