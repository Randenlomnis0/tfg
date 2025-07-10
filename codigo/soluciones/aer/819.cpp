#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define SZ(c) ((int)(c).size())
#define LSOne(S) ((S) & -(S))
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
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        FenwickTree ft(N);
        bool first = true;
        FOR(i, 0, N) {
            int k;
            cin >> k;
            int lb = 0, hb = N;
            while (lb != hb - 1) {
                int nb = (lb + hb) / 2;
                if (nb - ft.rsq(nb) <= k) {
                    lb = nb;
                }else {
                    hb = nb;
                }
            }
            ft.update(hb, 1);
            if (!first) cout << ' ';
            else first = false;
            cout << hb;
        }
        cout << '\n';
    }
    cout.flush();
    return 0;
}
