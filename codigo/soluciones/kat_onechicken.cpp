#include <bits/stdc++.h>
using namespace std;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    if (N <= M) {
        cout << "Dr. Chaz will have " << M - N << " piece" << (M - N != 1 ? "s" : "") << " of chicken left over!";
    }else {
        cout << "Dr. Chaz needs " << N - M << " more piece" << (N - M != 1 ? "s" : "") << " of chicken!";
    }
    cout.flush();
    return 0;
}
