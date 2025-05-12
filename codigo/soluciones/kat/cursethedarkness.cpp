#include <bits/stdc++.h>
using namespace std;

signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin >> m;
    while (m--) {
        double X, Y;
        cin >> X >> Y;
        int n;
        cin >> n;
        bool cursethedarkness = true;
        while (n--) {
            double x, y;
            cin >> x >> y;
            x -= X;
            y -= Y;
            if (x * x + y * y > 64.0) continue;
            cursethedarkness = false;
        }
        cout << (cursethedarkness ? "curse the darkness" : "light a candle") << '\n';
    }
    cout.flush();
    return 0;
}
