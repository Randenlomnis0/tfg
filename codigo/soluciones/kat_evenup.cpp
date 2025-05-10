#include <bits/stdc++.h>
using namespace std;
#define SZ(c) ((int)(c).size())
#define pb(x) push_back(x);
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> s;
    while (n--) {
        int aux;
        cin >> aux;
        s.push_back(aux);
        while (SZ(s) >= 2 && (s[SZ(s) - 2] + s[SZ(s) - 1])%2 == 0) {
            s.pop_back();
            s.pop_back();
        }
    }
    cout << SZ(s) << '\n';
    cout.flush();
    return 0;
}
