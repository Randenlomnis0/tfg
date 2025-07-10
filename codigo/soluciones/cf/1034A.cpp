#include <bits/stdc++.h>
using namespace std;

signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n%4 == 0) {
            cout << "Bob\n";
        }else {
            cout << "Alice\n";
        }
    }
    cout.flush();
    return 0;
}
