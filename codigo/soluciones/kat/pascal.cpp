#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    vector<bool> isPrime(40001, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 4; i <= 40000; i += 2) {
        isPrime[i] = false;
    }
    vector<int> p(1, 2);
    for (int i = 3; i <= 200; i += 2) {
        if (!isPrime[i]) continue;
        p.pb(i);
        for (int j = i * i; j <= 40000; j += i) {
            isPrime[j] = false;
        }
    }
    for (int i = 201; i <= 40000; ++i) {
        if (!isPrime[i]) continue;
        p.pb(i);
    }
    int N;
    cin >> N;
    int ans = 1;
    for (auto &it : p) {
        if (it * it > N) break;
        if (N%it == 0) {
            ans = N / it;
            break;
        }
    }
    cout << (N != 1 ? N - ans : 0) << '\n';
    cout.flush();
    return 0;
}
