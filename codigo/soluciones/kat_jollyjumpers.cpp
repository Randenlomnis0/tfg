#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n) {
        vector<int> ft(n, 0);
        int aux, prev;
        cin >> aux;
        FOR(i, 1, n) {
            prev = aux;
            cin >> aux;
            int ans = abs(aux - prev);
            if (ans < 1 || ans >= n) {
                ++ft[0];
            }else if (ft[ans]++) {
                    ++ft[0];
            }
        }
        if (ft[0]) {
            cout << "Not ";
        }
        cout << "Jolly\n";
    }
    cout.flush();
    return 0;
}
