#include <bits/stdc++.h>
using namespace std;
#define GL(s) getline(cin, s)
#define LEN(s) ((int)(s).length())
#define pb(x) push_back(x)
#define ALL(c) (c).begin(), (c).end()
void dfs(const string& changed, unordered_map<string, vector<string>>& AL, vector<string>& ts, unordered_set<string>& visited) {
    visited.insert(changed);
    for (auto &it : AL[changed]) {
        if (visited.count(it)) continue;
        dfs(it, AL, ts, visited);
    }
    ts.pb(changed);
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    unordered_map<string, vector<string>> AL;
    string aux;
    GL(aux);
    while (n--) {
        GL(aux);
        int i = aux.find(':');
        string key = aux.substr(0, i);
        i += 2;
        while (i < LEN(aux)) {
            int j = i;
            string token = "";
            while (j < LEN(aux) && aux[j] != ' ') {
                token += aux[j];
                ++j;
            }
            AL[token].pb(key);
            i = j + 1;
        }
    }
    string changed;
    cin >> changed;
    vector<string> ts;
    unordered_set<string> visited;
    dfs(changed, AL, ts, visited);
    reverse(ALL(ts));
    for (auto &it : ts) {
        cout << it << '\n';
    }
    cout.flush();
    return 0;
}
