#include <bits/stdc++.h>
using namespace std;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int C, n;
    cin >> C >> n;
    int inside = 0;
    bool inconsistent = false;
    while (n--) {
        int left, entered, waited;
        cin >> left >> entered >> waited;
        inside -= left;
        C += left;
        if (inside < 0) {
            inconsistent = true;
        }
        C -= entered;
        inside += entered;
        if (C < 0) {
            inconsistent = true;
        }
        if (waited > 0 && C > 0) {
            inconsistent = true;
        }
    }
    if (inconsistent || inside > 0) {
        cout << "im";
    }
    cout << "possible\n";
    cout.flush();
    return 0;
}
