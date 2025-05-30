#include <bits/stdc++.h>
using namespace std;
int solve(const int &N, const int &K) {
    if (N == K) return 0;
    if (N / 2 >= K) {
        return 1 + solve(N / 2, K);
    }else {
        return 1 + solve(N / 2, K - N / 2);
    }
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int K;
    cin >> K;
    int ans = pow(2, ceil(log2(K)));
    cout << ans << ' ' << solve(ans, K) << '\n';
    cout.flush();
    return 0;
}
