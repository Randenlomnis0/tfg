#include <bits/stdc++.h>
using namespace std;
#define ALL(c) (c).begin(), (c).end()
#define LEN(s) ((int)(s).length())
int m(const string &s, const int& i) {
    return 4 * (s[i] == '1') + 2 * (s[i + 1] == '1') + (s[i + 2] == '1');
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    string b2;
    cin >> b2;
    reverse(ALL(b2));
    while (LEN(b2)%3) {
        b2 += '0';
    }
    reverse(ALL(b2));
    for (int i = 0; i < LEN(b2); i += 3) {
        cout << m(b2, i);
    }
    cout << '\n';
    cout.flush();
    return 0;
}
