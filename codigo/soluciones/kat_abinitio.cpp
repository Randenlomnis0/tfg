#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define ll long long
const ll MOD = 1000000007;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int V, E, Q;
    cin >> V >> E >> Q;
    vector<vector<bool>> AM(V, vector<bool>(V));
    while (E--) {
        int A, B;
        cin >> A >> B;
        AM[A][B] = true;
    }
    bool transpose = false, complement = false;
    while (Q--) {
        int q;
        cin >> q;
        if (q == 1) {
            ++V;
            for (auto &it : AM) {
                it.pb(false);
            }
            AM.pb(vector<bool>(V));
        }else if (q == 2) {
            int X, Y;
            cin >> X >> Y;
            if (transpose) swap(X, Y);
            AM[X][Y] = !complement;
        }else if (q == 3) {
            int X;
            cin >> X;
            FOR(i, 0, V) {
                AM[i][X] = !complement;
                AM[X][i] = !complement;
            }
        }else if (q == 4) {
            int X, Y;
            cin >> X >> Y;
            if (transpose) swap(X, Y);
            AM[X][Y] = !complement;
        }else if (q == 5) {
            transpose = !transpose;
        }else {
            complement = !complement;
        }
    }
    cout << V << '\n';
    if (transpose) {
        FOR(i, 0, V) {
            FOR(j, 0, V) {
                swap(AM[i][j], AM[j][i]);
            }
        }
    }
    for (auto &it : AM) {
        ll ans1 = 0, ans2 = 0, base = 1;
        FOR(i, 0, V) {
            if (it[i] == complement) continue;
            ++ans1;
            ans2 += base * i;
            ans2 %= MOD;
            base *= 7;
            base %= MOD;
        }
        cout << ans1 << ' ' << ans2 << '\n';
    }
    cout.flush();
    return 0;
}
