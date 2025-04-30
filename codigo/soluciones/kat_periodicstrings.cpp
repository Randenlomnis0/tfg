#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define LEN(x) ((int)x.length())
int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    FOR(i, 1, LEN(s) + 1) {
        if (LEN(s)%i) continue;
        bool valido = true;
        FOR(j, 1, LEN(s) / i) {
            FOR(k, 0, i) {
                if (s[k] != s[j * i + (k + j)%i]) valido = false;
            }
        }
        if (valido) {
            cout << i << '\n';
            break;
        }
    }
    cout.flush();
    return 0;
}
