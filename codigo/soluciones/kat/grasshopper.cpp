#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a, b)
#define SZ(c) ((int)(c).size())
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int R, C, a, b, c, d;
    while (cin >> R >> C >> a >> b >> c >> d) {
        --a;
        --b;
        --c;
        --d;
        queue<pair<int, int>> q;
        q.push(mp(a, b));
        q.push(mp(-1, -1));
        vector<vector<int>> dist(R, vector<int>(C, -1));
        int aux = 0;
        while (SZ(q) > 1) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if (i == -1 && j == -1) {
                ++aux;
                q.push(mp(-1, -1));
                continue;
            }
            if (dist[i][j] != -1) continue;
            dist[i][j] = aux;
            for (int d1 = -2; d1 <= 2; d1 += 4) {
                for (int d2 = -1; d2 <= 1; d2 += 2) {
                    if (i + d1 >= 0 && i + d1 < R && j + d2 >= 0 && j + d2 < C && dist[i + d1][j + d2] == -1) {
                        q.push(mp(i + d1, j + d2));
                    }
                    if (i + d2 >= 0 && i + d2 < R && j + d1 >= 0 && j + d1 < C && dist[i + d2][j + d1] == -1) {
                        q.push(mp(i + d2, j + d1));
                    }
                }
            }
        }
        if (dist[c][d] == -1) {
            cout << "impossible\n";
        }else {
            cout << dist[c][d] << '\n';
        }
    }
    cout.flush();
    return 0;
}
