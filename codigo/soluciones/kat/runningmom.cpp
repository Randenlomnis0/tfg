#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define SZ(c) ((int)(c).size())
void dfs(const string& s, unordered_map<string, vector<string>>& AL, unordered_map<string, int>& state) {
    state[s] = 1;
    for (auto &it : AL[s]) {
        if (state[it] == 1 || state[it] == 2) {
            state[s] = 2;
            continue;
        }
        dfs(it, AL, state);
        if (state[it] == 2) {
            state[s] = 2;
        }
    }
    if (state[s] == 1) {
        state[s] = 3;
    }
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    unordered_map<string, vector<string>> AL;
    unordered_map<string, int> state;
    while (n--) {
        string o, d;
        cin >> o >> d;
        AL[o].pb(d);
        state[o] = 0;
        state[d] = 0;
    }
    for (auto &it : AL) {
        if (state[it.first] != 0) continue;
        dfs(it.first, AL, state);
    }
    string name;
    while (cin >> name) {
        cout << name << ' ' << (state[name] == 2 ? "safe" : "trapped") << '\n';
    }
    cout.flush();
    return 0;
}
