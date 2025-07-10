#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define LEN(s) ((int)(s).length())
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        unordered_map<char, int> ft;
        FOR(i, 1, n - 1) {
            ++ft[s[i]];
        }
        bool ans = false;
        for (auto &it : ft) {
            if (it.second > 1) {
                ans = true;
            }else if (it.second == 1 && (it.first == s[0] || it.first == s[LEN(s) - 1])) {
                ans = true;
            }
            if (ans) break;
        }
        cout << (ans ? "Yes" : "No") << '\n';
    }
    cout.flush();
    return 0;
}
