#include <bits/stdc++.h>
using namespace std;

signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, c;
    while (cin >> a >> b >> c, a || b || c) {
        if (b > c) swap(b, c);
        if (a > b) swap(a, b);
        if (b > c) swap(b, c);
        cout << (a * a + b * b == c * c ? "right" : "wrong") << '\n';
    }
    cout.flush();
    return 0;
}
