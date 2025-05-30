#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb(x) push_back(x)
#define FOR(i,j,k) for (int i = j; i < k; ++i)
bool test(const vector<bool> &isPrime, const vector<int> &p, const int &i) {
    if (i <= 40000) return isPrime[i];
    for (auto &it : p) {
        if (it * it > i) break;
        if (i%it == 0) return false;
    }
    return true;
}
int modpow(const int &a, int b, const int &m) {
    int base = a, ans = 1;
    while (b) {
        if (b%2) {
            ans *= base;
            ans %= m;
        }
        base *= base;
        base %= m;
        b /= 2;
    }
    return ans;
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    vector<bool> isPrime(40001, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 4; i <= 40000; i += 2) {
        isPrime[i] = false;
    }
    vector<int> pr(1, 2);
    for (int i = 3; i <= 200; i += 2) {
        if (!isPrime[i]) continue;
        pr.pb(i);
        for (int j = i * i; j <= 40000; j += i) {
            isPrime[j] = false;
        }
    }
    for (int i = 201; i <= 40000; ++i) {
        if (!isPrime[i]) continue;
        pr.pb(i);
    }
    int p, a;
    while (cin >> p >> a, p || a) {
        cout << (!test(isPrime, pr, p) && modpow(a, p, p) == a ? "yes" : "no") << '\n';
    }
    cout.flush();
    return 0;
}
