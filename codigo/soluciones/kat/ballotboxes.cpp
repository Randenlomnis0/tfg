#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a, b)
#define int long long
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N, B;
    while (cin >> N >> B, N != -1 || B != -1) {
        if (N == 1) {
            int a;
            cin >> a;
            cout << a / B + (a%B != 0) << '\n';
            continue;
        }
        auto cmp = [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.first * b.second < b.first * a.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> cities(cmp);
        B -= N;
        while (N--) {
            int a;
            cin >> a;
            cities.push(mp(a, 1));
        }
        while (B > 0) {
            int a = cities.top().first;
            int b = cities.top().second;
            cities.pop();
            int bgoal = max(b + 1, (int)ceil(a * cities.top().second / (double)cities.top().first));
            if (bgoal - b > B) {
                bgoal = B + b;
            }
            B -= bgoal - b;
            cities.push(mp(a, bgoal));
        }
        cout << cities.top().first / cities.top().second + (cities.top().first%cities.top().second != 0) << '\n';
    }
    cout.flush();
    return 0;
}
