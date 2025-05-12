#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define GL(s) getline(cin, (s))
#define MAX(a,b) a = max(a, b)
#define MIN(a,b) a = min(a, b)
#define PB(x) push_back(x)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int c, f;
        cin >> c >> f;
        vector<string> nevera(f);
        GL(nevera[0]);
        FOR(i, 0, f) {
            GL(nevera[i]);
        }
        unordered_map<char, int> minF, maxF, minC, maxC;
        unordered_set<char> vals;
        FOR(i, 0, f) {
            FOR(j, 0, c) {
                if (nevera[i][j] == '.') continue;
                if (vals.count(nevera[i][j]) == 0) {
                    vals.insert(nevera[i][j]);
                    minF[nevera[i][j]] = INT_MAX;
                    maxF[nevera[i][j]] = -1;
                    minC[nevera[i][j]] = INT_MAX;
                    maxC[nevera[i][j]] = -1;
                }
                MIN(minF[nevera[i][j]], i);
                MAX(maxF[nevera[i][j]], i);
                MIN(minC[nevera[i][j]], j);
                MAX(maxC[nevera[i][j]], j);
            }
        }
        unordered_map<char, unordered_set<char>> adj;
        for (auto &a : vals) {
            for (auto &b : vals) {
                if (a == b) continue;
                if (minF[a] > maxF[b] || maxF[a] < minF[b] || minC[a] > maxC[b] || maxC[a] < minC[b]) continue;
                int i1 = max(minF[a], minF[b]);
                int i2 = min(maxF[a], maxF[b]);
                int j1 = max(minC[a], minC[b]);
                int j2 = min(maxC[a], maxC[b]);
                bool aSobreB = false, bSobreA = false;
                FOR(i, i1, i2 + 1) {
                    FOR(j, j1, j2 + 1) {
                        char ch = nevera[i][j];
                        if (ch == a) aSobreB = true;
                        if (ch == b) bSobreA = true;
                    }
                }
                if (aSobreB) adj[b].insert(a);
                if (bSobreA) adj[a].insert(b);
            }
        }
        vector<set<char>> ans;
        while (!vals.empty()) {
            set<char> quitados;
            for (auto &it : vals) {
                if (!adj[it].empty()) continue;
                quitados.insert(it);
            }
            if (quitados.empty()) break;
            for (auto &it : vals) {
                for (auto &iit : quitados) {
                    adj[it].erase(iit);
                }
            }
            for (auto &it : quitados) {
                vals.erase(it);
            }
            ans.PB(quitados);
        }
        if (!vals.empty()) {
            cout << "IMPOSIBLE\n";
        }else {
            for (auto &it : ans) {
                bool first = true;
                for (auto &iit : it) {
                    if (first) first = false;
                    else cout << ' ';
                    cout << iit;
                }
                cout << '\n';
            }
        }
        cout << "----\n";
    }
    cout.flush();
    return 0;
}