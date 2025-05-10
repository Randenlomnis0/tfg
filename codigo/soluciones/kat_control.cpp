#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
class UnionFind {
private:
    vi p, sz;
public:
    UnionFind(int N) : p(N, -1), sz(N, 1) {}
    int findSet(int i) { return (p[i] < 0) ? i : (p[i] = findSet(p[i])); }
    int getSize(int i) { return sz[findSet(i)]; }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return;
        int x = findSet(i), y = findSet(j);
        if (p[x] < p[y]) swap(x, y);
        sz[y] += sz[x];
        p[x] = y;
        if (p[x] == p[y]) --p[y];
    }
};
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    UnionFind ufds(500001);
    int ans = 0;
    while (N--) {
        int M, aux = 0;
        cin >> M;
        vector<int> ingredients(M);
        unordered_set<int> setIds;
        for (auto &it : ingredients) {
            cin >> it;
            if (setIds.count(ufds.findSet(it)) == 0) {
                aux += ufds.getSize(it);
                setIds.insert(ufds.findSet(it));
            }
        }
        if (aux > M) continue;
        ++ans;
        for (auto &it : ingredients) {
            ufds.unionSet(it, ingredients[0]);
        }
    }
    cout << ans << '\n';
    cout.flush();
    return 0;
}
