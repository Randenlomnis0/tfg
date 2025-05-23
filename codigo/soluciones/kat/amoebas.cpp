#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
void dfs(const int &i, const int &j, vector<string>& image, const int& m, const int& n) {
    image[i][j] = '.';
    for (int di = -1; di <= 1; ++di) {
        for (int dj = -1; dj <= 1; ++dj) {
            if (i + di < 0 || i + di >=m || j + dj < 0 || j + dj >= n || image[i + di][j + dj] == '.') continue;
            dfs(i + di, j + dj, image, m, n);
        }
    }
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n;
    cin >> m >> n;
    vector<string> image(m);
    for (auto &it : image) {
        cin >> it;
    }
    int ans = 0;
    FOR(i, 0, m) {
        FOR(j, 0, n) {
            if (image[i][j] == '.') continue;
            ++ans;
            dfs(i, j, image, m, n);
        }
    }
    cout << ans << '\n';
    cout.flush();
    return 0;
}
