#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int f, c;
    while (cin >> f >> c, f || c) {
        unordered_map<char, unordered_map<char, int>> ft;
        FOR(i, 0, f) {
            string s, g;
            cin >> s >> g;
            FOR(j, 0, c) {
                ++ft[s[j]][g[j]];
            }
        }
        if (ft['0']['0'] + ft['0']['1'] > ft['0']['0'] + ft['1']['0'] + ft['R']['0']) {
            cout << "IMPOSIBLE\n";
            continue;
        }
        int ans = 0;
        int aux = min(ft['R']['1'], ft['0']['1'] + ft['1']['1'] + ft['R']['1'] - (ft['1']['0'] + ft['1']['1']));
        ft['R']['1'] -= aux;
        ft['1']['1'] += aux;
        ans += aux;
        ft['0']['1'] += ft['R']['1'];
        ans += ft['R']['1'];
        ft['R']['1'] = 0;
        aux = min(ft['R']['0'], ft['0']['1'] + ft['1']['1'] + ft['R']['1'] - (ft['1']['0'] + ft['1']['1']));
        ft['R']['0'] -= aux;
        ft['1']['0'] += aux;
        ans += aux;
        ft['0']['0'] += ft['R']['0'];
        ans += ft['R']['0'];
        ft['R']['0'] = 0;
        ans += ft['1']['0'];
        cout << ans << '\n';
    }
    cout.flush();
    return 0;
}
