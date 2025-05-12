#include <bits/stdc++.h>
using namespace std;

signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (n--) {
        int s, d;
        cin >> s >> d;
        if (s < d || (s + d)%2) {
            cout << "impossible\n";
        }else {
            cout << (s + d) / 2 << ' ' << s - ((s + d) / 2) << '\n';
        }
    }
    cout.flush();
    return 0;
}
