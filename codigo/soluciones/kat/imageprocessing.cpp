#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int H, W, N, M;
    cin >> H >> W >> N >> M;
    vector<vector<int>> image(H, vector<int>(W));
    for (auto &it : image) {
        for (auto &iit : it) {
            cin >> iit;
        }
    }
    vector<vector<int>> kernel(N, vector<int>(M));
    for (auto &it : kernel) {
        for (auto &iit : it) {
            cin >> iit;
        }
    }
    vector<vector<int>> ans(H - N + 1, vector<int>(W - M + 1));
    FOR(i, 0, H - N + 1) {
        FOR(j, 0, W - M + 1) {
            FOR(p, 0, N) {
                FOR(q, 0, M) {
                    ans[i][j] += image[i + p][j + q] * kernel[N - 1 - p][M - 1 - q];
                }
            }
        }
    }
    for (auto &it : ans) {
        bool first = true;
        for (auto &iit : it) {
            if (!first) cout << ' ';
            else first = false;
            cout << iit;
        }
        cout << '\n';
    }
    cout.flush();
    return 0;
}
