#include <bits/stdc++.h>
using namespace std;
#define MAX(a,b) a = max(a, b)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    while (cin >> N, N) {
        int m;
        cin >> m;
        int aux = 0, ans = 0;
        while (--N) {
            int n;
            cin >> n;
            ++aux;
            MAX(ans, aux);
            if (n > m) {
                m = n;
                aux = 1;
            }
        }
        cout << ans << '\n';
    }
    cout.flush();
    return 0;
}
