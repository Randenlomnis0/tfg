#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
class UnionFind {
private:
    vi p, sz, used;
public:
    UnionFind(int N) : p(N, -1), sz(N, 1), used(N, 0) {}
    int findSet(int i) { return (p[i] < 0) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return;
        int x = findSet(i), y = findSet(j);
        if (p[x] < p[y]) swap(x, y);
        sz[y] += sz[x];
        used[y] += used[x];
        p[x] = y;
        if (p[x] == p[y]) --p[y];
    }
    bool use(int i) {
        int x = findSet(i);
        if (used[x] + 1 > sz[x]) return false;
        ++used[x];
        return true;
    }
};
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N, L;
    cin >> N >> L;
    UnionFind ufds(L);
    while (N--) {
        int A, B;
        cin >> A >> B;
        --A;
        --B;
        ufds.unionSet(A, B);
        if (ufds.use(A)) {
            cout << "LADICA\n";
        }else {
            cout << "SMECE\n";
        }
    }
    cout.flush();
    return 0;
}
