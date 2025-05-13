#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define ALL(c) (c).begin(), (c).end()
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N, H;
    cin >> N >> H;
    vector<vector<int>> heights(2, vector<int>(N / 2));
    FOR(i, 0, N) {
        cin >> heights[i%2][i / 2];
    }
    for (auto &it : heights) {
        sort(ALL(it));
    }
    int ans = INT_MAX, cnt = 0;
    FOR(i, 0, H) {
        int aux = distance(lower_bound(ALL(heights[0]), i + 1), heights[0].end()) + distance(lower_bound(ALL(heights[1]), H - i), heights[1].end());
        if (aux < ans) {
            ans = aux;
            cnt = 1;
        }else if (aux == ans) {
            ++cnt;
        }
    }
    cout << ans << ' ' << cnt << '\n';
    cout.flush();
    return 0;
}
