#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        vector<string> grid(8, string(8, ' '));
        int i = 0, j = 0;
        for (auto &it : s) {
            if (it == '/') {
                ++i;
                j = 0;
            }else if ((it >= 'a' && it <= 'z') || (it >= 'A' && it <= 'Z')) {
                grid[i][j++] = it;
            }else {
                j += it - '0';
            }
        }
        FOR(i, 0, 8) {
            FOR(j, 0, 8) {
                if (grid[i][j] == ' ' || grid[i][j] == '+') continue;
                if (grid[i][j] == 'p') {
                    if (i + 1 >= 8) continue;
                    for (int d = -1; d <= 1; d += 2) {
                        if (j + d < 0 || grid[i + 1][j + d] != ' ') continue;
                        grid[i + 1][j + d] = '+';
                    }
                }else if (grid[i][j] == 'P') {
                    if (i - 1 < 0) continue;
                    for (int d = -1; d <= 1; d += 2) {
                        if (j + d < 0 || grid[i - 1][j + d] != ' ') continue;
                        grid[i - 1][j + d] = '+';
                    }
                }else if (tolower(grid[i][j]) == 'n') {
                    for (int dp = -2; dp <= 2; dp += 4) {
                        for (int dq = -1; dq <= 1; dq += 2) {
                            if (i + dp >= 0 && i + dp < 8 && j + dq >= 0 && j + dq < 8 && (grid[i + dp][j + dq] == ' ' || grid[i + dp][j + dq] == '+')) {
                                grid[i + dp][j + dq] = '+';
                            }
                            if (i + dq >= 0 && i + dq < 8 && j + dp >= 0 && j + dp < 8 && (grid[i + dq][j + dp] == ' ' || grid[i + dq][j + dp] == '+')) {
                                grid[i + dq][j + dp] = '+';
                            }
                        }
                    }
                }else if (tolower(grid[i][j]) == 'r') {
                    for (int d = -1; d <= 1; d += 2) {
                        for (int p = i + d; p >= 0 && p < 8; p += d) {
                            if (grid[p][j] != ' ' && grid[p][j] != '+') break;
                            grid[p][j] = '+';
                        }
                        for (int q = j + d; q >= 0 && q < 8; q += d) {
                            if (grid[i][q] != ' ' && grid[i][q] != '+') break;
                            grid[i][q] = '+';
                        }
                    }
                }else if (tolower(grid[i][j]) == 'b') {
                    for (int dp = -1; dp <= 1; dp += 2) {
                        for (int dq = -1; dq <= 1; dq += 2) {
                            for (int p = i + dp, q = j + dq; p >= 0 && p < 8 && q >= 0 && q < 8; p += dp, q += dq) {
                                if (grid[p][q] != ' ' && grid[p][q] != '+') break;
                                grid[p][q] = '+';
                            }
                        }
                    }
                }else if (tolower(grid[i][j]) == 'q') {
                    for (int dp = -1; dp <= 1; ++dp) {
                        for (int dq = -1; dq <= 1; ++dq) {
                            if (dp == 0 && dq == 0) continue;
                            for (int p = i + dp, q = j + dq; p >= 0 && p < 8 && q >= 0 && q < 8; p += dp, q += dq) {
                                if (grid[p][q] != ' ' && grid[p][q] != '+') break;
                                grid[p][q] = '+';
                            }
                        }
                    }
                }else if (tolower(grid[i][j]) == 'k') {
                    for (int dp = -1; dp <= 1; ++dp) {
                        for (int dq = -1; dq <= 1; ++dq) {
                            if (i + dp < 0 || i + dp >= 8 || j + dq < 0 || j + dq >= 8 || (dp == 0 && dq == 0) || (grid[i + dp][j + dq] != ' ' && grid[i + dp][j + dq] != '+')) continue;
                            grid[i + dp][j + dq] = '+';
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (auto &it : grid) {
            for (auto &iit : it) {
                ans += (iit == ' ');
            }
        }
        cout << ans << '\n';
    }
    cout.flush();
    return 0;
}
