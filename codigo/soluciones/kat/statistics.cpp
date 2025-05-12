#include <bits/stdc++.h>
using namespace std;
#define MIN(a,b) a = min(a, b)
#define MAX(a,b) a = max(a, b)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n, caso = 1;
    while (cin >> n) {
        cout << "Case " << caso << ": ";
        ++caso;
        int a = INT_MAX, b = INT_MIN;
        while (n--) {
            int aux;
            cin >> aux;
            MIN(a, aux);
            MAX(b, aux);
        }
        cout << a << ' ' << b << ' ' << b - a << '\n';
    }
    cout.flush();
    return 0;
}
