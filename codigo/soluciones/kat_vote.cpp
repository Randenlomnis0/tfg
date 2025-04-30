#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int ans, best = -1, winners, total = 0;
        FOR(i, 1, n + 1) {
            int aux;
            cin >> aux;
            if (aux > best) {
                best = aux;
                winners = 1;
                ans = i;
            }else if (aux == best) {
                ++winners;
            }
            total += aux;
        }
        if (winners > 1) {
            cout << "no winner\n";
            continue;
        }

        cout << (best > total / 2 ? "majority" : "minority") << " winner " << ans << '\n';
    }
    cout.flush();
    return 0;
}
