#include <bits/stdc++.h>
using namespace std;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int X, N, ans;
    cin >> X >> N;
    ans = X;
    while (N--) {
        int aux;
        cin >> aux;
        ans += X - aux;
    }
    cout << ans << '\n';
    cout.flush();
    return 0;
}
