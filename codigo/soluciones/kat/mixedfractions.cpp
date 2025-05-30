#include <bits/stdc++.h>
using namespace std;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    while (cin >> a >> b, a || b) {
        cout << a / b << ' ' << a % b << " / " << b << '\n';
    }
    cout.flush();
    return 0;
}
