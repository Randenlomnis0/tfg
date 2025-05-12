#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    string s, ans = "";
    cin >> s;
    ans += s[0];
    for (int i = 1; i < s.length(); ++i) {
        if (s[i] != s[i - 1]) {
            ans += s[i];
        }
    }
    cout << ans << '\n';
    cout.flush();
    return 0;
}
