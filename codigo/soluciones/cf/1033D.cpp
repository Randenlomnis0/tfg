#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,j,k) for (int i = j; i < k; ++i)
const int MOD = 1000000007;
int modpow(int k, int n) {
    int ans = 1, base = k;
    while (n) {
        if (n%2) {
            ans *= base;
            ans %= MOD;
        }
        n /= 2;
        base *= base;
        base %= MOD;
    }
    return ans;
}
int modinv(int x) {
    return modpow(x, MOD - 2);
}
int nCr(int a, int b) {
    if (b < 0 || b > a) return 0;
    b = min(b, a - b);
    int num = 1, denom = 1;
    FOR(i, 1, b + 1) {
        num *= (a - b + i);
        num %= MOD;
        denom *= i;
        denom %= MOD;
    }
    return (num * modinv(denom))%MOD;
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int a, b, k;
        cin >> a >> b >> k;
        int n = ((a - 1) * k + 1)%MOD;
        int m = ((((b - 1) * nCr(n, a))%MOD) * k + 1)%MOD;
        cout << n << ' ' << m << '\n';
    }
    cout.flush();
    return 0;
}
