#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
bool possible(const vector<string>& board, vector<string>& aux, const char& turn) {
    bool equal = true;
    char next_turn = (turn == 'X' ? 'O' : 'X');
    bool tres_en_raya = false;
    FOR(i, 0, 3) {
        tres_en_raya |= (aux[i][0] != '.' && aux[i][0] == aux[i][1] && aux[i][0] == aux[i][2]);
        tres_en_raya |= (aux[0][i] != '.' && aux[0][i] == aux[1][i] && aux[0][i] == aux[2][i]);
    }
    tres_en_raya |= (aux[0][0] != '.' && aux[0][0] == aux[1][1] && aux[0][0] == aux[2][2]);
    tres_en_raya |= (aux[0][2] != '.' && aux[0][2] == aux[1][1] && aux[0][2] == aux[2][0]);
    FOR(i, 0, 3) {
        FOR(j, 0, 3) {
            if (board[i][j] != aux[i][j]) {
                equal = false;
                if (!tres_en_raya && board[i][j] == turn) {
                    aux[i][j] = turn;
                    if (possible(board, aux, next_turn)) return true;
                    aux[i][j] = '.';
                }
            }
        }
    }
    return equal;
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    while (N--) {
        vector<string> board(3), aux(3, string(3, '.'));
        for (auto &it : board) {
            cin >> it;
        }
        cout << (possible(board, aux, 'X') ? "yes" : "no") << '\n';
    }
    cout.flush();
    return 0;
}
