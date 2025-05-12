#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a = INT_MAX, b;
    FOR(i, 0, n) {
        int aux;
        cin >> aux;
        if (aux < a) {
            b = i;
            a = aux;
        }
    }
    cout << b << '\n';
    cout.flush();
    return 0;
}
