#include <bits/stdc++.h>
using namespace std;
#define LEN(s) ((int)(s).length())
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    string s;
    while (N--) {
        cin >> s;
        if (s == "P=NP") {
            cout << "skipped\n";
        }else {
            int i = s.find('+');
            cout << stoi(s.substr(0, i)) + stoi(s.substr(i + 1, LEN(s) - (i  + 1))) << '\n';
        }
    }
    cout.flush();
    return 0;
}
