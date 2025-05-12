#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string s1, s2;
    cin >> n >> s1 >> s2;
    unordered_map<char, int> ft;
    int r = 0, s = 0;
    FOR(i, 0, n) {
        if (s1[i] != s2[i]) {
            ++ft[s1[i]];
        }
    }
    FOR(i, 0, n) {
        if (s1[i] == s2[i]) {
            ++r;
        }else {
            if (ft[s2[i]]) {
                --ft[s2[i]];
                ++s;
            }
        }
    }
    cout << r << ' ' << s << '\n';
    cout.flush();
    return 0;
}
