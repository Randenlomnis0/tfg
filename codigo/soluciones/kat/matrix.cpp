#include <bits/stdc++.h>
using namespace std;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, c, d, tcase = 1;
    while (cin >> a >> b >> c >> d) {
        cout << "Case " << tcase << ":\n";
        ++tcase;
        int det = a * d - b * c;
        swap(a, d);
        b *= -1;
        c *= -1;
        cout << a / det << ' ' << b / det << '\n';
        cout << c / det << ' ' << d / det << '\n';
    }
    cout.flush();
    return 0;
}
