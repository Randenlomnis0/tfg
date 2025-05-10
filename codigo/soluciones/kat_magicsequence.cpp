#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define ALL(c) (c).begin(), (c).end()
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int TC;
    cin >> TC;
    while (TC--) {
        int N, A, B, C, X, Y;
        cin >> N >> A >> B >> C >> X >> Y;
        vector<int> S(N);
        S[0] = A;
        FOR(i, 1, N) {
            S[i] = (S[i - 1] * B + A)%C;
        }
        sort(ALL(S));
        int V = 0;
        FOR(i, 0, N) {
            V = (V * X + S[i])%Y;
        }
        cout << V << '\n';
    }
    cout.flush();
    return 0;
}
