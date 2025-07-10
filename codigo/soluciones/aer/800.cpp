#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    while (cin >> N) {
        int ans = floor(sqrt(N));
        cout << (ans * ans == N ? "ENCENDIDA" : "APAGADA") << '\n';
    }
    cout.flush();
    return 0;
}
