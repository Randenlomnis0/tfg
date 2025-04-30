#include <bits/stdc++.h>
using namespace std;
#define GL(x) getline(cin, x)
#define LEN(x) ((int)x.length())
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define RFOR(i,j,k) for (int i = j - 1; i >= k; --i)
#define MAX(a,b) a = max(a, b)
#define REV(x) reverse(x.begin(), x.end())
int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    bool first = true;
    while (cin >> n, n) {
        if (!first) cout << '\n';
        else first = false;
        vector<string> art(n);
        int longestlong = 0;
        string line; GL(line);
        FOR(i, 0, n) {
            GL(art[i]);
            MAX(longestlong, LEN(art[i]));
        }
        FOR(i, 0, longestlong) {
            line = "";
            for (int j = 0; j < n; ++j) {
                if (i >= LEN(art[j])) line += " ";
                else {
                    if (art[j][i] == ' ' || art[j][i] == '+') {
                        line += art[j][i];
                    }else if (art[j][i] == '-') {
                        line += '|';
                    }else {
                        line += '-';
                    }
                }
            }
            REV(line);
            RFOR(j, LEN(line), 0) {
                if (line[j] == ' ') continue;
                line = line.substr(0, j + 1);
                break;
            }
            cout << line << '\n';
        }
    }
    cout.flush();
    return 0;
}
