#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a, b)
#define MAX(a,b) a = max(a, b)
void solve(const int& i, vector<double>& K, const vector<vector<pair<pair<int, int>, bool>>>& AL, const int& N) {
    if (K[i] != -1.0) return;
    K[i] = 0.0;
    for (auto &it : AL[i]) {
        solve(it.first.first, K, AL, N);
        double aux = K[it.first.first];
        if (it.second) {
            aux = sqrt(aux);
        }
        aux /= it.first.second / 100.0;
        MAX(K[i], aux);
    }
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<vector<pair<pair<int, int>, bool>>> AL(N);
    FOR(i, 1, N) {
        int A, B, X, T;
        cin >> A >> B >> X >> T;
        --A;
        --B;
        AL[A].pb(mp(mp(B, X), T == 1));
    }
    vector<double> K(N);
    for (auto &it : K) {
        cin >> it;
    }
    solve(0, K, AL, N);
    cout << fixed << setprecision(3) << K[0] << '\n';
    cout.flush();
    return 0;
}
