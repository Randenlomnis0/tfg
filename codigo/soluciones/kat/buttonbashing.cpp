#include <bits/stdc++.h>
using namespace std;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, t;
        cin >> n >> t;
        vector<int> buttons(n);
        for (auto &it : buttons) {
            cin >> it;
        }
        vector<int> ans(3601, -1);
        int aux = 0;
        queue<int> q;
        q.push(0);
        q.push(-1);
        while (q.size() > 1) {
            int i = q.front();
            q.pop();
            if (i == -1) {
                ++aux;
                q.push(-1);
                continue;
            }
            if (ans[i] != -1) continue;
            ans[i] = aux;
            for (auto &it : buttons) {
                if (ans[max(0, min(3600, i + it))] != -1) continue;
                q.push(max(0, min(3600, i + it)));
            }
        }
        aux = t;
        while (ans[aux] == -1) {
            ++aux;
        }
        cout << ans[aux] << ' ' << aux - t << '\n';
    }
    cout.flush();
    return 0;
}
