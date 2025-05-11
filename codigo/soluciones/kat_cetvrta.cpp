#include <bits/stdc++.h>
using namespace std;

signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    unordered_set<int> l, r;
    int aux = 3;
    while (aux--) {
        int a, b;
        cin >> a >> b;
        if (l.count(a)) {
            l.erase(a);
        }else {
            l.insert(a);
        }
        if (r.count(b)) {
            r.erase(b);
        }else {
            r.insert(b);
        }
    }
    cout << *l.begin() << ' ' << *r.begin() << '\n';
    cout.flush();
    return 0;
}
