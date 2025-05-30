#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define LEN(s) ((int)(s).length())
#define ALL(c) (c).begin(), (c).end()
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    string b8;
    cin >> b8;
    string b2 = "";
    FOR(i, 0, LEN(b8)) {
        int aux = b8[i] - '0';
        b2 += ((aux / 4)%2 ? "1" : "0");
        b2 += ((aux / 2)%2 ? "1" : "0");
        b2 += (aux%2 ? "1" : "0");
    }
    string b16 = "";
    for (int i = 0; i < LEN(b2); i += 4) {
        int aux = 0;
        if (b2[LEN(b2) - 1 - i] == '1') {
            aux += 1;
        }
        if (i + 1 < LEN(b2) && b2[LEN(b2) - 1 - (i + 1)] == '1') {
            aux += 2;
        }
        if (i + 2 < LEN(b2) && b2[LEN(b2) - 1 - (i + 2)] == '1') {
            aux += 4;
        }
        if (i + 3 < LEN(b2) && b2[LEN(b2) - 1 - (i + 3)] == '1') {
            aux += 8;
        }
        if (aux >= 10) {
            b16 += aux - 10 + 'A';
        }else {
            b16 += aux + '0';
        }
    }
    reverse(ALL(b16));
    cout << b16 << '\n';
    cout.flush();
    return 0;
}
