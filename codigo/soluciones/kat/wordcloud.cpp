#include <bits/stdc++.h>
using namespace std;
#define MAX(a,b) a = max(a, b)
#define LEN(s) ((int)(s).length())
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int W, N;
    int tcase = 1;
    while (cin >> W >> N, W || N) {
        int w = 0, h = 0, ans = 0, cmax = 0;
        vector<pair<string, int>> V(N);
        for (auto &it : V) {
            cin >> it.first >> it.second;
            MAX(cmax, it.second);
        }
        for (auto &it : V) {
            int P = 8 + ceil((40 * (it.second - 4)) / (double)(cmax - 4));
            int width = ceil((9 * LEN(it.first) * P) / 16.0);
            if (w > 0) {
                width += 10;
            }
            if (w + width > W) {
                w = 0;
                ans += h;
                h = 0;
                width -= 10;
            }
            w += width;
            MAX(h, P);
        }
        ans += h;
        cout << "CLOUD " << tcase << ": " << ans << '\n';
        ++tcase;
    }
    cout.flush();
    return 0;
}
