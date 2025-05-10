#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
int msort(vector<int>& V, const int& lb, const int& hb) {
    if (lb == hb - 1) {
        return 0;
    }
    int llb = lb, lhb = (lb + hb + 1) / 2, rlb = (lb + hb + 1) / 2, rhb = hb, n = hb - lb;
    msort(V, llb, lhb);
    msort(V, rlb, rhb);
    vector<int> aux(n);
    int l = llb, r = rlb, k = 0, ans = 0;
    while (l < lhb && r < rhb) {
        if (V[l] <= V[r]) {
            aux[k++] = V[l++];
        }else {
            ans += lhb - l - 1;
            aux[k++] = V[r++];
        }
    }
    while (l < lhb) {
        aux[k++] = V[l++];
    }
    while (r < rhb) {
        aux[k++] = V[r++];
    }
    FOR(i, 0, n) {
        V[i + lb] = aux[i];
    }
    return ans;
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (auto &it : A) {
        cin >> it;
    }
    for (auto &it : B) {
        cin >> it;
    }
    int a = msort(A, 0, N);
    int b = msort(B, 0, N);
    cout << (abs(a - b)%3 ? "Possible" : "Impossible") << '\n';
    cout.flush();
    return 0;
}
