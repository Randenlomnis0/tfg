#include <bits/stdc++.h>
using namespace std;
#define SZ(c) ((int)(c).size())
#define LSOne(S) ((S) & -(S))
typedef long long ll;
typedef vector<ll> vll;
class FenwickTree {
private:
    vll ft;
public:
    FenwickTree(int m) { ft.assign(m + 1, 0); }
    ll rsq(int j) {
        ll sum = 0;
        for (; j; j -= LSOne(j))
            sum += ft[j];
        return sum;
    }
    ll rsq(int i, int j) { return rsq(j) - rsq(i - 1); }
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
    FenwickTree fenwick(N);
    while (Q--) {
        char cmd;
        int i;
        cin >> cmd >> i;
        ++i;
        if (cmd == '+') {
            int delta;
            cin >> delta;
            fenwick.update(i, delta);
        }else {
            cout << fenwick.rsq(1, i - 1) << '\n';
        }
    }
    cout.flush();
    return 0;
}
