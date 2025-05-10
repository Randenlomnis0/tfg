#include <bits/stdc++.h>
using namespace std;

signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    while (cin >> N >> M, N || M) {
        unordered_set<int> cds;
        while (N--) {
            int aux;
            cin >> aux;
            cds.insert(aux);
        }
        int ans = 0;
        while (M--) {
            int aux;
            cin >> aux;
            if (cds.count(aux)) {
                ++ans;
            }
        }
        cout << ans << '\n';
    }
    cout.flush();
    return 0;
}
