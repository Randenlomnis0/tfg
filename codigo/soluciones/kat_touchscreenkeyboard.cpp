#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define LEN(s) ((int)(s).length())
#define ALL(c) (c).begin(), (c).end()
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    unordered_map<char, int> x = {
        {'q', 0},
        {'a', 0},
        {'z', 0},
        {'w', 1},
        {'s', 1},
        {'x', 1},
        {'e', 2},
        {'d', 2},
        {'c', 2},
        {'r', 3},
        {'f', 3},
        {'v', 3},
        {'t', 4},
        {'g', 4},
        {'b', 4},
        {'y', 5},
        {'h', 5},
        {'n', 5},
        {'u', 6},
        {'j', 6},
        {'m', 6},
        {'i', 7},
        {'k', 7},
        {'o', 8},
        {'l', 8},
        {'p', 9}
    };
    unordered_map<char, int> y = {
        {'q', 0},
        {'a', 1},
        {'z', 2},
        {'w', 0},
        {'s', 1},
        {'x', 2},
        {'e', 0},
        {'d', 1},
        {'c', 2},
        {'r', 0},
        {'f', 1},
        {'v', 2},
        {'t', 0},
        {'g', 1},
        {'b', 2},
        {'y', 0},
        {'h', 1},
        {'n', 2},
        {'u', 0},
        {'j', 1},
        {'m', 2},
        {'i', 0},
        {'k', 1},
        {'o', 0},
        {'l', 1},
        {'p', 0}
    };
    while (t--) {
        string a;
        int l;
        cin >> a >> l;
        vector<pair<int, string>> ans(l);
        for (auto &it : ans) {
            cin >> it.second;
            it.first = 0;
            FOR(i, 0, LEN(a)) {
                it.first += abs(x[a[i]] - x[it.second[i]]) + abs(y[a[i]] - y[it.second[i]]);
            }
        }
        sort(ALL(ans));
        for (auto &it : ans) {
            cout << it.second << ' ' << it.first << '\n';
        }
    }
    cout.flush();
    return 0;
}
