#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    string cmd;
    cin >> N >> cmd;
    vector<int> V(N);
    FOR(i, 0, N) {
        V[i] = i;
    }
    int ans = 0;
    while (true) {
        int M = (cmd == "out" ? (N + 1) / 2 : N / 2);
        vector<int> L(M), R(N - M);
        FOR(i, 0, M) {
            L[i] = V[i];
        }
        FOR(i, M, N) {
            R[i - M] = V[i];
        }
        if (cmd == "in") swap(L, R);
        FOR(i, 0, N) {
            V[i] = (i%2 == 0 ? L[i / 2] : R[i / 2]);
        }
        ++ans;
        bool terminado = true;
        FOR(i, 1, N) {
            if (V[i - 1] < V[i]) continue;
            terminado = false;
            break;
        }
        if (terminado) break;
    }
    cout << ans << '\n';
    cout.flush();
    return 0;
}
