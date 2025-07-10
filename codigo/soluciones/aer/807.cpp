#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define MAX(a,b) a = max(a, b)
int solve(int Q, int R, int N, int i, int cols, int diags1, int diags2, vector<int> &diags3, vector<int> &diags4, const vector<vector<int>> &board) {
    if (i == N) return 0;
    int ans = INT_MIN;
    FOR(j, 0, N) {
        if (Q > 0 && (cols & (1<<j)) && diags3[N + j - i - 1] == 0 && diags4[i + j] == 0) {
            cols &= ~(1<<j);
            diags1 &= ~(1<<(N + j - i - 1));
            diags2 &= ~(1<<(i + j));
            ++diags3[N + j - i - 1];
            ++diags4[i + j];
            int aux = solve(Q - 1, R, N, i + 1, cols, diags1, diags2, diags3, diags4, board);
            if (aux != INT_MIN) MAX(ans, board[i][j] + aux);
            cols |= (1<<j);
            diags1 |= (1<<(N + j - i - 1));
            diags2 |= (1<<(i + j));
            --diags3[N + j - i - 1];
            --diags4[i + j];
        }
        if (R > 0 && (cols & (1<<j)) && (diags1 & (1<<(N + j - i - 1))) && (diags2 & (1<<(i + j)))) {
            cols &= ~(1<<j);
            ++diags3[N + j - i - 1];
            ++diags4[i + j];
            int aux = solve(Q, R - 1, N, i + 1, cols, diags1, diags2, diags3, diags4, board);
            if (aux != INT_MIN) MAX(ans, board[i][j] + aux);
            cols |= (1<<j);
            --diags3[N + j - i - 1];
            --diags4[i + j];
        }
    }
    return ans;
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int Q, R;
    while (cin >> Q >> R) {
        int N = Q + R;
        vector<vector<int>> board(N, vector<int>(N));
        for (auto &it : board) {
            for (auto &iit : it) {
                cin >> iit;
            }
        }
        vector<int> diags3(2 * N - 1), diags4(2 * N - 1);
        int ans = solve(Q, R, N, 0, (1<<N) - 1, (1<<(2 * N - 1)) - 1, (1<<(2 * N - 1)) - 1, diags3, diags4, board);
        cout << (ans == INT_MIN ? 0 : ans) << '\n';
    }
    cout.flush();
    return 0;
}
