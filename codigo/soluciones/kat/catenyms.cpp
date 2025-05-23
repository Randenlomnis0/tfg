#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define pb(x) push_back(x)
#define SZ(c) ((int)(c).size())
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> name(n);
        unordered_map<string, int> id;
        FOR(i, 0, n) {
            cin >> name[i];
            id[name[i]] = i;
        }
        vector<vector<int>> AL(n);
        FOR(i, 0, n) {
            FOR(j, i + 1, n) {
                if (*name[i].rbegin() == *name[j].begin()) {
                    AL[i].pb(j);
                }
                if (*name[j].rbegin() == *name[i].begin()) {
                    AL[j].pb(i);
                }
            }
        }
        int a = 0, b = 0, c = 0, d = 0;
        vector<int> idgr(n);
        for (auto &it : AL) {
            for (auto &iit : it) {
                ++idgr[iit];
            }
        }
        FOR(i, 0, n) {
            if (SZ(AL[i]) == idgr[i]) {
                ++a;
            }else if (SZ(AL[i]) == idgr[i] + 1) {
                ++b;
            }else if (SZ(AL[i]) == idgr[i] - 1) {
                ++c;
            }else {
                ++d;
            }
        }
        if (d > 0 || b > 1 || c > 1 || b != c || a + b + c != n) {
            cout << "***\n";
        }else {
            
        }
    }
    cout.flush();
    return 0;
}
