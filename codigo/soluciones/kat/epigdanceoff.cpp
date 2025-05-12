#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<string> grid(N);
    for (auto &it : grid) {
        cin >> it;
    }
    int ans = 1;
    FOR(j, 0, M) {
        bool isEmpty = true;
        FOR(i, 0, N) {
            if (grid[i][j] == '_') continue;
            isEmpty = false;
            break;
        }
        ans += isEmpty;
    }
    cout << ans << '\n';
    cout.flush();
    return 0;
}
