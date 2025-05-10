#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,j,k) for (int i = j; i < k; ++i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    set<int> ans;
    FOR(i, 2, sqrt(N) + 2) {
        if (N%i) continue;
        ans.insert(i);
        ans.insert(N / i);
    }
    cout << '0';
    for (auto &it : ans) {
        cout << ' ' << it - 1;
    }
    cout << ' ' << N - 1 << '\n';
    cout.flush();
    return 0;
}
