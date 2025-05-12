#include <bits/stdc++.h>
using namespace std;
#define MAX(a,b) a = max(a, b)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    map<set<int>, int> ft;
    int norm = 0;
    while (n--) {
        int aux, k = 5;
        set<int> s;
        while (k--) {
            cin >> aux;
            s.insert(aux);
        }
        MAX(norm, ++ft[s]);
    }
    int ans = 0;
    for (auto &it : ft) {
        if (it.second < norm) continue;
        ans += it.second;
    }
    cout << ans << '\n';
    cout.flush();
    return 0;
}
