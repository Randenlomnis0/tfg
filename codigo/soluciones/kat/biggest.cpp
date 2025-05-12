#include <bits/stdc++.h>
using namespace std;

signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin >> m;
    while (m--) {
        int r, n, thetad, thetam, thetas;
        cin >> r >> n >> thetad >> thetam >> thetas;
        if (n == 1) {
            cout << fixed << setprecision(4) << acos(-1.0) * r * r << '\n';
        }else {
            double delta = acos(-1.0) * (thetad / 180.0);
            delta += (acos(-1.0) * (thetam / 180.0)) / 360;
            delta += ((acos(-1.0) * (thetas / 180.0)) / 360) / 360;
        }
    }
    cout.flush();
    return 0;
}
