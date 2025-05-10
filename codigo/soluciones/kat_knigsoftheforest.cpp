#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define mp(a,b) make_pair(a, b)
#define MAX(a,b) a = max(a, b)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int k, n;
    cin >> k >> n;
    int y, p;
    cin >> y >> p;
    priority_queue<pair<int, int>> pq1, pq2;
    pq1.push(mp(-y, p));
    FOR(i, 0, n + k - 2) {
        int a, b;
        cin >> a >> b;
        pq1.push(mp(-a, b));
    }
    set<int> strengths;
    FOR(i, 0, k) {
        strengths.insert(pq1.top().second);
        pq2.push(mp(pq1.top().second, -pq1.top().first));
        pq1.pop();
    }
    int year = 2011, ans = -1;
    while (!pq1.empty()) {
        if (*strengths.rbegin() == p) {
            ans = year;
            break;
        }
        int a = pq2.top().first, b = pq2.top().second;
        pq2.pop();
        strengths.erase(a);
        pq2.push(mp(pq1.top().second, -pq1.top().first));
        strengths.insert(pq1.top().second);
        pq1.pop();
        ++year;
    }
    if (*strengths.rbegin() == p) {
        ans = year;
    }
    if (ans == -1) {
        cout << "unknown\n";
    }else {
        cout << ans << '\n';
    }
    cout.flush();
    return 0;
}
