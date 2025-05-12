#include <bits/stdc++.h>
using namespace std;
#define GL(s) getline(cin, s)
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define pb(x) push_back(x)
#define SZ(c) ((int)(c).size())
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int L;
    cin >> L;
    string line;
    GL(line);
    GL(line);
    vector<char> s;
    int ans = -1;
    unordered_map<char, char> m = {{')', '('}, {'}', '{'}, {']', '['}};
    FOR(i, 0, L) {
        if (line[i] == ' ') continue;
        if (line[i] == '(' || line[i] == '{' || line[i] == '[') {
            s.pb(line[i]);
        }else if (SZ(s) == 0 || s[SZ(s) - 1] != m[line[i]]) {
            ans = i;
            break;
        }else {
            s.pop_back();
        }
    }
    if (ans == -1) {
        cout << "ok so far\n";
    }else {
        cout << line[ans] << ' ' << ans << '\n';
    }
    cout.flush();
    return 0;
}
