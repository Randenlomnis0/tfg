#include <bits/stdc++.h>
using namespace std;
#define REV(x) reverse(x.begin(), x.end())
#define GL(x) getline(cin, x)
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define PB(x) push_back(x)
#define LEN(x) ((int)x.length())
int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    string s, token, line; cin >> s;
    int e; cin >> e;
    vector<string> tokens;
    vector<vector<string>> rimas;
    REV(s);
    GL(line);
    FOR(i, 0, e) {
        GL(line);
        tokens.clear();
        token = "";
        for (auto &it : line) {
            if (it == ' ') {
                REV(token);
                tokens.PB(token);
                token = "";
            }else {
                token += it;
            }
        }
        REV(token);
        tokens.PB(token);
        bool valido = false;
        for (auto &it : tokens) {
            if (LEN(it) > LEN(s)) continue;
            bool bueno = true;
            FOR(j, 0, LEN(it)) {
                if (!bueno) break;
                if (it[j] != s[j]) bueno = false;
            }
            if (bueno) valido = true;
        }
        if (valido) rimas.PB(tokens);
    }
    int p; cin >> p;
    GL(line);
    FOR(i, 0, p) {
        GL(line);
        REV(line);
        bool encontrado = false;
        for (auto &it : rimas) {
            for (auto &iit : it) {
                if (LEN(iit) > LEN(line)) continue;
                bool bueno = true;
                FOR(j, 0, LEN(iit)) {
                    if (!bueno) break;
                    if (iit[j] != line[j]) bueno = false;
                }
                if (bueno) {   
                    encontrado = true;
                    break;
                }
            }
            if (encontrado) break;
        }
        if (encontrado) cout << "YES\n";
        else cout << "NO\n";
    }
    cout.flush();
    return 0;
}
