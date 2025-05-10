#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
int calc(const vector<vector<int>>& flies, const int& i, const int& j, const int& K) {
    return flies[i][j] - flies[i - K][j] - flies[i][j - K] + flies[i - K][j - K];
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int R, S, K;
    cin >> R >> S >> K;
    vector<string> picture(R);
    vector<vector<int>> flies(R, vector<int>(S));
    FOR(i, 0, R) {
        cin >> picture[i];
        FOR(j, 0, S) {
            if (i > 0) flies[i][j] += flies[i - 1][j];
            if (j > 0) flies[i][j] += flies[i][j - 1];
            if (i > 0 && j > 0) flies[i][j] -= flies[i - 1][j - 1];
            flies[i][j] += picture[i][j] == '*';
        }
    }
    int ans = -1, ansi, ansj;
    FOR(i, K - 1, R) {
        FOR(j, K - 1, S) {
            int aux = calc(flies, i - 1, j - 1, K - 2);
            if (aux > ans) {
                ans = aux;
                ansi = i;
                ansj = j;
            }
        }
    }
    cout << ans << '\n';
    FOR(i, 0, K) {
        picture[ansi - i][ansj] = '|';
        picture[ansi - i][ansj - K + 1] = '|';
        picture[ansi][ansj - i] = '-';
        picture[ansi - K + 1][ansj - i] = '-';
    }
    picture[ansi - K + 1][ansj - K + 1] = '+';
    picture[ansi - K + 1][ansj] = '+';
    picture[ansi][ansj - K + 1] = '+';
    picture[ansi][ansj] = '+';
    for (auto &it : picture) {
        cout << it << '\n';
    }
    cout.flush();
    return 0;
}
