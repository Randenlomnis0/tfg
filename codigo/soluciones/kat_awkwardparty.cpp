#include <bits/stdc++.h>
using namespace std;
#define MIN(a,b) a = min(a, b)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int ans = n;
    unordered_map<int, int> prev;
    while (n--) {
        int aux;
        cin >> aux;
        if (prev.count(aux)) {
            MIN(ans, prev[aux] - n);
        }
        prev[aux] = n;
    }
    cout << ans << '\n';
    cout.flush();
    return 0;
}
