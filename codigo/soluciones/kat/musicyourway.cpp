#include <bits/stdc++.h>
using namespace std;
#define GL(s) getline(cin, s)
#define pb(x) push_back(x)
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define SZ(c) ((int)(c).size())
#define ALL(c) (c).begin(), (c).end()
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    string line;
    GL(line);
    vector<string> attributes;
    while (line.find(' ') != string::npos) {
        attributes.pb(line.substr(0, line.find(' ')));
        line = line.substr(line.find(' ') + 1);
    }
    attributes.pb(line);
    int m, n = SZ(attributes);
    cin >> m;
    vector<vector<string>> data(m, vector<string>(n));
    FOR(i, 0, m) {
        FOR(j, 0, n) {
            cin >> data[i][j];
        }
    }
    int k;
    cin >> k;
    bool first = true;
    while (k--) {
        if (!first) cout << '\n';
        else first = false;
        string query;
        cin >> query;
        int idx;
        FOR(i, 0, n) {
            if (query == attributes[i]) {
                idx = i;
            }
        }
        stable_sort(ALL(data), [idx](const vector<string>& a, const vector<string>& b) {
            return a[idx] < b[idx];
        });
        bool ffirst = true;
        for (auto &it : attributes) {
            if (!ffirst) cout << ' ';
            else ffirst = false;
            cout << it;
        }
        cout << '\n';
        for (auto &it : data) {
            ffirst = true;
            for (auto &iit : it) {
                if (!ffirst) cout << ' ';
                else ffirst = false;
                cout << iit;
            }
            cout << '\n';
        }
    }
    cout.flush();
    return 0;
}
