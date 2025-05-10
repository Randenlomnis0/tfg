#include <bits/stdc++.h>
using namespace std;
#define MAX(a,b) a = max(a, b)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    set<int> A;
    set<int> B;
    while (N--) {
        int a, b;
        cin >> a >> b;
        A.insert(-a);
        B.insert(b);
        auto aIt = A.begin();
        auto bIt = B.begin();
        int ans = 0;
        while (aIt != A.end()) {
            a = *aIt;
            a *= -1;
            b = *bIt;
            MAX(ans, a + b);
            ++aIt;
            ++bIt;
        }
        cout << ans << '\n';
    }
    cout.flush();
    return 0;
}
