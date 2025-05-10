#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> board(5);
    for (auto &it : board) {
        cin >> it;
    }
    bool valid = true;
    int knights = 0;
    FOR(i, 0, 5) {
        FOR(j, 0, 5) {
            if (board[i][j] == '.') continue;
            ++knights;
            for (int p = -2; p <= 2; p += 4) {
                for (int q = -1; q <= 1; q += 2) {
                    if (i + p >= 0 && i + p < 5 && j + q >= 0 && j + q < 5 && board[i + p][j + q] == 'k') {
                        valid = false;
                    }
                }
            }
            for (int p = -1; p <= 1; p += 2) {
                for (int q = -2; q <= 2; q += 4) {
                    if (i + p >= 0 && i + p < 5 && j + q >= 0 && j + q < 5 && board[i + p][j + q] == 'k') {
                        valid = false;
                    }
                }
            }
        }
    }
    if (!valid || knights != 9) cout << "in";
    cout << "valid\n";
    cout.flush();
    return 0;
}
