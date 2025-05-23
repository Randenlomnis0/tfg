#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a, b)
#define pb(x) push_back(x)
#define MAX(a,b) a = max(a, b)
#define MIN(a,b) a = min(a, b)
int dfs(const int& i, const int& j, map<pair<int, int>, vector<pair<pair<int, int>, int>>>& AL, const int& M, const int& N) {
    int ans = INT_MAX;
    if (i == M - 1 && j == N - 1) {
        return 0;
    }
    for (auto &it : AL[mp(i, j)]) {
        int aux = dfs(it.first.first, it.first.second, AL, M, N);
        if (aux != INT_MAX) {
            MAX(aux, it.second);
        }
        MIN(ans, aux);
    }
    return ans;
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int M, N;
    cin >> M >> N;
    vector<vector<int>> heights(M, vector<int>(N));
    for (auto &it : heights) {
        for (auto &iit : it) {
            cin >> iit;
        }
    }
    priority_queue<pair<int, pair<pair<int, int>, pair<int, int>>>> pq;
    if (M > 1) {
        pq.push(mp(-max(0, heights[1][0] - heights[0][0]), mp(mp(1, 0), mp(0, 0))));
    }
    if (N > 1) {
        pq.push(mp(-max(0, heights[0][1] - heights[0][0]), mp(mp(0, 1), mp(0, 0))));
    }
    vector<vector<bool>> visited(M, vector<bool>(N));
    visited[0][0] = true;
    map<pair<int, int>, vector<pair<pair<int, int>, int>>> AL;
    while (!visited[M - 1][N - 1]) {
        int h = -pq.top().first;
        int i = pq.top().second.first.first;
        int j = pq.top().second.first.second;
        int pi = pq.top().second.second.first;
        int pj = pq.top().second.second.second;
        pq.pop();
        if (visited[i][j]) continue;
        AL[mp(pi, pj)].pb(mp(mp(i, j), h));
        visited[i][j] = true;
        for (int d = -1; d <= 1; d += 2) {
            if (i + d < 0 || i + d >= M || visited[i + d][j]) continue;
            pq.push(mp(-max(0, heights[i + d][j] - heights[i][j]), mp(mp(i + d, j), mp(i, j))));
        }
        for (int d = -1; d <= 1; d += 2) {
            if (j + d < 0 || j + d >= N || visited[i][j + d]) continue;
            pq.push(mp(-max(0, heights[i][j + d] - heights[i][j]), mp(mp(i, j + d), mp(i, j))));
        }
    }
    cout << dfs(0, 0, AL, M, N) << '\n';
    cout.flush();
    return 0;
}
