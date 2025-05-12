#include <bits/stdc++.h>
using namespace std;
#define GL(x) getline(cin, x)
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define LEN(x) ((int)x.length())
#define PB(x) push_back(x)
#define SZ(x) ((int)x.size())
#define POPB() pop_back()
bool isIntConst(const string& s) {
    return !(s == "+" || s == "-" || s == "*" || (LEN(s) == 1 && s[0] >= 'a' && s[0] <= 'z'));
}
void solve(const int& i, const vector<string>& tokens) {
    vector<string> pila;
    bool first = true;
    cout << "Case " << i << ": ";
    for (auto &it : tokens) {
        pila.PB(it);
        while (SZ(pila) > 2 && isIntConst(pila[SZ(pila) - 1]) && isIntConst(pila[SZ(pila) - 2])) {
            if (pila[SZ(pila) - 3] == "+") {
                pila[SZ(pila) - 3] = to_string(stoi(pila[SZ(pila) - 2]) + stoi(pila[SZ(pila) - 1]));
                pila.POPB();
                pila.POPB();
            }else if (pila[SZ(pila) - 3] == "-") {
                pila[SZ(pila) - 3] = to_string(stoi(pila[SZ(pila) - 2]) - stoi(pila[SZ(pila) - 1]));
                pila.POPB();
                pila.POPB();
            }else if (pila[SZ(pila) - 3] == "*") {
                pila[SZ(pila) - 3] = to_string(stoi(pila[SZ(pila) - 1]) * stoi(pila[SZ(pila) - 2]));
                pila.POPB();
                pila.POPB();
            }else {
                break;
            }
        }
    }
    for (auto &it : pila) {
        if (first) first = false;
        else cout << ' ';
        cout << it;
    }
    cout << '\n';
}
int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    string line, token;
    vector<string> tokens;
    int caso = 1;
    while (GL(line)) {
        token = "";
        tokens.clear();
        FOR(i, 0, LEN(line)) {
            if (!i) while (line[i] == ' ') ++i;
            if (line[i] != ' ') {
                token += line[i];
            }else {
                tokens.PB(token);
                token = "";
            }
        }
        if (token != "") tokens.PB(token);
        solve(caso++, tokens);
    }
    cout.flush();
    return 0;
}
