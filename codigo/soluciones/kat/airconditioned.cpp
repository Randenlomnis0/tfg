#include <bits/stdc++.h>
using namespace std;
#define ALL(c) (c).begin(), (c).end()
#define MIN(a,b) a = min(a, b)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<pair<int, int>> preferences(N);
    for (auto &it : preferences) {
        cin >> it.first >> it.second;
    }
    sort(ALL(preferences));
    int ans = 0, aux = 0;
    for (auto &it : preferences) {
        if (aux < it.first) {
            ++ans;
            aux = it.second;
        }else {
            MIN(aux, it.second);
        }
    }
    cout << ans << '\n';
    cout.flush();
    return 0;
}
