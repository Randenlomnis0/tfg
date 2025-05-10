#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a, b)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    multiset<pair<int, int>, less<pair<int, int>>> quests;
    while (N--) {
        string cmd;
        cin >> cmd;
        if (cmd == "add") {
            int E, G;
            cin >> E >> G;
            quests.insert(mp(E, G));
        }else {
            int X;
            cin >> X;
            int ans = 0;
            while (!quests.empty()) {
                auto it = quests.upper_bound(mp(X, INT_MAX));
                if (it == quests.begin()) break;
                --it;
                X -= it->first;
                ans += it->second;
                quests.erase(it);
            }
            cout << ans << '\n';
        }
    }
    cout.flush();
    return 0;
}
