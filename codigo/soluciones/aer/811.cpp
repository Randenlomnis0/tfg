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
    int N, C;
    while (cin >> N >> C, N || C) {
        FenwickTree ceros(N), menosunos(N);
        FOR(i, 0, N) {
            int v;
            cin >> v;
            if (v == 0) {
                ceros.update(i + 1, 1);
            }else if (v < 0) {
                menosunos.update(i + 1, 1);
            }
        }
        string ans = "";
        while (C--) {
            char c;
            cin >> c;
            if (c == 'C') {
                int pos, val;
                cin >> pos >> val;
                ceros.update(pos, -ceros.rsq(pos, pos));
                menosunos.update(pos, -menosunos.rsq(pos, pos));
                if (val == 0) {
                    ceros.update(pos, 1);
                }else if (val < 0) {
                    menosunos.update(pos, 1);
                }
            }else {
                int a, b;
                cin >> a >> b;
                if (ceros.rsq(a, b) > 0) {
                    ans += "0";
                }else if (menosunos.rsq(a, b)%2) {
                    ans += "-";
                }else {
                    ans += "+";
                }
            }
        }
        cout << ans << '\n';
    }
    cout.flush();
    return 0;
}
