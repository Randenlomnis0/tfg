#include <bits/stdc++.h>
using namespace std;
#define ALL(c) (c).begin(),(c).end()
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b;
    cin >> a >> b;
    reverse(ALL(a));
    reverse(ALL(b));
    if (stoi(a) > stoi(b)) {
        cout << a << '\n';
    }else {
        cout << b << '\n';
    }
    cout.flush();
    return 0;
}
