#include <bits/stdc++.h>
using namespace std;
#define GL(s) getline(cin, s)
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define LEN(s) ((int)(s).length())
#define pb(x) push_back(x)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    string line;
    GL(line);
    vector<string> board(8);
    for (auto &it : board) {
        GL(line);
        FOR(i, 0, 8) {
            it += line[2 + i * 4];
        }
        GL(line);
    }
    set<string> white, black;
    FOR(i, 0, 8) {
        FOR(j, 0, 8) {
            if (board[i][j] == '.' || board[i][j] == ':') continue;
            if (isupper(board[i][j])) {
                white.insert((board[i][j] != 'P' ? string(1, board[i][j]) : "") + string(1, '8' - i) + string(1, j + 'a'));
            }else {
                black.insert((board[i][j] != 'p' ? string(1, toupper(board[i][j])) : "") + string(1, i + '1') + string(1, j + 'a'));
            }
        }
    }
    string prio = "KQRBN";
    vector<string> w, b;
    for (auto &it : prio) {
        for (auto &iit : white) {
            if (LEN(iit) != 3 || iit[0] != it) continue;
            w.pb(string(1, iit[0]) + string(1, iit[2]) + string(1, iit[1]));
        }
        for (auto &iit : black) {
            if (LEN(iit) != 3 || iit[0] != it) continue;
            b.pb(string(1, iit[0]) + string(1, iit[2]) + string(1, '8' - (iit[1] - '1')));
        }
    }
    for (auto &iit : white) {
        if (LEN(iit) == 3) continue;
        w.pb(string(1, iit[1]) + string(1, iit[0]));
    }
    for (auto &iit : black) {
        if (LEN(iit) == 3) continue;
        b.pb(string(1, iit[1]) + string(1, '8' - (iit[0] - '1')));
    }
    cout << "White: ";
    bool first = true;
    for (auto &it : w) {
        if (!first) cout << ',';
        else first = false;
        cout << it;
    }
    cout << '\n';
    cout << "Black: ";
    first = true;
    for (auto &it : b) {
        if (!first) cout << ',';
        else first = false;
        cout << it;
    }
    cout << '\n';
    cout.flush();
    return 0;
}
