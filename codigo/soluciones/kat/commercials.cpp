#include <bits/stdc++.h>
using namespace std;
#define MAX(a,b) a = max(a, b)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N, P;
    cin >> N >> P;
    int ans = 0, aux = 0;
    while (N--) {
        int n;
        cin >> n;
        aux += n - P;
        MAX(ans, aux);
        MAX(aux, 0);
    }
    cout << ans << '\n';
    cout.flush();
    return 0;
}
