#include <bits/stdc++.h>
using namespace std;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    double X, Y;
    cin >> X >> Y;
    if (Y == 1) {
        cout << (X ? "IMPOSSIBLE" : "ALL GOOD") << '\n';
    }else {
        cout << fixed << setprecision(6) << X / (1 - Y) << '\n';
    }
    cout.flush();
    return 0;
}
