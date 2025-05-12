#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int X, Y, N;
    cin >> X >> Y >> N;
    FOR(i, 1, N + 1) {
        bool special = false;
        if (i%X == 0) {
            special = true;
            cout << "Fizz";
        }
        if (i%Y == 0) {
            special = true;
            cout << "Buzz";
        }
        if (!special) {
            cout << i;
        }
        cout << '\n';
    }
    cout.flush();
    return 0;
}
