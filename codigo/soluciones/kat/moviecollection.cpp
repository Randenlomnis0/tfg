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
    int t;
    cin >> t;
    while (t--) {
        int m, r;
        cin >> m >> r;
        FenwickTree ftree(m + r);
        unordered_map<int, int> pos;
        FOR(i, 0, m) {
            pos[i + 1] = m - i;
            ftree.update(pos[i + 1], 1);
        }
        int aux = m;
        bool first = true;
        while (r--) {
            int a;
            cin >> a;
            if (!first) cout << ' ';
            else first = false;
            cout << m - ftree.rsq(pos[a] - 1) - 1;
            ftree.update(pos[a], -1);
            pos[a] = ++aux;
            ftree.update(pos[a], 1);
        }
        cout << '\n';
    }
    cout.flush();
    return 0;
}
