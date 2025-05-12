#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define SZ(c) ((int)(c).size())
#define pb(x) push_back(x)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<bool> s;
    unordered_map<char, bool> tvals;
    FOR(i, 0, n) {
        char tval;
        cin >> tval;
        tvals['A' + i] = (tval == 'T' ? true : false);
    }
    char aux;
    while (cin >> aux) {
        if (aux == '+') {
            bool a = s[SZ(s) - 1];
            s.pop_back();
            bool b = s[SZ(s) - 1];
            s.pop_back();
            s.pb(a || b);
        }else if (aux == '*') {
            bool a = s[SZ(s) - 1];
            s.pop_back();
            bool b = s[SZ(s) - 1];
            s.pop_back();
            s.pb(a && b);
        }else if (aux == '-') {
            bool a = s[SZ(s) - 1];
            s.pop_back();
            s.pb(!a);
        }else {
            s.pb(tvals[aux]);
        }
    }
    cout << (s[0] ? 'T' : 'F') << '\n';
    cout.flush();
    return 0;
}
