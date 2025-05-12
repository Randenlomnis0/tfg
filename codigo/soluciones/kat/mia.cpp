#include <bits/stdc++.h>
using namespace std;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int s0, s1, r0, r1;
    while (cin >> s0 >> s1 >> r0 >> r1, s0 || s1 || r0 || r1) {
        if (s0 < s1) swap(s0, s1);
        if (r0 < r1) swap(r0, r1);
        int a, b;
        if (s0 == 2 && s1 == 1) {
            a = 3;
        }else if (s0 == s1) {
            a = 2;
        }else {
            a = 1;
        }
        if (r0 == 2 && r1 == 1) {
            b = 3;
        }else if (r0 == r1) {
            b = 2;
        }else {
            b = 1;
        }
        if (a > b) {
            cout << "Player 1 wins.\n";
        }else if (b > a) {
            cout << "Player 2 wins.\n";
        }else {
            if (a == 3) {
                cout << "Tie.\n";
            }else if (a == 2) {
                if (s0 == r0) {
                    cout << "Tie.\n";
                }else if (s0 > r0) {
                    cout << "Player 1 wins.\n";
                }else {
                    cout << "Player 2 wins.\n";
                }
            }else {
                a = s0 * 10 + s1;
                b = r0 * 10 + r1;
                if (a > b) {
                    cout << "Player 1 wins.\n";
                }else if (b > a) {
                    cout << "Player 2 wins.\n";
                }else {
                    cout << "Tie.\n";
                }
            }
        }
    }
    cout.flush();
    return 0;
}
