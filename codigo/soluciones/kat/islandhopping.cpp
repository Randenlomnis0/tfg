#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define mp(a,b) make_pair(a, b)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (n--) {
        int m;
        cin >> m;
        vector<double> x(m), y(m);
        FOR(i, 0, m) {
            cin >> x[i] >> y[i];
        }
        priority_queue<pair<double, int>> pq;
        vector<bool> visited(m);
        visited[0] = true;
        FOR(i, 1, m) {
            pq.push(mp(-hypot(x[0] - x[i], y[0] - y[i]), i));
        }
        double ans = 0;
        int aux = 1;
        while (aux < m) {
            double w = -pq.top().first;
            int i = pq.top().second;
            pq.pop();
            if (visited[i]) continue;
            ++aux;
            ans += w;
            visited[i] = true;
            FOR(j, 0, m) {
                if (visited[j]) continue;
                pq.push(mp(-hypot(x[i] - x[j], y[i] - y[j]), j));
            }
        }
        cout << fixed << setprecision(3) << ans << '\n';
    }
    cout.flush();
    return 0;
}
