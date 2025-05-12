#include <bits/stdc++.h>
using namespace std;
#define GL(s) getline(cin, s)
#define LEN(s) ((int)(s).length())
#define ALL(c) (c).begin(), (c).end()
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> board(8, string(8, ' '));
    string moves;
    GL(moves);
    if (moves != "White: ") {
        moves = moves.substr(moves.find(' ') + 1);
        while (moves.find(',') != string::npos) {
            string move = moves.substr(0, moves.find(','));
            moves = moves.substr(moves.find(',') + 1);
            if (LEN(move) == 2) {
                move = "P" + move;
            }
            board[move[2] - '1'][move[1] - 'a'] = move[0];
        }
        if (LEN(moves) == 2) {
            moves = "P" + moves;
        }
        board[moves[2] - '1'][moves[1] - 'a'] = moves[0];
    }
    GL(moves);
    if (moves != "Black: ") {
        moves = moves.substr(moves.find(' ') + 1);
        while (moves.find(',') != string::npos) {
            string move = moves.substr(0, moves.find(','));
            moves = moves.substr(moves.find(',') + 1);
            if (LEN(move) == 2) {
                move = "P" + move;
            }
            move[0] = tolower(move[0]);
            board[move[2] - '1'][move[1] - 'a'] = move[0];
        }
        if (LEN(moves) == 2) {
            moves = "P" + moves;
        }
        moves[0] = tolower(moves[0]);
        board[moves[2] - '1'][moves[1] - 'a'] = moves[0];
    }
    reverse(ALL(board));
    cout << "+---+---+---+---+---+---+---+---+\n";
    int i = 0, j = 0;
    for (auto &it : board) {
        cout << '|';
        for (auto &iit : it) {
            char fill = ((i + j)%2 != 0 ? ':' : '.');
            cout << fill << (iit != ' ' ? iit : fill) << fill << '|';
            ++j;
        }
        cout << "\n+---+---+---+---+---+---+---+---+\n";
        ++i;
        j = 0;
    }
    cout.flush();
    return 0;
}
