#include <bits/stdc++.h>
using namespace std;
#define GL(s) getline(cin, s)
#define pb(x) push_back(x)
#define SZ(c) ((int)(c).size())
#define LEN(s) ((int)(s).length())
#define RFOR(i,j,k) for (int i = j - 1; i >= k; --i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    string line;
    GL(line);
    while (T--) {
        GL(line);
        vector<string> ans(1);
        int i = 0;
        for (auto &it : line) {
            if (it == '[') {
                ans.pb("");
                i = SZ(ans) - 1;
            }else if (it == ']') {
                i = 0;
            }else if (it == '<') {
                if (LEN(ans[i])) {
                    ans[i].pop_back();
                }
            }else {
                ans[i] += it;
            }
        }
        RFOR(k, SZ(ans), 0) {
            cout << ans[k];
        }
        cout << '\n';
    }
    cout.flush();
    return 0;
}
