#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define RFOR(i,j,k) for (int i = j - 1; i >= k; --i)
#define MIN(a,b) a = min(a, b)
#define LEN(s) ((int)(s).length())
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int F, C, N;
    while (cin >> F >> C >> N, F || C || N) {
        vector<string> teclado(F);
        unordered_set<char> chars;
        for (auto &it : teclado) {
            cin >> it;
            for (auto &c : it) {
                chars.insert(c);
            }
        }
        unordered_map<char, int> mini, minj, maxi, maxj;
        FOR(i, 0, F) {
            FOR(j, 0, C) {
                maxi[teclado[i][j]] = i;
                maxj[teclado[i][j]] = j;
            }
        }
        RFOR(i, F, 0) {
            RFOR(j, C, 0) {
                mini[teclado[i][j]] = i;
                minj[teclado[i][j]] = j;
            }
        }
        unordered_map<char, unordered_map<char, int>> dist;
        for (auto &c1 : chars) {
            for (auto &c2 : chars) {
                dist[c1][c2] = 10000;
            }
        }
        for (auto &c : chars) {
            dist[c][teclado[(mini[c] - 1 + F)%F][minj[c]]] = 1;
            dist[c][teclado[(maxi[c] + 1)%F][minj[c]]] = 1;
            dist[c][teclado[mini[c]][(minj[c] - 1 + C)%C]] = 1;
            dist[c][teclado[mini[c]][(maxj[c] + 1)%C]] = 1;
            dist[c][c] = 0;
        }
        for (auto &c3 : chars) {
            for (auto &c1 : chars) {
                for (auto &c2 : chars) {
                    MIN(dist[c1][c2], dist[c1][c3] + dist[c3][c2]);
                }
            }
        }
        while (N--) {
            string s;
            cin >> s;
            int ans = dist[teclado[0][0]][s[0]];
            FOR(i, 1, LEN(s)) {
                ans += dist[s[i - 1]][s[i]];
            }
            cout << ans << '\n';
        }
        cout << "---\n";
    }
    cout.flush();
    return 0;
}
