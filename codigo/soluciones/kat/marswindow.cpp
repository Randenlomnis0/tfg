#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int y;
    cin >> y;
    cout << ((26 + (y - 2018) * 12 - 3)%26 > 14 ? "yes" : "no") << '\n';
    cout.flush();
    return 0;
}
