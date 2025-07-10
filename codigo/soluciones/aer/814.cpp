#include <bits/stdc++.h>
using namespace std;
#define GL(s) getline(cin, s)
#define pb push_back
#define mp make_pair
#define SZ(c) ((int)(c).size())
int vtoi(const vector<int>& v) {
    if (v[0] != 0) return v[0] == 1 ? 0 : 1;
    if (v[1] != 0) return v[1] == 1 ? 2 : 3;
    return v[2] == 1 ? 4 : 5;
}
vector<int> rotate(const vector<int> &orientation, int di, int dj) {
    vector<int> ans = orientation;
    if (di == 1) {
        ans[1] = orientation[2];
        ans[2] = -orientation[1];
    }else if (di == -1) {
        ans[1] = -orientation[2];
        ans[2] = orientation[1];
    }else if (dj == 1) {
        ans[0] = orientation[2];
        ans[2] = -orientation[0];
    }else {
        ans[0] = -orientation[2];
        ans[2] = orientation[0];
    }
    return ans;
}
pair<int, int> bfs(int i1, int j1, int i2, int j2, int ty, int tx, const vector<vector<vector<pair<int, int>>>> &AL) {
    pair<int, int> ans = mp(-1, -1);
    queue<pair<pair<int, int>, vector<int>>> q;
    vector<int> aux(3);
    aux[2] = -1;
    q.push(mp(mp(i1, j1), aux));
    q.push(mp(mp(-1, -1), vector<int>()));
    vector<vector<vector<bool>>> visited(ty, vector<vector<bool>>(tx, vector<bool>(6)));
    int cnt = 0;
    while (SZ(q) > 1) {
        int i = q.front().first.first;
        int j = q.front().first.second;
        vector<int> orientation = q.front().second;
        q.pop();
        if (i == -1) {
            q.push(mp(mp(-1, -1), vector<int>()));
            ++cnt;
            continue;
        }
        if (visited[i][j][vtoi(orientation)]) continue;
        visited[i][j][vtoi(orientation)] = true;
        if (i == i2 && j == j2 && ans.first == -1) {
            ans.first = cnt;
        }
        if (i == i2 && j == j2 && orientation[2] == -1 && ans.second == -1) {
            ans.second = cnt;
            return ans;
        }
        for (auto &it : AL[i][j]) {
            vector<int> newOrientation = rotate(orientation, it.first - i, it.second - j);
            if (visited[it.first][it.second][vtoi(newOrientation)]) continue;
            q.push(mp(it, newOrientation));
        }
    }
    return ans;
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int tx, ty;
    while (cin >> tx >> ty, tx || ty) {
        vector<string> grid(2 * ty + 1);
        GL(grid[0]);
        for (auto &it : grid) {
            GL(it);
        }
        int i1, j1, i2, j2;
        for (int i = 1; i < 2 * ty + 1; i += 2) {
            for (int j = 1; j < 2 * tx + 1; j += 2) {
                if (grid[i][j] == 'O') {
                    i1 = i / 2;
                    j1 = j / 2;
                    grid[i][j] = ' ';
                }else if (grid[i][j] == 'D') {
                    i2 = i / 2;
                    j2 = j / 2;
                    grid[i][j] = ' ';
                }
            }
        }
        vector<vector<vector<pair<int, int>>>> AL(ty, vector<vector<pair<int, int>>>(tx));
        for (int i = 1; i < 2 * ty + 1; i += 2) {
            for (int j = 1; j < 2 * tx + 1; j += 2) {
                for (int d = -1; d <= 1; d += 2) {
                    if (grid[i + d][j] == ' ') {
                        AL[i / 2][j / 2].pb(mp(i / 2 + d, j / 2));
                    }
                    if (grid[i][j + d] == ' ') {
                        AL[i / 2][j / 2].pb(mp(i / 2, j / 2 + d));
                    }
                }
            }
        }
        pair<int, int> ans = bfs(i1, j1, i2, j2, ty, tx, AL);
        if (ans.first == -1) {
            cout << "IMPOSIBLE IMPOSIBLE\n";
            continue;
        }
        cout << ans.first << ' ';
        if (ans.second == -1) {
            cout << "IMPOSIBLE";
        }else {
            cout << ans.second;
        }
        cout << '\n';
    }
    cout.flush();
    return 0;
}
