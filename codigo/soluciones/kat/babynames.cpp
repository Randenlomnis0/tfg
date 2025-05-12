#include <bits/stdc++.h>
using namespace std;

signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int cmd;
    set<string> males, females;
    while (cin >> cmd, cmd) {
        if (cmd == 1) {
            string name;
            int suitability;
            cin >> name >> suitability;
            if (suitability == 1) {
                males.insert(name);
            }else {
                females.insert(name);
            }
        }else if (cmd == 2) {
            string name;
            cin >> name;
            males.erase(name);
            females.erase(name);
        }else {
            string l, r;
            int suitability;
            cin >> l >> r >> suitability;
            int ans = 0;
            if (suitability == 0 || suitability == 1) {
                ans += distance(males.lower_bound(l), males.upper_bound(r));
            }
            if (suitability == 0 || suitability == 2) {
                ans += distance(females.lower_bound(l), females.upper_bound(r));
            }
            cout << ans << '\n';
        }
    }
    cout.flush();
    return 0;
}
