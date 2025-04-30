#include <bits/stdc++.h>
using namespace std;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (n--) {
        int aux;
        cin >> aux;
        cout << aux << " is " << (aux%2 ? "odd" : "even") << '\n';
    }
    cout.flush();
    return 0;
}
