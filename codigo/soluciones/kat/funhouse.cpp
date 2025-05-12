#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int W, L, i = 0;
    while (cin >> W >> L, W || L) {
        ++i;
        cout << "HOUSE " << i << '\n';
        vector<string> room(L);
        for (auto &it : room) {
            cin >> it;
        }
        int a, b, c, d;
        for (int j = 0; j < W; ++j) {
            if (room[0][j] == '*') {
                a = 0;
                b = j;
                c = 1;
                d = 0;
            }else if (room[L - 1][j] == '*') {
                a = L - 1;
                b = j;
                c = -1;
                d = 0;
            }
        }
        for (int j = 0; j < L; ++j) {
            if (room[j][0] == '*') {
                a = j;
                b = 0;
                c = 0;
                d = 1;
            }else if (room[j][W - 1] == '*') {
                a = j;
                b = W - 1;
                c = 0;
                d = -1;
            }
        }
        do {
            a += c;
            b += d;
            if (room[a][b] == '/') {
                if (c == 1) {
                    c = 0;
                    d = -1;
                }else if (c == -1) {
                    c = 0;
                    d = 1;
                }else if (d == 1) {
                    c = -1;
                    d = 0;
                }else {
                    c = 1;
                    d = 0;
                }
            }else if (room[a][b] == '\\') {
                if (c == 1) {
                    c = 0;
                    d = 1;
                }else if (c == -1) {
                    c = 0;
                    d = -1;
                }else if (d == 1) {
                    c = 1;
                    d = 0;
                }else {
                    c = -1;
                    d = 0;
                }
            }
        }while (room[a][b] != 'x');
        room[a][b] = '&';
        for (auto &it : room) {
            cout << it << '\n';
        }
    }
    cout.flush();
    return 0;
}
