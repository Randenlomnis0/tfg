#include <bits/stdc++.h>
using namespace std;
#define GL(s) getline(cin, s)
#define FOR(i,j,k) for (int i = j; i < k; ++i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    string s;
    GL(s);
    while (N--) {
        GL(s);
        vector<int> ft('z' - 'a' + 1);
        for (auto &it : s) {
            if (it >= 'A' && it <= 'Z') {
                it += ' ';
            }
            if (it < 'a' || it > 'z') continue;
            ++ft[it - 'a'];
        }
        string missing = "";
        FOR(i, 0, 'z' - 'a' + 1) {
            if (ft[i]) continue;
            missing += 'a' + i;
        }
        if (missing == "") {
            cout << "pangram\n";
        }else {
            cout << "missing " << missing << '\n';
        }
    }
    cout.flush();
    return 0;
}
