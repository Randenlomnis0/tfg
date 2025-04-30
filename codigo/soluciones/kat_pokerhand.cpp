#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define MAX(a,b) a = max(a, b)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    map<char, int> ft;
    FOR(i, 0, 5) {
        cin >> s;
        ++ft[s[0]];
    }
    int ans = 0;
    for (auto &it : ft) {
        MAX(ans, it.second);
    }
    cout << ans << '\n';
    cout.flush();
    return 0;
}
