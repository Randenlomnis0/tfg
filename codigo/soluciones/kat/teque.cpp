#include <bits/stdc++.h>
using namespace std;
#define SZ(c) ((int)(c).size())
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    deque<int> l, r;
    while (N--) {
        string cmd;
        cin >> cmd;
        if (cmd == "get") {
            int i;
            cin >> i;
            if (i < SZ(l)) {
                cout << l[i] << '\n';
            }else {
                cout << r[i - SZ(l)] << '\n';
            }
            continue;
        }
        int x;
        cin >> x;
        if (cmd == "push_front") {
            l.push_front(x);
        }else if (cmd == "push_back") {
            r.push_back(x);
        }else {
            if ((SZ(l) + SZ(r))%2) {
                r.push_front(x);
            }else {
                l.push_back(x);
            }
        }
        if (SZ(l) < SZ(r)) {
            l.push_back(r.front());
            r.pop_front();
        }else if (SZ(l) > SZ(r) + 1) {
            r.push_front(l.back());
            l.pop_back();
        }
    }
    cout.flush();
    return 0;
}
