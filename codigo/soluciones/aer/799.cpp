#include <bits/stdc++.h>
using namespace std;
#define LEN(s) ((int)(s).length())
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        string token;
        unordered_map<string, string> dict;
        unordered_map<string, int> cnt;
        while (cin >> token, token != ".") {
            string aux = token;
            if (LEN(token) > 2) {
                sort(token.begin() + 1, token.end() - 1);
            }
            dict[token] = aux;
            ++cnt[token];
        }
        bool first = true;
        while (cin >> token, token != ".") {
            string aux = token;
            if (LEN(token) > 2) {
                sort(token.begin() + 1, token.end() - 1);
            }
            if (!first) cout << ' ';
            else first = false;
            if (cnt[token] == 0) {
                cout << aux;
            }else if (cnt[token] == 1) {
                cout << dict[token];
            }else {
                cout << aux;
            }
        }
        cout << " .\n";
    }
    cout.flush();
    return 0;
}
