#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    vector<bool> street(N);
    while (K--) {
        int i;
        cin >> i;
        --i;
        street[i] = true;
    }
    int a = 0, b, ans = N * (N - 1) / 2 + N;
    while (a < N) {
        while (a < N && street[a]) {
            ++a;
        }
        b = a;
        while (b < N && !street[b]) {
            ++b;
        }
        ans -= (b - a) * (b - a - 1) / 2 + (b - a);
        a = b;
    }
    cout << ans << '\n';
    cout.flush();
    return 0;
}
