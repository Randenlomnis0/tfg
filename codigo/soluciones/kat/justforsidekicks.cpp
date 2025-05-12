#include <bits/stdc++.h>
using namespace std;
#define SZ(c) ((int)(c).size())
#define LSOne(S) ((S) & -(S))
#define FOR(i,j,k) for (int i = j; i < k; ++i)
typedef long long ll;
typedef vector<int> vi;
class FenwickTree {
private:
    vi ft;
public:
    FenwickTree(int m) { ft.assign(m + 1, 0); }
    int rsq(int j) {
        int sum = 0;
        for (; j; j -= LSOne(j))
            sum += ft[j];
        return sum;
    }
    int rsq(int i, int j) { return rsq(j) - rsq(i - 1); }
    void update(int i, int v) {
        for (; i < SZ(ft); i += LSOne(i))
            ft[i] += v;
    }
};
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    vector<ll> V(6);
    for (auto &it : V) {
        cin >> it;
    }
    string P;
    vector<FenwickTree> ftrees(6, FenwickTree(N));
    cin >> P;
    FOR(i, 0, N) {
        ftrees[P[i] - '1'].update(i + 1, 1);
    }
    while (Q--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int k, p;
            cin >> k >> p;
            --p;
            ftrees[P[k - 1] - '1'].update(k, -1);
            P[k - 1] = p + '1';
            ftrees[P[k - 1] - '1'].update(k, 1);
        }else if (cmd == 2) {
            int p, v;
            cin >> p >> v;
            --p;
            V[p] = v;
        }else {
            int l, r;
            cin >> l >> r;
            ll ans = 0;
            FOR(i, 0, 6) {
                ans += ftrees[i].rsq(l, r) * V[i];
            }
            cout << ans << '\n';
        }
    }
    cout.flush();
    return 0;
}
