#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t;
    cin >> n >> t;
    double px, py, pz;
    cin >> px >> py >> pz;
    double a = 0.0, b = 0.0;
    while (--n) {
        double x, y;
        int z;
        cin >> x >> y >> z;
        a += sqrt(fabs(x - px) * fabs(x - px) + fabs(y - py) * fabs(y -px));
        double frac = sqrt(fabs(x - px) * fabs(x - px) + fabs(y - py) * fabs(y -px)) * (t / (z - pz));
        while (pz < z) {
            b += frac;
            pz += t;
        }
        px = x;
        py = y;
        pz = z;
    }
    cout.flush();
    return 0;
}
