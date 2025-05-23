#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
const int MOD = 1000000009;
int solve(const int& N, const int& K, const int& T, vector<vector<int>>& memo) {
    if (N == 0 && T == 0) return memo[N][T];
    if (N == 0 || T <= 0) return 0;
    int& ans = memo[N][T];
    if (ans != -1) return ans;
    ans = 0;
    FOR(i, 1, K + 1) {
        ans += solve(N - 1, K, T - i, memo);
        ans %= MOD;
    }
    return ans;
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K, T;
    cin >> N >> K >> T;
    vector<vector<int>> memo(N + 1, vector<int>(T + 1, -1));
    memo[0][0] = 1;
    cout << solve(N, K, T, memo) << '\n';
    cout.flush();
    return 0;
}
