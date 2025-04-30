#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define MIN(a,b) a = min(a, b)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> tea(N);
    FOR(i, 0, N) {
        cin >> tea[i];
    }
    int M;
    cin >> M;
    vector<int> topping(M);
    FOR(i, 0, M) {
        cin >> topping[i];
    }
    int best = INT_MAX;
    FOR(i, 0, N) {
        int K;
        cin >> K;
        FOR(j, 0, K) {
            int aux;
            cin >> aux;
            MIN(best, tea[i] + topping[aux - 1]);
        }
    }
    int X;
    cin >> X;
    cout << max(0, X / best - 1) << '\n';
    cout.flush();
    return 0;
}
