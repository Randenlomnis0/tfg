#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define ALL(c) (c).begin(),(c).end()
#define RALL(c) (c).rbegin(),(c).rend()
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<string> v(N), a(N), b(N);
    FOR(i, 0, N) {
        cin >> v[i];
        a[i] = b[i] = v[i];
    }
    sort(ALL(a));
    sort(RALL(b));
    bool esA = true, esB = true;
    FOR(i, 0, N) {
        if (v[i] != a[i]) {
            esA = false;
        }
        if (v[i] != b[i]) {
            esB = false;
        }
    }
    if (esA) {
        cout << "INCREASING\n";
    }else if (esB) {
        cout << "DECREASING\n";
    }else {
        cout << "NEITHER\n";
    }
    cout.flush();
    return 0;
}
