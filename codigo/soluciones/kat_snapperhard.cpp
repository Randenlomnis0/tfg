#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    FOR(i, 1, T + 1) {
        int N, K;
        cin >> N >> K;
        cout << "Case #" << i << ": " << ((K + 1)%(1<<N) == 0 ? "ON" : "OFF") << '\n';
    }
    cout.flush();
    return 0;
}
