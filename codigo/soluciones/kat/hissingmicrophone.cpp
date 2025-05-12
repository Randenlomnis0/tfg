#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define LEN(s) ((int)(s).length())
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    bool hiss = false;
    FOR(i, 1, LEN(s)) {
        if (s[i] == 's' && s[i - 1] == 's') {
            hiss = true;
            break;
        }
    }
    if (!hiss) {
        cout << "no ";
    }
    cout << "hiss\n";
    cout.flush();
    return 0;
}
