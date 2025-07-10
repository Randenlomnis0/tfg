#include <bits/stdc++.h>
using namespace std;
#define int long long
#define SZ(c) ((int)(c).size())
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    while (cin >> n >> k, n || k) {
        int a = 0, b = 0;
        priority_queue<int> kRicos;
        while (n--) {
            int aux;
            cin >> aux;
            a += aux;
            kRicos.push(-aux);
            if (SZ(kRicos) > k) {
                kRicos.pop();
            }
        }
        while (!kRicos.empty()) {
            b -= kRicos.top();
            kRicos.pop();
        }
        cout << a << ' ' << b << '\n';
    }
    cout.flush();
    return 0;
}
