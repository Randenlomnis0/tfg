#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define MAX(a,b) a = (a == -1 ? b : max(a, b))
#define MIN(a,b) a = (a == -1 ? b : min(a, b))
int mcd(int a, int b) {
    while (b > 0) {
        int tmp = a;
        a = b;
        b = tmp%b;
    }
    return a;
}
int mcm(int a, int b) {
    return a / mcd(a, b) * b;
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int h;
    while (cin >> h) {
        int n;
        cin >> n;
        vector<int> monedas(n);
        for (auto &it : monedas) {
            cin >> it;
        }
        int l = -1, r = -1;
        FOR(a, 0, n) {
            FOR(b, 0, a) {
                FOR(c, 0, b) {
                    FOR(d, 0, c) {
                        int base = mcm(mcm(mcm(monedas[a], monedas[b]), monedas[c]), monedas[d]);
                        int hl = base * (h / base);
                        MAX(l, hl);
                        if (hl < h) {
                            hl += base;
                        }
                        MIN(r, hl);
                    }
                }
            }
        }
        cout << l << ' ' << r << '\n';
    }
    cout.flush();
    return 0;
}
