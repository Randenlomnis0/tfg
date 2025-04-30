#include <bits/stdc++.h>
using namespace std;
#define GL(x) getline(cin, x)
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define LEN(x) ((int)x.length())
bool probar(const string& s1, const string& s2) {
    for (int i = 0; i < s2.length(); ++i) {
        if (s2[i] != s1[i%s1.length()]) return false;
    }
    return true;
}
int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    string line; GL(line);
    while (n--) {
        GL(line);
        FOR(i, 1, LEN(line) + 1) {
            if (probar(line.substr(0, i), line)) {
                cout << i << '\n';
                break;
            }
        }
    }
    cout.flush();
    return 0;
}
