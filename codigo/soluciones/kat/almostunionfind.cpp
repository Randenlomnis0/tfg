#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
class UnionFind {
private:
    vi p, sz, sum;
public:
    UnionFind(int N) : p(2 * N, -1), sz(2 * N, 1), sum(2 * N, 0) { for (int i = 0; i < N; ++i) { p[i] = N + i; sum[N + i] = sum[i] = i + 1; } }
    int findSet(int i) { return (p[i] < 0) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return;
        int x = findSet(i), y = findSet(j);
        if (p[x] < p[y]) swap(x, y);
        sz[y] += sz[x];
        sum[y] += sum[x];
        p[x] = y;
        if (p[x] == p[y]) --p[y];
        findSet(i);
        findSet(j);
    }
    void moveSet(int i, int j) {
        if (isSameSet(i, j)) return;
        int x = findSet(i), y = findSet(j);
        --sz[y];
        sum[y] -= j + 1;
        ++sz[x];
        sum[x] += j + 1;
        p[j] = x;
        findSet(i);
        findSet(j);
    }
    int getSize(int i){
        return sz[findSet(i)];
    }
    int getSum(int i){
        return sum[findSet(i)];
    }
};
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    while (cin >> n >> m) {
        UnionFind ufds(n);
        while (m--) {
            int cmd, p;
            cin >> cmd >> p;
            --p;
            if (cmd == 1) {
                int q;
                cin >> q;
                --q;
                ufds.unionSet(p, q);
            }else if (cmd == 2) {
                int q;
                cin >> q;
                --q;
                ufds.moveSet(q, p);
            }else {
                cout << ufds.getSize(p) << ' ' << ufds.getSum(p) << '\n';
            }
        }
    }
    cout.flush();
    return 0;
}
