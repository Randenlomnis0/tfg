#include <bits/stdc++.h>
using namespace std;
#define LEN(s) ((int)(s).length())
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b;
    cin >> a >> b;
    int i = 0, j = 0;
    for (; i < LEN(a) && i < LEN(b) && a[i] == b[i]; ++i);
    for (; j < LEN(a) && j < LEN(b) && a[LEN(a) - j - 1] == b[LEN(b) - j - 1]; ++j);
    cout << max(0, LEN(b) - j - i) << '\n';
    cout.flush();
    return 0;
}
