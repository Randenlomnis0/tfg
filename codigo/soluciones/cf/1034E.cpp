#include <bits/stdc++.h>
using namespace std;
#define ALL(c) (c).begin(), (c).end()
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define RFOR(i,j,k) for (int i = j - 1; i >= k; --i)
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
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &it : a) {
            cin >> it;
        }
        sort(ALL(a));
        int cnt = 0;
        for (auto &it : a) {
            if (it == cnt) {
                ++cnt;
            }
        }
        ++cnt;
        vector<int> confronters(cnt);
        for (auto &it : a) {
            if (it >= cnt) break;
            ++confronters[it];
        }
        vector<int> pref(cnt);
        pref[0] = confronters[0];
        FOR(i, 1, cnt) {
            pref[i] = confronters[i] + pref[i - 1];
        }
        vector<int> suff(cnt);
        suff[cnt - 1] = n - pref[cnt - 1];
        RFOR(i, cnt - 1, 0) {
            suff[i] = confronters[i + 1] + suff[i + 1];
        }
        FenwickTree ftree(n + 3);
        FOR(i, 0, cnt) {
            int k = confronters[i], margin = suff[i];
            if (i > 0) {
                margin += pref[i - 1] - i;
            }
            ftree.update(k + 1, 1);
            ftree.update(k + 1 + margin + 1, -1);
        }
        FOR(k, 0, n) {
            cout << ftree.rsq(k + 1) << ' ';
        }
        cout << "1\n";
    }
    cout.flush();
    return 0;
}
