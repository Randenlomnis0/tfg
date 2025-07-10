#include <bits/stdc++.h>
using namespace std;
#define MAX(a,b) a = max(a, b)
#define MIN(a,b) a = min(a, b)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        int mx = INT_MIN, mn = INT_MAX;
        while (n--) {
            int aux;
            cin >> aux;
            MAX(mx, aux);
            MIN(mn, aux);
        }
        cout << mx - mn + min(abs(s - mn), abs(s - mx)) << '\n';
    }
    cout.flush();
    return 0;
}
