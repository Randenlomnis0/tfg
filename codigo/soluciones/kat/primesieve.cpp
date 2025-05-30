#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define SZ(c) ((int)(c).size())
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 4; i <= n; i += 2) {
        isPrime[i] = false;
    }
    vector<int> p(1, 2);
    for (int i = 3; i <= floor(sqrt(n)); i += 2) {
        if (!isPrime[i]) continue;
        p.pb(i);
        for (int j = i * i; j <= n; j += i) {
            isPrime[j] = false;
        }
    }
    for (int i = floor(sqrt(n)) + 1; i <= n; ++i) {
        if (!isPrime[i]) continue;
        p.pb(i);
    }
    cout << SZ(p) << '\n';
    while (q--) {
        int i;
        cin >> i;
        cout << isPrime[i] << '\n';
    }
    cout.flush();
    return 0;
}
