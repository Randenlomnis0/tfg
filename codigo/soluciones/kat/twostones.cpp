#include <bits/stdc++.h>
using namespace std;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    cout << (N%2 ? "Alice" : "Bob") << '\n';
    cout.flush();
    return 0;
}
