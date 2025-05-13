#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    double T;
    int N;
    cin >> T >> N;
    set<double> weights;
    FOR(i, 0, N) {
        int w;
        cin >> w;
        weights.insert(w);
    }
    int ans = 0;
    double goal = (*weights.begin()) / T;
    for (auto &it : weights) {
        ans += max(0.0, it / goal - 1);
    }
    cout << ans << '\n';
    cout.flush();
    return 0;
}
