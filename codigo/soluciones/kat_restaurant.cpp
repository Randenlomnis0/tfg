#include <bits/stdc++.h>
using namespace std;

signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    bool first = true;
    while (cin >> N, N) {
        int a = 0, b = 0;
        if (!first) cout << '\n';
        else first = false;
        while (N--) {
            string instr;
            int m;
            cin >> instr >> m;
            if (instr == "DROP") {
                cout << "DROP 2 " << m << '\n';
                b += m;
            }else {
                if (a >= m) {
                    cout << "TAKE 1 " << m << '\n';
                    a -= m;
                    m = 0;
                }else if (a > 0) {
                    cout << "TAKE 1 " << a << '\n';
                    m -= a;
                    a = 0;
                }
                if (m > 0) {
                    cout << "MOVE 2->1 " << b << '\n';
                    cout << "TAKE 1 " << m << '\n';
                    a += b;
                    a -= m;
                    b = 0;
                }
            }
        }
    }
    cout.flush();
    return 0;
}
