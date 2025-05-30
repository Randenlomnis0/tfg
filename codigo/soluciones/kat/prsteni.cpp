#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
int mcd(const int &a, const int &b) { return (b == 0 ? a : mcd(b, a%b)); };
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> R(N);
    for (auto &it : R) {
        cin >> it;
    }
    int A = 1, B = 1;
    FOR(i, 1, N) {
        A *= R[i - 1];
        B *= R[i];
        int aux = mcd(A, B);
        A /= aux;
        B /= aux;
        cout << A << '/' << B << '\n';
    }
    cout.flush();
    return 0;
}
