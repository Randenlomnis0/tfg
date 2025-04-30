#include <bits/stdc++.h>
using namespace std;
#define GL(x) getline(cin, x)
#define LEN(x) ((int)x.length())
#define FOR(i,j,k) for (int i = j; i < k; ++i)
int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);   
    int n, naux, nauxx;
    string s, aux, ans;
    while (cin >> n, n) {
        GL(aux);
        GL(aux);
        s = "";
        for (auto &it : aux) {
            if (it == ' ') continue;
            s += toupper(it);
        }
        ans = string(LEN(s), '-');
        naux = nauxx = 0;
        FOR(i, 0, LEN(s)) {
            ans[naux + nauxx] = s[i];
            nauxx += n;
            if (naux + nauxx >= LEN(s)) {
                ++naux;
                nauxx = 0;
            }
        }
        cout << ans << '\n';
    }
    cout.flush();
    return 0;
}
