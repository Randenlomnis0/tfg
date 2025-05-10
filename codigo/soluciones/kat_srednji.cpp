#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N, B;
    cin >> N >> B;
    vector<int> A(N);
    int idx;
    FOR(i, 0, N) {
        cin >> A[i];
        if (A[i] == B) {
            idx = i;
        }
    }
    set<int> l, r;
    int i = idx - 1, j = idx + 1;
    while (i >= 0 && j < N) {
        if (A[i] < B) {
            l.insert(A[i]);
        }else {
            r.insert(A[i]);
        }
        --i;
        if (i < 0) {
            if (A[j] < B) {
                l.insert(A[j]);
            }else {
                r.insert(A[j]);
            }
            --j;
        }else {

        }
    }
    cout.flush();
    return 0;
}
