#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define ALL(c) (c).begin(),(c).end()
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> v(3);
    FOR(i, 0, 3) {
        cin >> v[i];
    }
    sort(ALL(v));
    if (v[0] - v[1] == v[1] - v[2]) {
        cout << v[2] + v[2] - v[1] << '\n';
    }else if (abs(v[0] - v[1]) > abs(v[1] - v[2])) {
        cout << v[0] + v[2] - v[1] << '\n';
    }else {
        cout << v[1] + v[1] - v[0] << '\n';
    }
    cout.flush();
    return 0;
}
