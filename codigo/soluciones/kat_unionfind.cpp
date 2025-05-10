#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
class UnionFind {
private:
    vi p;
public:
    UnionFind(int N) : p(N, -1) {}
    int findSet(int i) { return (p[i] < 0) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return;
        int x = findSet(i), y = findSet(j);
        if (p[x] < p[y]) swap(x, y);
        p[x] = y;
        if (p[x] == p[y]) --p[y];
    }
};
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    UnionFind ufds(N);
    while (Q--) {
        char cmd;
        int a, b;
        cin >> cmd >> a >> b;
        if (cmd == '=') {
            ufds.unionSet(a, b);
        }else {
            cout << (ufds.isSameSet(a, b) ? "yes" : "no") << '\n';
        }
    }
    cout.flush();
    return 0;
}
