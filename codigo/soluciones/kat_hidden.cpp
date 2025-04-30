#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define LEN(x) ((int)x.length())
int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    string pword, msg; cin >> pword >> msg;
    int j = 0;
    bool pass = true, found;
    FOR(i, 0, LEN(pword)) {
        if (!pass) break;
        found = false;
        while (j < LEN(msg) && pword[i] != msg[j]) {
            FOR(k, i + 1, LEN(pword)) {
                if (pword[k] == msg[j]) {
                    pass = false;
                }
            }
            ++j;
        }
        if (j < LEN(msg)) {
            found = true;
            ++j;
        }
        if (!found) pass = false;
    }
    cout << (pass ? "PASS" : "FAIL") << "\n";
    cout.flush();
    return 0;
}
