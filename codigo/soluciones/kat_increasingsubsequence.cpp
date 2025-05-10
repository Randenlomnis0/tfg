#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define pb(x) push_back(x)
#define ALL(c) (c).begin(), (c).end()
#define SZ(c) ((int)(c).size())
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n, n) {
        vector<int> A(n), LIS(n, 1), p(n, -1);
        for (auto &it : A) {
            cin >> it;
        }
        int ans = 0;
        FOR(i, 1, n) {
            FOR(j, 0, i) {
                if (A[j] >= A[i]) continue;
                if (LIS[i] < LIS[j] + 1) {
                    LIS[i] = LIS[j] + 1;
                    p[i] = j;
                }else if (LIS[i] == LIS[j] + 1 && A[j] < A[p[i]]) {
                    p[i] = j;
                }
            }
            if (LIS[i] > LIS[ans]) {
                ans = i;
            }else if (LIS[i] == LIS[ans] && A[i] < A[ans]) {
                ans = i;
            }
        }
        cout << LIS[ans];
        vector<int> v;
        while (ans != -1) {
            v.pb(A[ans]);
            ans = p[ans];
        }
        reverse(ALL(v));
        for (auto &it : v) {
            cout << ' ' << it;
        }
        cout << '\n';
    }
    cout.flush();
    return 0;
}
