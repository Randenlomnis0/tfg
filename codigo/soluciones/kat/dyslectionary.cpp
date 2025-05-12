#include <bits/stdc++.h>
using namespace std;
#define GL(s) getline(cin, s)
#define pb(x) push_back(x)
#define ALL(c) (c).begin(), (c).end()
#define MAX(a,b) a = max(a, b)
#define LEN(s) ((int)(s).length())
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    string line;
    bool first = true;
    while (GL(line)) {
        vector<string> lines;
        int longest = 0;
        while (line != "") {
            MAX(longest, LEN(line));
            reverse(ALL(line));
            lines.pb(line);
            GL(line);
        }
        sort(ALL(lines));
        if (!first) cout << '\n';
        else first = false;
        for (auto &it : lines) {
            reverse(ALL(it));
            cout << string(longest - LEN(it), ' ') << it << '\n';
        }
    }
    cout.flush();
    return 0;
}
