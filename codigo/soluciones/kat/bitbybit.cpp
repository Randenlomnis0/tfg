#include <bits/stdc++.h>
using namespace std;
#define ALL(c) (c).begin(), (c).end()
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n, n) {
        string ans = string(32, '?');
        while (n--) {
            string instr;
            cin >> instr;
            if (instr == "CLEAR") {
                int i;
                cin >> i;
                ans[i] = '0';
            }else if (instr == "SET") {
                int i;
                cin >> i;
                ans[i] = '1';
            }else if (instr == "OR") {
                int i, j;
                cin >> i >> j;
                if (ans[i] == '1' || ans[j] == '1') {
                    ans[i] = '1';
                }else if (ans[i] == '0' && ans[j] == '0') {
                    ans[i] = '0';
                }else {
                    ans[i] = '?';
                }
            }else {
                int i, j;
                cin >> i >> j;
                if (ans[i] == '0' || ans[j] == '0') {
                    ans[i] = '0';
                }else if (ans[i] == '1' && ans[j] == '1') {
                    ans[i] = '1';
                }else {
                    ans[i] = '?';
                }
            }
        }
        reverse(ALL(ans));
        cout << ans << '\n';
    }
    cout.flush();
    return 0;
}
