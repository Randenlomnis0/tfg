#include <bits/stdc++.h>
using namespace std;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n, t;
    cin >> m >> n >> t;
    bool ans = true;
    if (t == 1) {
        int aux = 1;
        for (int i = 2; i <= n; ++i) {
            aux *= i;
            if (aux > m) {
                ans = false;
                break;
            }
        }
    }else if (t == 2) {
        int aux = 1;
        for (int i = 0; i < n; ++i) {
            aux *= 2;
            if (aux > m) {
                ans = false;
                break;
            }
        }
    }else if (t == 7) {
        ans = m >= n;
    }else if (t == 6) {
        ans = m >= n * log2(n);
    }else {
        t = 7 - t;
        int aux = 1;
        for (int i = 0; i < t; ++i) {
            aux *= n;
            if (aux > m) {
                ans = false;
                break;
            }
        }
    }
    cout << (ans ? "AC" : "TLE") << '\n';
    cout.flush();
    return 0;
}
