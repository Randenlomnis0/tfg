#include <bits/stdc++.h>
using namespace std;
#define LEN(s) ((int)(s).length())
#define FOR(i,j,k) for (int i = j; i < k; ++i)
unordered_map<char, char> m = {{'R', 'S'}, {'B', 'K'}, {'L', 'H'}};
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int a = 0, b = 0, c = 0;
    string ans = "";
    if (LEN(s) < 3) {
        for (auto &it : s) {
            ans += m[it];
        }
    }else {
        vector<bool> esCombo(LEN(s), false);
        a += (s[0] == 'R') + (s[1] == 'R');
        b += (s[0] == 'B') + (s[1] == 'B');
        c += (s[0] == 'L') + (s[1] == 'L');
        FOR(i, 2, LEN(s)) {
            if (s[i] == 'R') {
                ++a;
            }else if (s[i] == 'B') {
                ++b;
            }else {
                ++c;
            }
            if (!esCombo[i - 2] && !esCombo[i - 1] && !esCombo[i] && a == 1 && b == 1 && c == 1) {
                esCombo[i - 2] = esCombo[i - 1] = esCombo[i] = true;
            }
            if (s[i - 2] == 'R') {
                --a;
            }else if (s[i - 2] == 'B') {
                --b;
            }else {
                --c;
            }
        }
        if (!esCombo[0]) {
            ans += m[s[0]];
        }
        if (!esCombo[1]) {
            ans += m[s[1]];
        }
        FOR(i, 2, LEN(s)) {
            if (esCombo[i - 2] && esCombo[i - 1] && esCombo[i]) {
                esCombo[i - 2] = esCombo[i - 1] = esCombo[i] = false;
                ans += 'C';
            }else if (!esCombo[i]) {
                ans += m[s[i]];
            }
        }
    }
    cout << ans << '\n';
    cout.flush();
    return 0;
}

