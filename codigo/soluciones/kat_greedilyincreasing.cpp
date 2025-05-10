#include <bits/stdc++.h>
using namespace std;
#define PB(x) push_back(x)
#define SZ(c) ((int)(c).size())
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N, prev = 0;
    cin >> N;
    vector<int> ans;
    while (N--) {
        int aux;
        cin >> aux;
        if (aux > prev) {
            ans.PB(aux);
            prev = aux;
        }
    }
    cout << SZ(ans) << '\n';
    bool first = true;
    for (auto &it : ans) {
        if (!first) cout << ' ';
        else first = false;
        cout << it;
    }
    cout << '\n';
    cout.flush();
    return 0;
}
