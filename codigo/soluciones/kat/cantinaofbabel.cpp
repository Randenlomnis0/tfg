#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define GL(s) getline(cin, s)
#define LEN(s) ((int)(s).length())
#define pb(x) push_back(x)
#define ALL(c) (c).begin(), (c).end()
#define MAX(a,b) a = max(a, b)
void dfs1(const string& s, unordered_map<string, unordered_set<string>>& AL, unordered_set<string>& visited, vector<string>& ts) {
    visited.insert(s);
    for (auto &it : AL[s]) {
        if (visited.count(it)) continue;
        dfs1(it, AL, visited, ts);
    }
    ts.pb(s);
}
int dfs2(const string &s, unordered_map<string, unordered_set<string>>& AL_T, unordered_set<string>& visited, unordered_map<string, int>& w) {
    visited.insert(s);
    int ans = w[s];
    for (auto &it : AL_T[s]) {
        if (visited.count(it)) continue;
        ans += dfs2(it, AL_T, visited, w);
    }
    return ans;
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    unordered_map<string, unordered_set<string>> AL, AL_T;
    unordered_map<string, int> w;
    FOR(k, 0, N) {
        string speak;
        cin >> speak >> speak;
        string line;
        GL(line);
        int i = 1;
        while (i < LEN(line)) {
            int j = i;
            string understand = "";
            while (j < LEN(line) && line[j] != ' ') {
                understand += line[j];
                ++j;
            }
            AL[understand].insert(speak);
            AL_T[speak].insert(understand);
            i = j + 1;
        }
        ++w[speak];
    }
    vector<string> ts;
    unordered_set<string> visited;
    for (auto &it : AL) {
        if (visited.count(it.first)) continue;
        dfs1(it.first, AL, visited, ts);
    }
    reverse(ALL(ts));
    int ans = 0;
    visited.clear();
    for (auto &it : ts) {
        if (visited.count(it)) continue;
        MAX(ans, dfs2(it, AL_T, visited, w));
    }
    cout << N - ans << '\n';
    cout.flush();
    return 0;
}
