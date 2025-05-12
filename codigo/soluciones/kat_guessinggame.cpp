#include <bits/stdc++.h>
using namespace std;
#define MAX(a,b) a = max(a, b)
#define MIN(a,b) a = min(a, b)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int guess;
    while (cin >> guess, guess) {
        string a, b;
        int l = 1, r = 10;
        while (cin >> a >> b, a != "right" || b != "on") {
            if (b == "high") {
                MIN(r, guess - 1);
            }else {
                MAX(l, guess + 1);
            }
            cin >> guess;
        }
        if (l > r || l > guess || r < guess) {
            cout << "Stan is dishonest\n";
        }else {
            cout << "Stan may be honest\n";
        }
    }
    cout.flush();
    return 0;
}
