#include <bits/stdc++.h>
using namespace std;
#define ALL(c) (c).begin(), (c).end()
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define LEN(s) ((int)(s).length())
int contarIguales(const string &a, const string &b) {
    int i = 0;
    while (i < LEN(a) && i < LEN(b) && a[i] == b[i]) {
        ++i;
    }
    return i;
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n, n) {
        vector<string> hashes(n);
        for (auto &it : hashes) {
            cin >> it;
        }
        if (n == 1) {
            cout << "0\n";
            continue;
        }
        sort(ALL(hashes));
        int ans = 0;
        FOR(i, 0, n) {
            int l = ((i > 0) ? contarIguales(hashes[i], hashes[i - 1]) : 0);
            int r = ((i < n - 1) ? contarIguales(hashes[i], hashes[i + 1]) : 0);
            ans += 1 + max(l, r);
        }
        cout << ans << '\n';
    }
    cout.flush();
    return 0;
}
