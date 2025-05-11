#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define FOR(i,j,k) for (int i = j; i < k; ++i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    double g;
    cin >> N >> g;
    vector<double> ans(N);
    vector<int> D(N);
    FOR(i, 0, N) {
        int theta;
        cin >> D[i] >> theta;
        ans[i] = g * cos(acos(-1.0) * theta / 180.0);
    }
    FOR(i, 0, N) {
        double speed = 0.0;
        FOR(j, i, N) {
            speed = sqrt(speed * speed + 2 * ans[i] * D[i]);
        }
        cout << fixed << setprecision(6) << speed << '\n';
    }
    cout.flush();
    return 0;
}
