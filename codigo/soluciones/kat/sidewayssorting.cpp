#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define ALL(c) (c).begin(), (c).end()
#define LEN(s) ((int)(s).length())
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int r, c;
    bool first = true;
    while (cin >> r >> c, r || c) {
        vector<string> in(r), out(c);
        for (auto &it : in) {
            cin >> it;
        }
        FOR(j, 0, c) {
            FOR(i, 0, r) {
                out[j] += in[i][j];
            }
        }
        sort(ALL(out), [](const string& a, const string& b) {
            int n = LEN(a);
            FOR(i, 0, n) {
                if (tolower(a[i]) != tolower(b[i])) return tolower(a[i]) < tolower(b[i]);
            }
            return false;
        });
        if (!first) cout << '\n';
        else first = false;
        FOR(i, 0, r) {
            in[i] = "";
            FOR(j, 0, c) {
                in[i] += out[j][i];
            }
            cout << in[i] << '\n';
        }
    }
    cout.flush();
    return 0;
}
