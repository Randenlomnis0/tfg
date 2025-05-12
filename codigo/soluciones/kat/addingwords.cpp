#include <bits/stdc++.h>
using namespace std;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    string cmd;
    unordered_map<string, int> mem;
    unordered_map<int, string> valName;
    while (cin >> cmd) {
        if (cmd == "def") {
            string x;
            int y;
            cin >> x >> y;
            mem[x] = y;
            valName[y] = x;
        }else if (cmd == "calc") {
            string token;
            bool unknown = false;
            int ans = 0;
            int op = 1;
            bool first = true;
            while (cin >> token, token != "=") {
                if (token == "+") {
                    op = 1;
                }else if (token == "-") {
                    op = -1;
                }else {
                    if (mem.count(token) == 0) {
                        unknown = true;
                    }else {
                        ans += op * mem[token];
                    }
                }
                if (!first) cout << ' ';
                else first = false;
                cout << token;
            }
            if (valName.count(ans) == 0 || mem[valName[ans]] != ans) {
                unknown = true;
            }
            if (unknown) {
                cout << " = unknown\n";
            }else {
                cout << " = " << valName[ans] << '\n';
            }
        }else {
            mem.clear();
            valName.clear();
        }
    }
    cout.flush();
    return 0;
}
