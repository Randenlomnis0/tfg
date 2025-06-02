#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define mt(a,b,c) make_tuple(a, b, c)
#define ALL(c) (c).begin(), (c).end()
#define MAX(a,b) a = max(a, b)
#define SZ(c) ((int)(c).size())
typedef vector<int> vi;
class SegmentTree {
private:
    int n;
    vi A, st, lazy;
    int l(int p) { return p<<1; }
    int r(int p) { return (p<<1) + 1; }
    int conquer(int a, int b) {
        if (a == -1) return b;
        if (b == -1) return a;
        return max(a, b);
    }
    void build(int p, int L, int R) {
        if (L == R)
            st[p] = A[L];
        else {
            int m = (L + R) / 2;
            build(l(p), L, m);
            build(r(p), m + 1, R);
            st[p] = conquer(st[l(p)], st[r(p)]);
        }
    }
    void propagate(int p, int L, int R) {
        if (lazy[p] != -1) {
            MAX(st[p], lazy[p]);
            if (L != R)
                lazy[l(p)] = lazy[r(p)] = lazy[p];
            else
                st[L] = lazy[p];
            lazy[p] = -1;
        }
    }
    int RMQ(int p, int L, int R, int i, int j) {
        propagate(p, L, R);
        if (i > j) return 0;
        if ((L >= i) && (R <= j)) return st[p];
        int m = (L + R) / 2;
        return conquer(RMQ(l(p), L, m, i, min(m, j)), RMQ(r(p), m + 1, R, max(i, m + 1), j));
    }
    void update(int p, int L, int R, int i, int j, int val) {
        propagate(p, L, R);
        if (i > j) return;
        if ((L >= i) && (R <= j)) {
            lazy[p] = val;
            propagate(p, L, R);
        }else {
            int m = (L + R) / 2;
            update(l(p), L, m, i, min(m, j), val);
            update(r(p), m + 1, R, max(i, m + 1), j, val);
            int lsubtree = (lazy[l(p)] != -1) ? lazy[l(p)] : st[l(p)];
            int rsubtree = (lazy[r(p)] != -1) ? lazy[r(p)] : st[r(p)];
            st[p] = (lsubtree <= rsubtree) ? st[l(p)] : st[r(p)];
        }
    }
public:
    SegmentTree(int sz) : n(sz), st(4 * n), lazy(4 * n, -1) {}
    void update(int i, int j, int val) { update(1, 0, n - 1, i, j, val); }
    int RMQ(int i, int j) { return RMQ(1, 0, n - 1, i, j); }
};
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int W, H, N;
    while (cin >> W >> H >> N, W || H || N) {
        vector<tuple<int, int, int>> obs(N + 2);
        FOR(i, 0, N) {
            char c;
            int x, y, w = 1, h = 1;
            cin >> c >> x >> y;
            if (c == 'V') {
                cin >> w >> h;
            }
            obs[i] = mt(x, x + w - 1, y);
        }
        obs[N++] = mt(-1, -1, H);
        obs[N++] = mt(W, W, H);
        map<int, int> ntoc;
        for (auto &it : obs) {
            MAX(ntoc[get<0>(it)], get<2>(it));
            MAX(ntoc[get<0>(it)], get<2>(it));
        }
        int aux = 0;
        for (auto &it : ntoc) {
            it.second = aux++;
        }
        SegmentTree stree(SZ(ntoc));
        for (auto &it : obs) {
            stree.update(ntoc[get<0>(it)], ntoc[get<1>(it)], get<2>(it));
        }
        int ans = 0;
        FOR(i, 0, N - 1) {
            FOR(j, i + 1, N) {
                if (get<0>(obs[j]) - get<1>(obs[i]) - 1 < 1) continue;
                MAX(ans, (get<0>(obs[j]) - get<1>(obs[i]) - 1) * (H - stree.RMQ(ntoc[get<1>(obs[i])] + 1, ntoc[get<0>(obs[j])] - 1)));
            }
        }
        cout << ans << '\n';
    }
    cout.flush();
    return 0;
}