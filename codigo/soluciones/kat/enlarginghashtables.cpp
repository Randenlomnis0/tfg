#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb(x) push_back(x)
#define SZ(c) ((int)(c).size())
#define ALL(c) (c).begin(), (c).end()
void solve(vector<int> &p) {
    int N = 1<<15, n = floor(sqrt(1<<15));
    if (n%2 == 0) {
        ++n;
    }
    vector<bool> aux(N + 1, true);
    aux[0] = aux[1] = false;
    for (int i = 4; i <= N; i += 2) {
        aux[i] = false;
    }
    p.pb(2);
    for (int i = 3; i <= n; i += 2) {
        if (!aux[i]) continue;
        p.pb(i);
        for (int j = i * i; j <= N; j += i) {
            aux[j] = false;
        }
    }
    for (int i = n + 1; i <= N; i += 2) {
        if (!aux[i]) continue;
        p.pb(i);
    }
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> p;
    solve(p);
    int n;
    while (cin >> n, n) {
        cout << *upper_bound(ALL(p), 2 * n);
        if (*lower_bound(ALL(p), n) != n) {
            cout << " (" << n << " is not prime)";
        }
        cout << '\n';
    }
    cout.flush();
    return 0;
}
