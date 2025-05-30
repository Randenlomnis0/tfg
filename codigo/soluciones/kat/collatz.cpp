#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int A, B;
    while (cin >> A >> B, A || B) {
        int origA = A, origB = B;
        unordered_map<int, int> seqA;
        int i = 0;
        while (A != 1) {
            seqA[A] = i++;
            if (A%2) {
                A = A * 3 + 1;
            }else {
                A = A / 2;
            }
        }
        seqA[A] = i;
        i = 0;
        int ansA = -1, ansB = -1, ans = -1;
        while (B != 1) {
            if (seqA.count(B)) {
                ansA = seqA[B];
                ansB = i;
                ans = B;
                break;
            }
            ++i;
            if (B%2) {
                B = B * 3 + 1;
            }else {
                B = B / 2;
            }
        }
        if (ansA == -1) {
            ansA = seqA[1];
            ansB = i;
            ans = 1;
        }
        cout << origA << " needs " << ansA << " steps, " << origB << " needs " << ansB << " steps, they meet at " << ans << '\n';
    }
    cout.flush();
    return 0;
}
