#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a, b)
int ffill(vector<vector<int>> &grid, const int &i, const int &j, const int &N) {
    grid[i][j] = -1;
    int ans = 0;
    for (int d = -1; d <= 1; d += 2) {
        if (i + d >= 0 && i + d < N) {
            if (grid[i + d][j] == 0) {
                ans += ffill(grid, i + d, j, N);
            }else if (grid[i + d][j] == 1) {
                ++ans;
            }
        }
        if (j + d >= 0 && j + d < N) {
            if (grid[i][j + d] == 0) {
                ans += ffill(grid, i, j + d, N);
            }else if (grid[i][j + d] == 1) {
                ++ans;
            }
        }
        if (i + d >= 0 && i + d < N && j + d >= 0 && j + d < N) {
            if (grid[i + d][j + d] == 0) {
                ans += ffill(grid, i + d, j + d, N);
            }else if (grid[i + d][j + d] == 1) {
                ++ans;
            }
        }
    }
    return ans;
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int R, K;
    cin >> R >> K;
    vector<vector<int>> grid(2 * R + 1, vector<int>(2 * R + 1));
    unordered_map<int, pair<int, int>> pos;
    int aux = 1;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < R + i; ++j) {
            pos[aux++] = mp(i + 1, j + 1);
        }
    }
    for (int i = R; i < 2 * R - 1; ++i) {
        for (int j = i - R + 1; j < 2 * R - 1; ++j) {
            pos[aux++] = mp(i + 1, j + 1);
        }
    }
    while (K--) {
        int idx;
        cin >> idx;
        grid[pos[idx].first][pos[idx].second] = 1;
    }
    cout << ffill(grid, 0, 0, 2 * R + 1) << '\n';
    cout.flush();
    return 0;
}
