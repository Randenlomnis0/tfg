#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define MIN(a,b) a = min(a, b)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int C;
    while (cin >> C, C) {
        vector<string> name(C);
        unordered_map<string, int> id;
        FOR(i, 0, C) {
            cin >> name[i];
            id[name[i]] = i;
        }
        int R;
        cin >> R;
        vector<vector<double>> AM(C, vector<double>(C, 1e9));
        while (R--) {
            string s1, s2, s3;
            cin >> s1 >> s2 >> s3;
            double a = stod(s3.substr(0, s3.find(':'))), b = stod(s3.substr(s3.find(':') + 1));
            MIN(AM[id[s1]][id[s2]], b / a);
        }
        FOR(k, 0, C) {
            FOR(i, 0, C) {
                FOR(j, 0, C) {
                    if (AM[i][k] == 1e9 || AM[k][j] == 1e9) continue;
                    MIN(AM[i][j], AM[i][k] * AM[k][j]);
                }
            }
        }
        bool ans = false;
        FOR(k, 0, C) {
            if (AM[k][k] <= 1.0) continue;
            ans = true;
            break;
        }
        cout << (ans ? "Arbitrage" : "Ok") << '\n';
    }
    cout.flush();
    return 0;
}
