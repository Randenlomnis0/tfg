#include <bits/stdc++.h>
using namespace std;

signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int M, N;
    double R;
    cin >> M >> N >> R;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double ans = abs(y1 - y2) * (R / N) + (abs(x1 - x2) * acos(-1.0) * min(y1, y2) * (R / N)) / M;
    cout << fixed << setprecision(6) << ans << '\n';
    cout.flush();
    return 0;
}
