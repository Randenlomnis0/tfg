#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define ALL(c) (c).begin(), (c).end()
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> plots(N);
    for (auto &it : plots) {
        cin >> it;
        it *= it;
        it *= 2;
    }
    sort(ALL(plots));
    vector<int> houses(M + K);
    FOR(i, 0, M) {
        cin >> houses[i];
        houses[i] *= houses[i];
        houses[i] *= 2;
    }
    FOR(i, 0, K) {
        cin >> houses[M + i];
        houses[M + i] = houses[M + i] * houses[M + i];
    }
    sort(ALL(houses));
    int ans = 0;
    FOR(i, 0, N) {
        if (i >= M + K) break;
        ans += (houses[i] <= plots[i]);
    }
    cout << ans << '\n';
    cout.flush();
    return 0;
}
