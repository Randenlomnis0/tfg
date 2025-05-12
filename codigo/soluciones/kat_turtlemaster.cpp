#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define RFOR(i,j,k) for (int i = j - 1; i >= k; --i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> board(8);
    for (auto &it : board) {
        cin >> it;
    }
    string cmd;
    cin >> cmd;
    int i = 7, j = 0, di = 0, dj = 1;
    bool bug = false;
    for (auto &it : cmd) {
        if (bug) break;
        if (it == 'F') {
            i += di;
            j += dj;
            if (i < 0 || i >= 8 || j < 0 || j >= 8 || board[i][j] == 'C' || board[i][j] == 'I') {
                bug = true;
            }
        }else if (it == 'X') {
            int auxi = i + di, auxj = j + dj;
            if (auxi < 0 || auxi >= 8 || auxj < 0 || auxj >= 8 || board[auxi][auxj] != 'I') {
                bug = true;
            }else {
                board[auxi][auxj] = '.';
            }
        }else {
            int aux = di;
            if (it == 'L') {
                di = -dj;
                dj = aux;
            }else {
                di = dj;
                dj = -aux;
            }
        }
    }
    if (bug || board[i][j] != 'D') {
        cout << "Bug!\n";
    }else {
        cout << "Diamond!\n";
    }
    cout.flush();
    return 0;
}
