#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define LEN(s) ((int)(s).length())
#define RFOR(i,j,k) for (int i = j - 1; i >= k; --i)
int ctz(const string &s) {
    int ans = 0;
    RFOR(i, LEN(s), 0) {
        if (s[i] != '0') break;
        ++ans;
    }
    return ans;
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    string N, M;
    cin >> N >> M;
    if (LEN(M) > LEN(N)) {
        cout << '0';
    }
    FOR(i, 0, max(0, LEN(N) - LEN(M) + 1)) {
        cout << N[i];
    }
    int aux = ctz(N);
    int s = max(0, LEN(N) - LEN(M) + 1), e = LEN(N) - aux;
    string trail = N.substr(s, max(0, e - s));
    if (trail != "") {
        cout << '.';
    }
    FOR(i, 0, LEN(M) - LEN(N) - 1) {
        cout << '0';
    }
    cout << trail << '\n';
    cout.flush();
    return 0;
}
