#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int w, h, n;
        cin >> w >> h >> n;
        vector<vector<string>> mp(2, vector<string>(h));
        vector<int> ships(2);
        FOR(i, 0, 2) {
            for (auto &it : mp[i]) {
                cin >> it;
                for (auto &iit : it) {
                    if (iit == '#') {
                        ++ships[i];
                    }
                }
            }
        }
        int turn = 0, ans = -1;
        while (n--) {
            int x, y;
            cin >> x >> y;
            if (ans != -1) continue;
            y = h - y - 1;
            turn = 1 - turn;
            if (mp[turn][y][x] == '#') {
                mp[turn][y][x] = '_';
                --ships[turn];
                if (ships[turn]) turn = 1 - turn;
            }
            if (turn == 0) {
                ans += 2 * (ships[0] == 0) + (ships[1] == 0);
            }
        }
        if (ans == 0) {
            cout << "player one wins\n";
        }else if (ans == 1) {
            cout << "player two wins\n";
        }else {
            cout << "draw\n";
        }
    }
    cout.flush();
    return 0;
}
