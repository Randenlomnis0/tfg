#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define SZ(c) ((int)(c).size())
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    int aux = 0;
    vector<int> mem;
    mem.pb(aux);
    while (k--) {
        string cmd;
        cin >> cmd;
        if (cmd == "undo") {
            int m;
            cin >> m;
            while (m--) {
                mem.pop_back();
            }
            aux = mem[SZ(mem) - 1];
        }else {
            int p = stoi(cmd);
            aux += p;
            while (aux < 0) {
                aux += n;
            }
            aux %= n;
            mem.pb(aux);
        }
    }
    cout << aux << '\n';
    cout.flush();
    return 0;
}
