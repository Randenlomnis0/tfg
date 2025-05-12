#include <bits/stdc++.h>
using namespace std;
#define ll long long
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    ll a, b;
    while (cin >> a >> b) {
        cout << abs(a - b) << '\n';
    }
    cout.flush();
    return 0;
}
