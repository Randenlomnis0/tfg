#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
void build(int l, int r, int K, bool first) {
    if (l > r) return;
    if (!first) {
        cout << ' ';
    }
    if (l == r) {
        cout << l;
        return;
    }
    if (l == r - 1) {
        cout << l << ' ' << r;
        return;
    }
    FOR(m, l, r + 1) {
        if (floor(log2(r - m)) + 1 > K - 1 || floor(log2(m - l)) + 1 > K - 1) continue;
        cout << m;
        build(l, m - 1, K - 1, false);
        build(m + 1, r, K - 1, false);
        return;
    }
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        int alturaMinima = floor(log2(N)) + 1;
        if (alturaMinima > K) {
            cout << "IMPOSIBLE\n";
            continue;
        }
        build(1, N, min(N, K), true);
        cout << '\n';
    }
    cout.flush();
    return 0;
}
