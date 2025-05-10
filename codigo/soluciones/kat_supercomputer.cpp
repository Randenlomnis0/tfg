#include <bits/stdc++.h>
using namespace std;
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
    int N, K;
    cin >> N >> K;
    FenwickTree ftree(N);
    while (K--) {
        char cmd;
        cin >> cmd;
        if (cmd == 'F') {
            int i;
            cin >> i;
            ftree.update(i, 1 - 2 * ftree.rsq(i, i));
        }else {
            int l, r;
            cin >> l >> r;
            cout << ftree.rsq(l, r) << '\n';
        }
    }
    cout.flush();
    return 0;
}
