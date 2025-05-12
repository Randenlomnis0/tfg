#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
bool sameDiag(int a, int b, int c, int d) {
    return a - b == c - d || a + b == c + d;
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        char A, C;
        int a, b, c, d;
        cin >> A >> b >> C >> d;
        a = A - 'A' + 1;
        c = C - 'A' + 1;
        if ((a + b + c + d)%2) {
            cout << "Impossible\n";
        }else if (a == c && b == d) {
            cout << "0 " << A << ' ' << b << '\n';
        }else if (sameDiag(a, b, c, d)) {
            cout << "1 " << A << ' ' << b << ' ' << C << ' ' << d << '\n';
        }else {
            int p, q;
            FOR(i, 1, 9) {
                FOR(j, 1, 9) {
                    if (sameDiag(a, b, i, j) && sameDiag(c, d, i, j)) {
                        p = i;
                        q = j;
                    }
                }
            }
            cout << "2 " << A << ' ' << b << ' ' << (char)(p + 'A' - 1) << ' ' << q << ' ' << C << ' ' << d << '\n';
        }
    }
    cout.flush();
    return 0;
}
