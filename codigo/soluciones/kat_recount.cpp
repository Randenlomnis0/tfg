#include <bits/stdc++.h>
using namespace std;
#define GL(s) getline(cin, s)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    string line, ans;
    unordered_map<string, int> ft;
    int aux = 0;
    while (GL(line), line != "***") {
        ++ft[line];
        if (ans == "" || ft[line] > ft[ans] || line == ans) {
            ans = line;
            aux = 1;
        }else if (line != ans && ft[line] == ft[ans]) {
            ++aux;
        }
    }
    if (aux > 1) {
        cout << "Runoff!\n";
    }else {
        cout << ans << '\n';
    }
    cout.flush();
    return 0;
}
