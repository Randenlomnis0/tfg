#include <bits/stdc++.h>
using namespace std;
#define ALL(c) (c).begin(), (c).end()
#define LEN(s) ((int)(s).length())
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    bool first = true;
    while (cin >> n, n) {
        vector<string> names(n);
        for (auto &it : names) {
            cin >> it;
        }
        stable_sort(ALL(names), [](const string& a, const string& b) {
            if (a[0] != b[0]) return a[0] < b[0];
            if (LEN(a) > 1 && LEN(b) > 1) {
                if (a[1] != b[1]) return a[1] < b[1];
                return false;
            }else if (LEN(a) > 1) {
                return false;
            }else if (LEN(b) > 1) {
                return true;
            }
            return false;
        });
        if (!first) cout << '\n';
        else first = false;
        for (auto &it : names) {
            cout << it << '\n';
        }
    }
    cout.flush();
    return 0;
}
