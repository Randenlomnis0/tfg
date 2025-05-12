#include <bits/stdc++.h>
using namespace std;
#define ALL(c) (c).begin(), (c).end()
#define FOR(i,j,k) for (int i = j; i < k; ++i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> stops(N);
    for (auto &it : stops) {
        cin >> it;
    }
    sort(ALL(stops));
    cout << stops[0];
    vector<bool> hide(N);
    FOR(i, 1, N - 1) {
        if (stops[i - 1] + 1 != stops[i] || stops[i] + 1 != stops[i + 1]) continue;
        hide[i] = true;
    }
    FOR(i, 1, N - 1) {
        if (hide[i]) continue;
        if (hide[i - 1]) {
            cout << '-' << stops[i];
        }else {
            cout << ' ' << stops[i];
        }
    }
    if (N > 1) {
        if (hide[N - 2] && !hide[N - 1]) {
            cout << '-' << stops[N - 1];
        }else {
            cout << ' ' << stops[N - 1];
        }
    }
    cout << '\n';
    cout.flush();
    return 0;
}
