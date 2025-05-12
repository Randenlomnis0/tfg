#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n, p, m;
    cin >> n >> p >> m;
    map<string, int> points;
    while (n--) {
        string name;
        cin >> name;
    }
    vector<string> ans;
    while (m--) {
        string name;
        int paux;
        cin >> name >> paux;
        if (points[name] < p && points[name] + paux >= p) {
            ans.pb(name);
        }
        points[name] += paux;
    }
    for (auto &it : ans) {
        cout << it << " wins!\n";
    }
    if (ans.empty()) {
        cout << "No winner!\n";
    }
    cout.flush();
    return 0;
}
