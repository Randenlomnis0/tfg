#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a, b)
#define MAX(a,b) a = max(a, b)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    priority_queue<pair<int, int>> l, r;
    while (N--) {
        int a, b;
        cin >> a >> b;
        if (b == 0) continue;
        if (a < 0) {
            l.push(mp(a, b));
        }else {
            r.push(mp(-a, b));
        }
    }
    int ans = 0;
    while (!l.empty()) {
        int cartas = K, dist = 0;
        int d = -l.top().first;
        int k = l.top().second;
        l.pop();
        int viajes = (k - cartas) / K + 1 + ((k - cartas) % K != 0);
        cartas = K - (k - cartas) % K;
        if (cartas < K) {

        }else {
            ans += 2 * dist * viajes;
        }
    }
    while (!r.empty()) {
        int cartas = K, dist = 0;
        while (cartas > 0 && !r.empty()) {
            int d = -r.top().first;
            int k = r.top().second;
            r.pop();
            int aux = k;
            k = max(0, k - cartas);
            cartas = max(0, cartas - k);
            if (k > 0) {
                r.push(mp(-d, k));
            }
            MAX(dist, d);
        }
        ans += 2 * dist;
    }
    cout << ans << '\n';
    cout.flush();
    return 0;
}
