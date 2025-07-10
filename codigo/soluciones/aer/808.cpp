#include <bits/stdc++.h>
using namespace std;
#define MAX(a,b) a = max(a, (ll)b)
#define FOR(i,j,k) for (int i = j; i < k; ++i)
typedef long long ll;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int hp, n;
    while (cin >> hp >> n) {
        vector<int> v(n);
        ll lb = 0;
        for (auto &it : v) {
            cin >> it;
            MAX(lb, -it);
        }
        ll hb = 1000000000001L;
        while (lb != hb - 1) {
            ll nb = (lb + hb) / 2;
            ll energia = nb;
            int vidas = hp;
            FOR (i, 0, n) {
                energia += v[i];
                if (energia <= 0) {
                    energia = nb + v[i];
                    --vidas;
                }else if (energia > nb) {
                    energia = nb;
                }
                if (vidas == 0) break;
            }
            if (vidas == 0) {
                lb = nb;
            }else {
                hb = nb;
            }
        }
        cout << hb << '\n';
    }
    cout.flush();
    return 0;
}
