#include <bits/stdc++.h>
using namespace std;
#define LEN(s) ((int)(s).length())
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    double a, b, c, d;
    a = b = c = d = 0.0;
    for (auto &it : s) {
        if (it == '_') {
            ++a;
        }else if (it >= 'a' && it <= 'z') {
            ++b;
        }else if (it >= 'A' && it <= 'Z') {
            ++c;
        }else {
            ++d;
        }
    }
    cout << fixed << setprecision(6) << a / LEN(s) << '\n';
    cout << fixed << setprecision(6) << b / LEN(s) << '\n';
    cout << fixed << setprecision(6) << c / LEN(s) << '\n';
    cout << fixed << setprecision(6) << d / LEN(s) << '\n';
    cout.flush();
    return 0;
}
