#include <bits/stdc++.h>
using namespace std;
#define ALL(c) (c).begin(), (c).end()
#define mp(a,b) make_pair(a, b)
#define SZ(c) ((int)(c).size())
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<pair<int, int>> v(m);
        for (auto &it : v) {
            cin >> it.first >> it.second;
        }
        sort(ALL(v), greater<pair<int, int>>());
        set<pair<int, int>> s;
        for (auto &it : v) {
            auto aux = lower_bound(ALL(s), mp(it.second + 1, it.first + 1));
            if (aux != s.end()) {
                s.erase(aux);
            }
            s.insert(mp(it.second, it.first));
        }
        cout << SZ(s) << '\n';
    }
    cout.flush();
    return 0;
}
