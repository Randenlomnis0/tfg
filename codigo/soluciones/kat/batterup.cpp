#include <bits/stdc++.h>
using namespace std;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int nom = 0, denom = 0;
    while (n--) {
        int aux;
        cin >> aux;
        if (aux == -1) continue;
        nom += aux;
        ++denom;
    }
    cout << fixed << setprecision(3) << nom/(double)denom << '\n';
    cout.flush();
    return 0;
}
