#include <bits/stdc++.h>
using namespace std;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    cout << (a >= 1 && b >= 1 && c >= 1 && n >= 3 && a + b + c >= n ? "YES" : "NO") << '\n'; 
    cout.flush();
    return 0;
}
