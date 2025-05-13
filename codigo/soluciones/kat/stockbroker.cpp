#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define int long long
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int d;
    cin >> d;
    vector<int> P(d);
    for (auto &it : P) {
        cin >> it;
    }
    int money = 100, shares = 0;
    FOR(i, 1, d) {
        if (P[i - 1] < P[i]) {
            int buy = money / P[i - 1];
            shares += buy;
            money -= buy * P[i - 1];
        }else if (P[i - 1] > P[i]) {
            money += shares * P[i - 1];
            shares = 0;
        }
    }
    if (shares) {
        money += shares * P[d - 1];
    }
    cout << money << '\n';
    cout.flush();
    return 0;
}
