#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Y;
    cin >> N >> Y;
    vector<int> ft(N);
    while (Y--) {
        int k;
        cin >> k;
        ++ft[k];
    }
    int ans = 0;
    FOR(i, 0, N) {
        if (ft[i] == 0) {
            cout << i << '\n';
        }else {
            ++ans;
        }
    }
    cout << "Mario got " << ans << " of the dangerous obstacles.\n";
    cout.flush();
    return 0;
}
