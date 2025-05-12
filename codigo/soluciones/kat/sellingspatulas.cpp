#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n, n) {
        vector<int> sales(1440);
        while (n--) {
            int t;
            double p;
            cin >> t >> p;
            sales[t] += round(p * 100);
        }
        FOR(i, 1, 1440) {
            sales[i] += sales[i - 1];
        }
        int ans = INT_MIN, aux;
        int ansi, ansj;
        FOR(i, 0, 1440) {
            FOR(j, i, 1440) {
                if (i == 0) {
                    aux = sales[j] - (j + 1) * 8;
                }else {
                    aux = sales[j] - sales[i - 1] - (j - i + 1) * 8;
                }
                if (aux > ans) {
                    ans = aux;
                    ansi = i;
                    ansj = j;
                }else if (aux == ans && j - i < ansj - ansi) {
                    ansi = i;
                    ansj = j;
                }
            }
        }
        if (ans <= 0) {
            cout << "no profit\n";
        }else {
            cout << fixed << setprecision(2) << double(ans) / 100.0 << ' ' << ansi << ' ' << ansj << '\n';;
        }
    }
    cout.flush();
    return 0;
}
