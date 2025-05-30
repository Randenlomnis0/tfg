#include <bits/stdc++.h>
using namespace std;
int dist(int N) {
    int p = 2, norig = N, ans = 1;
    while (p * p < N && N != 1) {
        int aux = 1;
        while (N%p == 0) {
            N /= p;
            aux *= p;
            ans += aux + N / aux;
        }
        ++p;
    }
    if (p * p == N) {
        ans += p;
    }
    return abs(norig - ans);
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    while (cin >> N) {
        cout << N << ' ';
        int d = dist(N);
        if (d > 2) {
            cout << "not ";
        }else if (d > 0) {
            cout << "almost ";
        }
        cout << "perfect\n";
    }
    cout.flush();
    return 0;
}
