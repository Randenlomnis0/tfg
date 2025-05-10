#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define SZ(c) ((int)(c).size())
#define pb(x) push_back(x)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> s(2 * n), saux;
    FOR(i, 0, 2 * n) {
        cin >> s[i];
    }
    FOR(i, 0, 2 * n) {
        if (SZ(saux) > 0 && s[i] == saux[SZ(saux) - 1]) {
            saux.pop_back();
        }else {
            saux.pb(s[i]);
        }
    }
    cout << (saux.empty() ? to_string(2 * n) : "impossible") << '\n';
    cout.flush();
    return 0;
}
