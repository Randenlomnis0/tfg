#include <bits/stdc++.h>
using namespace std;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    string month;
    int day;
    cin >> month >> day;
    cout << ((month == "OCT" && day == 31) || (month == "DEC" && day == 25) ? "yup" : "nope") << '\n';
    cout.flush();
    return 0;
}
