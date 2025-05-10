#include <bits/stdc++.h>
using namespace std;
#define SZ(c) ((int)(c).size())
#define ALL(c) (c).begin(), (c).end()
vector<vector<int>> memo(101, vector<int>(1001, -1));
int ks(const vector<int>& C, const int& i, int c) {
    int& ans = memo[i][c];
    if (c < 0) return ans = 0;
    if (i == SZ(C)) {
        return ans = (c == 0);
    }
    if (ans != -1) return ans;
    ans = 0;
    while (c >= 0) {
        ans += ks(C, i + 1, c);
        c -= C[i];
    }
    return ans;
}

signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> C(n);
    for (auto &it : C) {
        cin >> it;
    }
    sort(ALL(C));
    int m;
    cin >> m;
    while (m--) {
        int c;
        cin >> c;
        int ans = ks(C, 0, c);
        if (ans > 1) {
            cout << "Ambiguous\n";
        }else if (ans == 0) {
            cout << "Impossible\n";
        }else {
            
        }
    }
    cout.flush();
    return 0;
}
