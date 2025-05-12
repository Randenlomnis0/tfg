#include <bits/stdc++.h>
using namespace std;
#define GL(s) getline(cin, s)
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a, b)
#define FOR(i,j,k) for (int i = j; i < k; ++i)
int id(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'z') return '9' - '0' + 1 + c - 'a';
    return '9' - '0' + 1 + 'z' - 'a' + 1 + c - 'A';
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    string line;
    bool first = true;
    while (GL(line)) {
        vector<string> board(1, line);
        while (GL(line) && line != "") {
            board.pb(line);
        }
        int N = 0;
        for (auto &it : board) {
            for (auto &iit : it) {
                if (iit == '.') continue;
                ++N;
            }
        }
        vector<pair<int, int>> V(N);
        int i = 0;
        for (auto &it : board) {
            int j = 0;
            for (auto &iit : it) {
                ++j;
                if (iit == '.') continue;
                V[id(iit)] = mp(i, j - 1);
            }
            ++i;
        }
        FOR(i, 1, N) {
            if (V[i - 1].first == V[i].first) {
                FOR(j, min(V[i - 1].second, V[i].second), max(V[i - 1].second, V[i].second)) {
                    if (board[V[i].first][j] == '|') {
                        board[V[i].first][j] = '+';
                    }else if (board[V[i].first][j] == '.') {
                        board[V[i].first][j] = '-';
                    }
                }
            }else {
                FOR(j, min(V[i - 1].first, V[i].first), max(V[i - 1].first, V[i].first)) {
                    if (board[j][V[i].second] == '-') {
                        board[j][V[i].second] = '+';
                    }else if (board[j][V[i].second] == '.') {
                        board[j][V[i].second] = '|';
                    }
                }
            }
        }
        if (!first) cout << '\n';
        else first = false;
        for (auto &it : board) {
            cout << it << '\n';
        }
    }
    cout.flush();
    return 0;
}
