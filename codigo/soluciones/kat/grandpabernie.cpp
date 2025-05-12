#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define ALL(c) (c).begin(), (c).end()
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    unordered_map<string, vector<int>> ft;
    while (n--) {
        string s;
        int y;
        cin >> s >> y;
        ft[s].pb(y);
    }
    for (auto &it : ft) {
        sort(ALL(it.second));
    }
    int q;
    cin >> q;
    while (q--) {
        string s;
        int k;
        cin >> s >> k;
        cout << ft[s][k - 1] << '\n';
    }
    cout.flush();
    return 0;
}
