#include <bits/stdc++.h>
using namespace std;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    unordered_set<char> solved;
    unordered_map<char, int> attempts;
    int ans = 0;
    while (cin >> t, t != -1) {
        char c;
        string s;
        cin >> c >> s;
        if (solved.count(c)) continue;
        if (s == "right") {
            ans += t;
            solved.insert(c);
        }else {
            ++attempts[c];
        }
    }
    for (auto &it : attempts) {
        if (!solved.count(it.first)) continue;
        ans += it.second * 20;
    }
    cout << solved.size() << ' ' << ans << '\n';
    cout.flush();
    return 0;
}
