#include <bits/stdc++.h>
using namespace std;
#define ALL(c) (c).begin(), (c).end()
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define int long long
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> sticks(N);
    for (auto &it : sticks) {
        cin >> it;
    }
    sort(ALL(sticks));
    bool possible = false;
    FOR(i, 2, N) {
        if (sticks[i - 2] + sticks[i - 1] > sticks[i]) {
            possible = true;
            break;
        }
    }
    cout << (possible ? "possible" : "impossible") << '\n';
    cout.flush();
    return 0;
}
