#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    double X, Y, N, r;
    while (cin >> X >> Y >> N >> r, X || Y || N || r) {
        FOR(i, 0, N) {
            FOR(j, 0, 12) {
                X -= Y;
                Y += Y * (r / 1200);
            }
        }
        cout << (X >= 0.0 ? "YES" : "NO") << '\n';
    }
    cout.flush();
    return 0;
}
